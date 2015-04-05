#include "Logger.h"
#include <iostream>
#include <fstream>

int Logger::WARNING = 1;
int Logger::INFO = 2;
int Logger::ERROR= 3;

Logger::Logger()
{
	this->file = false;
}

Logger::~Logger()
{
	//TODO *(this->flux).close();
}

Logger::Logger(std::string path)
{
	this->file = true;
	std::ofstream *file;
	file = new std::ofstream(path, std::ios::out | std::ios::app);
	if (file) 
	{
		this->flux = file;
	}
}

void Logger::write(std::string message, int type)
{
	if (this->file) 
	{
		*(this->flux) << message << std::endl;
	} 
	else 
	{
		std::cout << message << std::endl;
	}

}



