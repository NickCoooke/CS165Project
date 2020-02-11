//FileStorage.h

#ifndef FILESTORAGE_H
#define FILESTORAGE_H
#include <stdio.h>
#include <string>
using namespace std;

class FileStorage
{
	private:
		string filePath;//user input: will hold path to executable file. [Must find method to automatically record path to .exe file]
		string fileName;//name of file in which history of projectiles will be logged [i.e. "history"]
		string folderName; // name of file in which history of projectiles will be logged
		int lastSuffix;//this tracks the LAST numerical suffix created [these numbers are appended to projectile[insert #].txt]
		string nextSuffix;//this will hold the next string suffix TO BE CREATED when running main executable

		
	public:
		FileStorage();//default constructor

		~FileStorage();//destructor

		void setFilePath(string );
		
		void setFileName(string );

		void setFolderName(string );
		
		void setLastSuffix(int );
		
		void setNextSuffix(int );//will use int input to convert numerical suffix to string  data type
		
		string getFilePath() const;
		
		string getFileName() const;

		string getFolderName() const;
		
		int getLastSuffix() const;
		
		string getNextSuffix() const;
};
#endif //FileStorage
