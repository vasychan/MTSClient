/*
 * =====================================================================================
 *
 *       Filename:  playlist.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05.07.2012 12:20:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "configure.h"

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include <algorithm>
typedef boost::gregorian::date Date;
 
struct Playlist 
{
        std::string  song_name;
        std::string  song_url;
};
     
typedef std::vector<Playlist> PlaylistList;

using boost::property_tree::ptree;
using namespace boost;

class Parser
{
    public:
        Parser() {}
        ~Parser() {}


        PlaylistList Read( std::istream & is )
        {
              //using namespace std;
              // populate tree structure pt
              read_xml(is, pt);
              // traverse pt
              BOOST_FOREACH(const ptree::value_type &v, pt.get_child("playlist.tracklist")) 
              {
                  if(v.first == "track") 
                  {
                      Playlist f;
                      f.song_name = v.second.get<std::string>("title");
                      f.song_url = v.second.get<std::string>("location");
                      ans.push_back(f);
                  }
              }
           
              return ans;
        }

    private:
        ptree pt;
        PlaylistList ans;
};

PlaylistList read( std::istream & is )
{
  using namespace boost;
  //using namespace std;
  // populate tree structure pt
  using boost::property_tree::ptree;
  ptree pt;
  read_xml(is, pt);

  // traverse pt
  PlaylistList ans;
  BOOST_FOREACH(const ptree::value_type &v, pt.get_child("playlist.tracklist")) 
  {
      if(v.first == "track") 
      {
          Playlist f;
          f.song_name = v.second.get<std::string>("title");
          f.song_url = v.second.get<std::string>("location");
          ans.push_back(f);
      }
  }

  return ans;
}




#endif
