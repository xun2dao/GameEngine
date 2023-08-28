#include<iostream>
#include<config.h>
#include"logger.h"

namespace engine{
void PrintEngine(){

#ifdef _ENGINE_
	EG_ERROR("Engine Starts! value = {}", 9);
#endif
	std::cout<< "Engine"<<std::endl;
}
}
