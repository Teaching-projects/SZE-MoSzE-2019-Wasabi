#include "Directory.h"

Directory::Directory(std::string name, std::string parentname) : name(name), parentname(parentname){}
std::string Directory::getDirName() {
	return name;
}

std::string Directory::getParent() {
	return parentname;
}