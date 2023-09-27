#include "MyFirstTool.h"

MyFirstTool::MyFirstTool():Tool(){}


bool MyFirstTool::Initialise(std::string configfile, DataModel &data){

  if(configfile!="")  m_variables.Initialise(configfile);
  //m_variables.Print();

  m_data= &data;
  m_log= m_data->Log;

  if(!m_variables.Get("verbose",m_verbose)) m_verbose=1;

  return true;
}


bool MyFirstTool::Execute(){

  return true;
}


bool MyFirstTool::Finalise(){

  return true;
}
