#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <iostream>
#include <string>

class Directory{
	std::string name;
	std::string parentname;
public:
	Directory(std::string, std::string);
	std::string getDirName();
	std::string getParent();
};
#endif