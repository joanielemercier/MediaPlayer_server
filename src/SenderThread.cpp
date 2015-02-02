#include "SenderThread.h"
#include <ofxOsc.h>

SenderThread::SenderThread(void) :
    frame_number_(0), frame_number_should_reset_(true)
{
}


SenderThread::~SenderThread(void)
{
}

void SenderThread::setup(std::string address, int port, int interval, int interval_timescale)
{
	address_ = address;
	port_ = port;
	interval_ = interval;
	interval_timescale_ = interval_timescale;
}

void SenderThread::threadedFunction()
{
	ofxOscSender sender;
	sender.setup(address_, port_);

	int start_time = ofGetElapsedTimeMillis();
	int interval_ms = interval_ * 1000 / interval_timescale_;

	//int interval_msec = 
	while (isThreadRunning())
	{
		// send frame number

		std::queue<ofxOscMessage> copied_queue;
		lock();
		copied_queue.swap(queue_);

        if (frame_number_should_reset_)
        {
            start_time = ofGetElapsedTimeMillis();
            ofxOscMessage message;
		    message.setAddress("/frame_number_reset");
		    message.addInt64Arg(0);
            copied_queue.push(message);
            frame_number_should_reset_ = false;
        }

		frame_number_ = (ofGetElapsedTimeMillis() - start_time) / interval_ms;

		long frame_number = frame_number_;
		unlock();
		
		while (copied_queue.empty() == false)
		{
			sender.sendMessage(copied_queue.front());
			copied_queue.pop();
		}

		ofxOscMessage message;
		message.setAddress("/frame_number");
		message.addInt64Arg(frame_number);

		sender.sendMessage(message);

		// Sleep until the next interval boundry
		int elapsed_time = ofGetElapsedTimeMillis() - start_time;
		int to_sleep = interval_ms - (elapsed_time % interval_ms);
		sleep(to_sleep);

	}
}

long SenderThread::getFrameNumber()
{
	long result;
	lock();
	result = frame_number_;
	unlock();
	return frame_number_;
}

void SenderThread::resetFrameNumber()
{
	lock();
	frame_number_should_reset_ = true;
	unlock();
}

void SenderThread::send(ofxOscMessage& message)
{
	lock();
	queue_.push(message);
	unlock();
}
