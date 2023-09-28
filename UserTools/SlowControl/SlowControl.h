#ifndef SlowControl_H
#define SlowControl_H

#include <string>
#include <iostream>

#include "Tool.h"

class SlowControl: public Tool {

public:

   SlowControl();
   bool Initialise(std::string configfile,DataModel &data);
   bool Execute();
   bool Finalise();

private:

   zmq::socket_t* slow_control_sock;
   DAQUtilities* utils;    
   std::map<std::string,Store*> connections;
   zmq::pollitem_t items[1];
   std::string slow_control_port;
};

#endif
