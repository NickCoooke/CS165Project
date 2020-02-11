/*
	define macro for backslash or forward slash depending on OS
	http://www.cplusplus.com/doc/tutorial/preprocessor/


    REVISION COMMENTS: alternate main for file storage system
*/
#ifdef TARGET_OS_MAC
#define SLASH_SYMBOL '/'

#elif defined __APPLE__
#define SLASH_SYMBOL '/'

#elif defined _WIN32
#define SLASH_SYMBOL '\\'
#endif

#include <cctype>
#include <direct.h> //for mkdir (make directory) & rmdir (remove directory) functions
#include "FileStorage.cpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

//Libraries for rand function
#include <ctime>
#include <cstdlib>

bool createFolder(FileStorage &, string);
void pathFileANDsuffixFile(FileStorage &);

int main()
{
	srand(time(0)); //for createFolder Function

	FileStorage historyFolder;
	historyFolder.setFolderName("history"); //preset by programmer
	historyFolder.setFileName("Projectile"); //preset by programmer
	pathFileANDsuffixFile(historyFolder);

	//call path.txt. if it exists, then open and read to char[]
	//if it does not exist, create a file and ask user to input file location

	//generate a new texfile in history folder to hold projectile#.txt
	//fout to this file for the projectile that was run

	return 0;
}


void pathFileANDsuffixFile(FileStorage &object) //temporary function name..
												/*purpose: locate or create "path.txt" which holds the directory
												then set setFilePath + \history to create a folder in the next function*/
{
	//attempt to open path.txt
	ifstream fin;
	fin.open("path.txt");////>>CREATE pirvate class member for "path.txt"

	//if path.txt does not exist, ask user for directory path. Program will generate path.txt and file-output directory path
	if (!fin.good())
	{
		string userInput = "";

		//error handle user's input
		bool isNotValid = false;
		while (!isNotValid)
		{
			cout << "\nPlease enter directory path to executable's folder: ";
			getline(cin, userInput);

			if (userInput.length() < 1)
			{
				cout << "\n***Blank Entry. Please try again***\n";
				continue;
			}//if

			 /*
			 concatenate user's input with file name for compelete file location
			 require two backslash characters since the first one is the escape sequence, the second being the actual backslash
			 https://stackoverflow.com/questions/19405196/what-does-a-backslash-in-c-mean [see escape sequence - bottom page]
			 */
			object.setFilePath(userInput + SLASH_SYMBOL + object.getFolderName());

			if (createFolder(object, userInput))
			{
				ofstream fout;
				fout.open("path.txt");
				if (!fout.good()) throw "I/O error"; //error handling
				fout << object.getFilePath();
				fout.close();
				isNotValid = true;
			}//if

			else
				cout << "\n***Invalid directory path entered. Please try again***\n";
		}//while
	}//if

	else if (fin.good())
	{
		string fileInput;
		getline(fin, fileInput);
		object.setFilePath(fileInput);
	}
	fin.close();
}//pathTextFile

bool createFolder(FileStorage &object, string userInput)
{
	//generate a RANDOM number to create random file
	//	IF creation of file is successful, pathway must be good. 
	//		Create the '\history' file. Delete the random file
	//	IF unsuccessful, return false for user to re-enter correct pathway
	//All of this could be avoided if we can "find" the pathway ourselves (rather than user input)

	int randomNum = (rand() % 1000);
	string randomDirectory = to_string(randomNum) + "x";
	randomDirectory = userInput + SLASH_SYMBOL + randomDirectory;

	char *tempRandomCstring = new char[randomDirectory.length() + 1];
	strcpy(tempRandomCstring, randomDirectory.c_str());

	//IF file creation successful, mkdir will return 0
	//IF file creation unsuccessful, mkdir will return -1
	int creationStatus = -1;
	creationStatus = _mkdir(tempRandomCstring);

	if (creationStatus == 0)
	{
		//create a history folder(if previously created, the program will do nothing)
		char *tempCstring = new char[object.getFilePath().length() + 1];
		strcpy(tempCstring, object.getFilePath().c_str());
		_mkdir(tempCstring);
		delete[] tempCstring;
		//delete random folder
		_rmdir(tempRandomCstring);
		return true;
	}//if
	else
		return false;

	delete[] tempRandomCstring;

}//createFolder



