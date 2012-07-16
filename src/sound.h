/*
 * =====================================================================================
 *
 *       Filename:  sound.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12.07.2012 16:16:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  vasy (vasy.chan@gmail.com), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef SOUND_H
#define SOUND_H

#include "configure.h"

class Sound
{
    public:
        Sound();

        void start_playing();
        bool stop_playing();

    private:
        Glib::RefPtr<Gst::Pipeline> m_pipeline;
        Glib::RefPtr<Gst::Element> m_source, m_sink, m_decoder,  m_demuxer, m_conv;
};

Sound::Sound()
{
    m_pipeline = Gst::Pipeline::create("audio-player");
    m_source = Gst::ElementFactory::create_element("filesrc", "file-source");
    m_demuxer = Gst::ElementFactory::create_element("oggdemux","ogg-demuxer");
    m_decoder = Gst::ElementFactory::create_element("vorbisdec","vorbis-decoder");
    m_conv = Gst::ElementFactory::create_element("audioconvert","converter");
    m_sink = Gst::ElementFactory::create_element("autoaudiosink","audio-output");
    m_pipeline->add(m_source);
    m_pipeline->add(m_demuxer);
    m_pipeline->add(m_decoder);
    m_pipeline->add(m_conv);
    m_pipeline->add(m_sink);
    m_source->link(m_sink);
}

void Sound::start_playing ()
{
    // m_source->set_property("freq", frequency);
    // m_pipeline->set_state(Gst::STATE_PLAYING);

    // /* stop it after 200ms */
    // Glib::signal_timeout().connect(sigc::mem_fun(*this, &Sound::stop_playing),
    //                                200);
}

bool Sound::stop_playing()
{
    m_pipeline->set_state(Gst::STATE_NULL);
    return false;
}

#endif
