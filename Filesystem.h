#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <iostream>
#include <vector>
#include "Directory.h"

class Filesystem{
	std::vector<Directory*> dir;
	const std::string user = "User";
	std::string currentFile = "/";
	std::string path = "/";
public:
	std::string Current();
	void printtree();
	void mkdir(std::string);
	void ls();
	void cd(std::string);
	void cdout();
	void rm(std::string);
	bool exist(std::string);
	bool hasChildren(std::string);

};
#endif