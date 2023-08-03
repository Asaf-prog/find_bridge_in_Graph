#ifndef SEARCHBRIDGE_Exeptions
#define SEARCHBRIDGE_Exeptions
#include <iostream>
#include <string>
using namespace std;

class Exeptions {
protected:
	string error;

public:
	string& getError() { return error; }

};

class addEdgeExeption : public Exeptions {

public:
	addEdgeExeption(string msg) { error = msg; }

};
class validEdgeExeption : public Exeptions {

public:
	validEdgeExeption(string msg) { error = msg; }

};

class validInput : public Exeptions {

public:
	validInput(string msg) { error = msg; }

};
#endif