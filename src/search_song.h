/*
 * =====================================================================================
 *
 *       Filename:  search_song.h
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
#ifndef SEARCHLIST_H
#define SEARCHLIST_H

#include "configure.h"

#include <boost/property_tree/xml_parser.hpp>
//#include <boost/property_tree/json_parser.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include <algorithm>
typedef boost::gregorian::date Date;
 
struct SearchList
{
        int  aid;
        int  owner_id;
        std::string  artist;
        std::string  title;
        std::string  duration;
        std::string  url;
        //int  lyrics_id;
};
     
typedef std::vector<SearchList> SearchListList;

SearchListList read_search_list( std::istream & is )
{
      using namespace boost;
      //using namespace std;
      // populate tree structure pt
      using boost::property_tree::ptree;
      ptree pt;
      read_xml(is, pt);
   
      // traverse pt
      SearchListList ans;
      BOOST_FOREACH(const ptree::value_type &v, pt.get_child("response")) 
      {
          if(v.first == "audio") 
          {
              SearchList f;
              f.aid = v.second.get<int>("aid");
              f.owner_id = v.second.get<int>("owner_id");
              f.artist = v.second.get<std::string>("artist");
              f.title = v.second.get<std::string>("title");
              f.duration = v.second.get<std::string>("duration");
              f.url = v.second.get<std::string>("url");
              //f.lyrics_id = v.second.get<int>("lyrics_id");
              ans.push_back(f);
          }
      }   
      return ans;
}


#endif
