#include "Factory.h"

Tool* Factory(std::string tool) {

Tool* ret=0;


  if (tool=="MyFirstTool") ret=new MyFirstTool;
return ret;
}
