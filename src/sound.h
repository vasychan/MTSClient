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
        Glib::RefPtr<Glib::MainLoop> m_loop;
        Glib::RefPtr<Gst::Pipeline> m_pipeline;
        Glib::RefPtr<Gst::Element> m_source, m_sink, m_decoder,  m_demuxer, m_conv;
        Glib::RefPtr<Gst::Bus> m_bus;
};

Sound::Sound()
{
    Gst::init();
    m_loop = Glib::MainLoop::create();
    m_pipeline = Gst::Pipeline::create("audio-player");
    // m_source = Gst::FileSrc::create();
    // m_demuxer = Gst::OggDemux::create();
    // m_decoder = Gst::VorbisDec::create();
    // m_conv = Gst::AudioConvert::create();
    // m_sink = Gst::AlsaSink::create();
    // if (!m_pipeline || !m_source ||  !m_decoder || !m_demuxer || m_conv || m_sink)
    // {
    //     std::cerr << "One element could not be created" << "\n";
    // }
    // else
    // {
    //     m_pipeline->add(m_source);
    //     m_pipeline->add(m_demuxer);
    //     m_pipeline->add(m_decoder);
    //     m_pipeline->add(m_conv);
    //     m_pipeline->add(m_sink);
    //     m_source->link(m_demuxer);
    //     m_demuxer->link(m_decoder);
    //     m_decoder->link(m_conv);
    //     m_conv->link(m_sink);
    // }
    m_loop->run();
    
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
