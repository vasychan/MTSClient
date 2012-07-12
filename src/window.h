/*
 * =====================================================================================
 *
 *       Filename:  window.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05.07.2012 12:09:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef WINDOW_H
#define WINDOW_H

#include "configure.h"
#include "playlist.h"
#include "search_song.h"
#include "http_client.h"


namespace window
{
    Glib::StaticMutex mutex = GLIBMM_STATIC_MUTEX_INIT; 

    class Worker {
      public:
     
        Worker() : thread(0), stop(false) {}
     
        // Called to start the processing on the thread
        void start () {
          thread = Glib::Thread::create(sigc::mem_fun(*this, &Worker::run), true);
        }
     
        // When shutting down, we need to stop the thread
        ~Worker() {
          {
            Glib::Mutex::Lock lock (mutex);
            stop = true;
          }
          if (thread)
            thread->join(); // Here we block to truly wait for the thread to complete
        }
     
        Glib::Dispatcher sig_done;
     
      protected:
        // This is where the real work happens
        void run () {
     
          while(true) {
            {
              Glib::Mutex::Lock lock (mutex);
              if (stop) break;
            }
            sleep(5);
            std::cout << "Thread write!" << std::endl;
            sig_done();
            break;
          }
        }
     
        Glib::Thread * thread;
        Glib::Mutex mutex;
        bool stop;
    };

    class MainWindow: public Gtk::Window 
    {
        public:
            class PlaylistModel : public Gtk::TreeModel::ColumnRecord
            {
                public:
                    PlaylistModel()
                    { 
                        //add(m_col_id); 
                        add(m_col_name); 
                    }

                    Gtk::TreeModelColumn<unsigned int> m_col_id;
                    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
            };

            class SearchListModel : public Gtk::TreeModel::ColumnRecord
            {
                public:
                    SearchListModel()
                    { 
                        add(m_artist); 
                        add(m_title); 
                        add(m_url); 
                    }

                    Gtk::TreeModelColumn<unsigned int> m_col_id;
                    Gtk::TreeModelColumn<Glib::ustring> m_artist;
                    Gtk::TreeModelColumn<Glib::ustring> m_title;
                    Gtk::TreeModelColumn<Glib::ustring> m_url;
            };



        public:
            MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
                : Gtk::Window(cobject)
                , _builder(builder)
            {
                // ====  playlist start ==== 
                _builder->get_widget("treeview2", _playlist);
                m_refTreeModel = Gtk::ListStore::create(_playlistColumns);
                _playlist->set_model(m_refTreeModel);
                // ====  playlist end ==== 

                _builder->get_widget("treeview1", _song_list); // song list
                _song_list->append_column("songtitle", _searchlistColumns.m_title);
                _song_list->append_column("artist", _searchlistColumns.m_artist);
                _builder->get_widget("entry1", m_findEntry);
                //connect signal
                m_findEntry->signal_key_release_event().connect(
                    sigc::mem_fun(*this, &MainWindow::entryKeyRelease));

                // connect button5 (add song to playlist)
                _builder->get_widget("button5", _add_song_button);
                _add_song_button->signal_clicked().connect(
                    sigc::mem_fun(*this, &MainWindow::AddSongClicked));

                // connect button3 (refresh playlist)
                //_builder->get_widget("button3", _refresh_playlist_button);
                //_refresh_playlist_button->signal_clicked().connect(
                //    sigc::mem_fun(*this, &MainWindow::RefreshPlayList));

                 // connect button1 (search)
                _builder->get_widget("button1", _search_button);
                _search_button->signal_clicked().connect(
                    sigc::mem_fun(*this, &MainWindow::initSearchTreeView));

                // === search playlist == 
                m_searchTreeModel = Gtk::ListStore::create(_searchlistColumns);
                _song_list->set_model(m_searchTreeModel);

                m_dispatcher.connect( sigc::mem_fun( m_pbar , &Gtk::ProgressBar::pulse )); 

            }

            ~MainWindow() 
            {
              {
                Glib::Mutex::Lock lock(mutex);                    
                if(m_end_thread)       // Wenn der Thread noch läuft
                   m_end_thread = true; // sagen wir dem Thread das er beenden soll
              }
              if(_refresh_worker->joinable())
                _refresh_worker->join();      
            }

            void InitPlayList(PlaylistList playlist)
            {
                //m_refTreeModel->clear();
                Gtk::TreeModel::Row row = *(m_refTreeModel->append());
                
                
                std::vector<Playlist>::iterator it;
                for ( it=playlist.begin() ; it < playlist.end(); it++ )
                {
                    row[_playlistColumns.m_col_name] = (*it).song_name;
                    row = *(m_refTreeModel->append());
                }
                //row[_playlistColumns.m_col_id] = 1;

                //_playlist->append_column("ID", _playlistColumns.m_col_id);
                _playlist->append_column("Song", _playlistColumns.m_col_name);

                _refresh_worker = Glib::Thread::create( sigc::mem_fun(*this,&MainWindow::ThreadRefreshPlaylist),true); 
                // if (refresh != NULL)
                //     return;
                // refresh = new Worker();
                // refresh->sig_done.connect(sigc::mem_fun(*this, &MainWindow::RefreshPlayList));
                // refresh->start();
                // _song_list->set_sensitive(true);

            }

            void ThreadRefreshPlaylist()
            {
                while (true)
                {
                    m_dispatcher();

                    {
                        Glib::Mutex::Lock lock(mutex);
                        if(m_end_thread)
                            return;
                    }
                    Glib::usleep(900000);
                    boost::asio::io_service io_service;
                    client c(io_service, "mts.local", "/playlist");

                    //boost::posix_time::seconds workTime(2); 
                    io_service.run();
                    
                    std::string t = c.getResponse();
                    //std::cout << t << "\n";
                    std::istringstream is(t);
                    Parser *p = new Parser();
                    PlaylistList playlist = p->Read( is);
                    is.clear();
                    //std::cout << "iistringstream = " << is.str() << "\n";

                    Glib::RefPtr<Gtk::TreeModel>  playlist_model = _playlist->get_model();
                    
                    std::vector<Playlist>::iterator it;
                    int i = 0;
                    for ( it=playlist.begin() ; it < playlist.end(); it++ )
                    {
                        std::stringstream st;
                        st << i;
                        Gtk::TreeModel::iterator iter = playlist_model->get_iter(st.str());
                        if(iter)
                        {
                            Gtk::TreeModel::Row row = *iter;
                            //std::cout << (*it).song_name  << "\n"; 
                            if (row[_playlistColumns.m_col_name] != (*it).song_name)
                            {
                                //std::cout << row[_playlistColumns.m_col_name]  << " =======!= "<< (*it).song_name << "\n"; 
                                row[_playlistColumns.m_col_name] = (*it).song_name;
                            }

                        }
                        else
                        {
                            Gtk::TreeModel::Row insert_row = *(m_refTreeModel->append());
                            insert_row[_playlistColumns.m_col_name] = (*it).song_name;
                            insert_row = *(m_refTreeModel->append());
                        }

                        i++;
                     
                    }
                    c.clearResponse();
                }

            }


            void RefreshPlayList()
            {

                    //boost::posix_time::seconds workTime(2); 
                    boost::asio::io_service io_service;
                    client c(io_service, "mts.local", "/playlist");
                    io_service.run();

                    std::string t = c.getResponse();
                    std::istringstream is(t);
                    PlaylistList playlist = read( is);

                    Gtk::TreeModel::Row row = *(m_refTreeModel->append());
                    
                    
                    std::vector<Playlist>::iterator it;
                    for ( it=playlist.begin() ; it < playlist.end(); it++ )
                    {
                        row[_playlistColumns.m_col_name] = (*it).song_name;
                        row = *(m_refTreeModel->append());
                    }
                    //_playlist->append_column("Song", _playlistColumns.m_col_name);
                    //boost::this_thread::sleep(workTime); 
            }


            bool on_key_press_event(GdkEventKey* event)
            {
                std::cout << "on_key_press_event" << "\n";
                return Gtk::Window::on_key_press_event(event);

            }

            bool  entryKeyRelease(GdkEventKey* event)
            {
                //boost::mutex::scoped_lock lock(io_mutex);
                std::cout << event->keyval << "\n";

                // enter
                if (event->keyval == GDK_KEY_Return || event->keyval == GDK_KEY_ISO_Enter || event->keyval == GDK_KEY_KP_Enter)
                {
                    initSearchTreeView();

                }
                return true;

            }

            void initSearchTreeView()
            {
                boost::asio::io_service io_service;
                std::string query = "/search?track="+m_findEntry->get_text()+"&format=xml";
                client c(io_service, "mts.local", query);
                io_service.run();
                std::string response = c.getResponse();

                //boost::mutex::scoped_lock lock(io_mutex);
                m_searchTreeModel->clear();
                std::istringstream is(response);
                SearchListList playlist = read_search_list( is);


                Gtk::TreeModel::Row row = *(m_searchTreeModel->append());
                
                
                std::vector<SearchList>::iterator it;
                for ( it=playlist.begin() ; it < playlist.end(); it++ )
                {
                    row[_searchlistColumns.m_artist] = (*it).artist;
                    row[_searchlistColumns.m_title] = (*it).title;
                    row[_searchlistColumns.m_url] = (*it).url;
                    row = *(m_searchTreeModel->append());
                }
                //row[_playlistColumns.m_col_id] = 1;

                //_playlist->append_column("ID", _playlistColumns.m_col_id);
                //_song_list->append_column("songtitle", _searchlistColumns.m_title);

                
            }
           
            void AddSongClicked()
            {
                //boost::mutex::scoped_lock lock(io_mutex);
                boost::asio::io_service io_service;
                std::cout << "AddSongClicked" << "\n";

                Glib::RefPtr<Gtk::TreeSelection> song_tree = _song_list->get_selection();
                song_tree->set_mode(Gtk::SELECTION_SINGLE);

                Gtk::TreeModel::iterator iter = song_tree->get_selected();
                if(iter) //If anything is selected
                {
                    Gtk::TreeModel::Row row = *iter;
                    Glib::ustring title =  row[_searchlistColumns.m_title];
                    Glib::ustring link =  row[_searchlistColumns.m_url];
                    std::cout << title.c_str() << link.c_str() << "\n";

                    // send to server

                    std::string query = "/add?title="+title+"&link="+link;
                    std::cout << query.c_str() << "\n";
                    client c(io_service, "mts.local", query);
                    io_service.run();
                    std::string rres = c.getResponse();
                    std::cout << rres.c_str() << "/n";
                    //RefreshPlayList();
                }
            }

        private:
            Glib::RefPtr<Gtk::Builder> _builder;

            //playlist
            Gtk::TreeView *_playlist;
            Gtk::TreeView *_song_list;
            PlaylistModel _playlistColumns; 
            SearchListModel _searchlistColumns; 
            Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
            Glib::RefPtr<Gtk::ListStore> m_searchTreeModel;

            //find song
                // entry
                Gtk::Entry *m_findEntry;

            // add song to playlist
            Gtk::Button *_add_song_button, *_refresh_playlist_button, *_search_button;
            boost::mutex io_mutex;
            
            //thread
            Worker * refresh;
            Glib::Thread * _refresh_worker;
            bool             m_end_thread; 
            Glib::Dispatcher m_dispatcher; 

            Gtk::ProgressBar m_pbar; 

    };

}

#endif
