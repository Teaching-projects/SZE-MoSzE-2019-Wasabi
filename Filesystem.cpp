#include "Filesystem.h";

std::string Filesystem::Current() {
	return currentFile;
}

void Filesystem::printtree(){
	std::cout << user << path;
}

void Filesystem::mkdir(std::string newDirectory) {
	dir.push_back(new Directory(newDirectory, currentFile));
}

void Filesystem::ls() {
	for (auto &v : dir) {
		if (v->getParent() == Filesystem::Current()) {
			std::cout << v->getDirName() << "\n";
		}
	}
}

void Filesystem::cd(std::string dirname) {
	currentFile = dirname;
	path += dirname + "/";
}

void Filesystem::cdout() {
	if (currentFile != "/") {
		for (auto& d : dir) {
			if (d->getDirName() == currentFile) {
				path.erase(path.end() - (currentFile.length() + 1), path.end());
				currentFile = d->getParent();
			}
		}
	}
	else {
		std::cerr << "You are in root.\n" << std::endl;
	}
}
bool Filesystem::hasChildren(std::string dirname){
	for (auto &d : dir) {
		if (d->getParent() == dirname) {
			return true;
		}
	}
	return false;
}


void Filesystem::rm(std::string dirname){
	if (hasChildren(dirname)){
		std::cerr << "Directory not empty" << std::endl;
	}
	else if (hasChildren(dirname) == false){
		for (unsigned i = 0; i<dir.size(); i++){
			if (dir[i]->getDirName() == dirname){
				dir.erase(dir.begin() + i);
			}
		}
	}
}

bool Filesystem::exist(std::string dirname){
	bool exist = false;
	for (auto &iter : dir){
		if (iter->getDirName() == dirname){
			exist = true;
		}
	}
	return exist;
}