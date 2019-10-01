#include <iostream>
#include <string>
#include "Filesystem.h"

using namespace std;

int main(){
	Filesystem file;
	bool ok = false;
	string command, name;
	do
	{
		file.printtree();
		cin >> command;
		if (command == "mkdir"){
			cin >> name;
			if (!file.exist(name)){ file.mkdir(name);}
			else{ cerr << "Existing file"<< endl; }
		}
		else if (command == "ls"){
			file.ls();
		}
		else if (command == "cd"){
			cin >> name;
			if (name == ".."){ file.cdout(); }
			else{
				if (!file.exist(name)) {
					cerr << "Wrong file name" << endl;
				}
				else {
					file.cd(name);
				}
			}
		}
		else if (command == "rm"){
			cin >> name;
			if (file.exist(name) == true)
				file.rm(name);
			else
				cerr <<"No such file" << endl;
		}	
		else if (command == "quit"){
			ok = true;
		}
		else{
			cout << "Wrong command!" << endl;
		}
	} while (!ok);
}