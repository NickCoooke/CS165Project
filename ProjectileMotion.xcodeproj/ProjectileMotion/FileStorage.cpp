//FileStorage.cpp

#include "FileStorage.h"
#include <iostream>
#include <string>
using namespace std;

/*
	string filePath;//user input: will hold path to executable file. [Must find method to automatically record path to .exe file]
		string fileName;//name of file in which history of projectiles will be logged [i.e. "history"]
		int lastSuffix;//this tracks the LAST numerical suffix created [these numbers are appended to projectile[insert #].txt]
		int nextSuffix;//this will hold the next numerical suffix TO BE CREATED when running main executable*/
		
		
FileStorage::FileStorage()//default onstructor 
{
	filePath = "";
	fileName = "";
	folderName = "";
	lastSuffix = 0;
	nextSuffix = "";
}

FileStorage::~FileStorage()//default destructor 
{
	cout << "\ndestructor running\n";
}

void FileStorage::setFilePath(string pathInput)
{
	filePath.assign(pathInput);
}

void FileStorage::setFileName(string nameInput)
{
	fileName.assign(nameInput);
}

void FileStorage::setFolderName(string nameInput)
{
	folderName.assign(nameInput);
}

void FileStorage::setLastSuffix(int numericalInput)
{
	lastSuffix = numericalInput;
}

void FileStorage::setNextSuffix(int numericalInput)
{
	int inputPlusOne = numericalInput + 1; 
	nextSuffix = to_string(inputPlusOne);
}

string FileStorage::getFilePath() const
{
	return filePath;
}

string FileStorage::getFileName() const
{
	return fileName;
}

string FileStorage::getFolderName() const
{
	return folderName;
}


int FileStorage::getLastSuffix() const
{
	return lastSuffix;
}

string FileStorage::getNextSuffix() const
{
	return nextSuffix;
}



//this is a test










