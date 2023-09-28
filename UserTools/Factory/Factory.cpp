#include "Factory.h"

Tool* Factory(std::string tool) {
Tool* ret=0;

// if (tool=="Type") tool=new Type;
if (tool=="MyFirstTool") ret=new MyFirstTool;
if (tool=="SlowControl") ret=new SlowControl;
return ret;
}
