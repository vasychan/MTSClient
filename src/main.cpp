/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04.07.2012 09:08:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  vasy (vasy.chan@gmail.com), 
 *        Company:  
 *
 * =====================================================================================
 */

//#include "configure.h"
#include "window.h"
#include "http_client.h"


//#include <boost/thread.hpp>  
//#include <boost/date_time.hpp> 

boost::mutex io_mutex;
void workerPlaylist(window::MainWindow *mainWindow)
{
    sleep(5);
    while(true)
    {

        boost::posix_time::seconds workTime(5); 
        //mainWindow->RefreshPlayList();

        boost::this_thread::sleep(workTime); 
        std::cout << "Worker: finished" << std::endl; 
    }



}


int main(int argc, char *argv[])
{
    if(!Glib::thread_supported()) Glib::thread_init();

    Gtk::Main app(argc, argv);
    // move in config
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("../interface/main.glade");
    //Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("interface/main.glade");
    window::MainWindow *mainWindow = 0;
    builder->get_widget_derived("mtc_client", mainWindow);


   
    // write playlist. move it to thread
    {
        boost::mutex::scoped_lock lock(io_mutex);
        //run play list http client
        boost::asio::io_service io_service;
        client c(io_service, "mts.local", "/playlist");
        io_service.run();

        std::string t = c.getResponse();
        //std::cout << t.c_str();
        std::istringstream is(t);
        PlaylistList playlist = read( is);
        //std::cout << t.c_str();
        mainWindow->InitPlayList(playlist);
    }
    //boost::thread workerThread(workerPlaylist, mainWindow);
    // end

    
    app.run(*mainWindow);
    delete mainWindow;
    //workerThread.join();
    return 0;
}


