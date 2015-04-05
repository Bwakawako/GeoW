#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Logger
{
public:
	Logger(void);
	~Logger(void);
	
	Logger(std::string path);
	void write(std::string message, int type = Logger::INFO);
	
	static int WARNING;
	static int INFO;
	static int ERROR;
	
private:
	std::ofstream *flux;
	bool file;
};

