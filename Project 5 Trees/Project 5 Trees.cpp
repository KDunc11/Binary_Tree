/*
	Project 5, on Chapter 6 Binary Trees
	By: Kyle Duncan

	Collaborated with Joe Bulanon and Jeff Fairbanks
*/

#include <iostream>
#include "Tree.h"
#include "Tree.cpp"
#include <cstring>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

//Function Prototypes
void openAndProccessFiles(const string& fileName, Tree<string>& tree, const int& argc, char* argv[]); //This function is used to open and handle the specified input file

int main(int argc, char* argv[]) //Command Line Arguments
{
	if (argc == 1 || argc > 4) //There must be at least 3 arguments passed into the program, the .exe, .sln, and file name to open, output file is optional
	{
		cout << "Incorrect number of arguments." << endl;
		return 1;
	}

	if (argc == 3) //Program is running with the .exe, .sln, and text file
	{
		Tree<string> tree;
		openAndProccessFiles(argv[2], tree, argc, argv);
	}

	if (argc == 4) //Program is running with the .exe, .sln, text file, and an output file
	{
		Tree<string> tree;
		openAndProccessFiles(argv[2], tree, argc, argv);
	}

	std::cout << "\n" << "Done running program, press enter to close the program.";
	std::cin.ignore();
	return 0;
}

void openAndProccessFiles(const string& fileName, Tree<string>& tree, const int& argc, char* argv[])
{
	fstream inFile;

	inFile.open(fileName); //Tries to open the specified file

	if (inFile.is_open()) //If the file can be opened then proceeds
	{
		string str;
		string secondWord;
		bool usingSecondWord = false;
		string num;

		while (!inFile.eof())
		{
			inFile >> str; //Reads in a string from the file

			int removedPunctIndex = -1; //Used to keep track of the index of the removed punctuation

			for (unsigned int i = 0; i < str.length(); ++i)
			{
				if (ispunct(str[i])) //Checks for punctuation
				{
					if (str[i] == '-' && i > 0 && i + 1 != str.length()) //Checks for hyphens
					{
						secondWord = str.substr(0, i); //Splits the string into two words, removing the hyphen
						str = str.substr(i + 1);
						usingSecondWord = true; //Since the string was split into two words, the using a second string condition is met and set to true
						i = 0; //Resets i to check for more punctuation
					}
					if (str[i] != '\'' || i == 0 || i == removedPunctIndex) //Checks for single quotes ( ' ), only removes a single quote if followed by another single quote
					{
						str = str.substr(0, i) + str.substr(i + 1); //Removes a single quote from the string
						removedPunctIndex = i; //Sets the index
						i--;
					}
				}
			}

			if (isdigit(*str.c_str())) //Checks if the read in string is a number, if it is then set it equal to the num string variable. Variable will not change until the next verse number is read in
				num = str;
			else if (usingSecondWord) 
				if (isdigit(*secondWord.c_str())) //Checks if the second string read in is a number
					num = secondWord;

			if (isalpha(*str.c_str())) //Checks if the string is composed of letters
			{
				int i = 0;
				while (str[i] != '\0')
				{
					str[i] = tolower(str[i]); //sets all characters to lowercase
					i++;
				}

				tree.insert(str, stoi(num)); //Calls Tree.h's insert function to insert a word and verse number into the tree
			}
			
			if (usingSecondWord) //If a second string is used continue
			{
				if (isalpha(*secondWord.c_str())) //Same as above
				{
					int i = 0;
					while (secondWord[i] != '\0')
					{
						secondWord[i] = tolower(secondWord[i]); //Changes second string to lowercase letters
						i++;
					}

					tree.insert(secondWord, stoi(num)); //Inserts a second string and verse number into the tree
				}
			}

			usingSecondWord = false; //Resets the boolean
		}
		inFile.close(); //Closes the input file
	}
	else 
		cout << "Could not open file." << endl;

	if (argc == 3) //No Output File Specified, Output to console
	{
		cout << tree; //Displays tree onto console
		cout << "Total Nodes: " << tree.leafNodeCount() << endl;
		cout << "Tree Depth: " << tree.depth();
	}

	if (argc == 4) //Need to Output Tree to a file
	{
		ofstream outFile;
		outFile.open(argv[3]);

		if (outFile.is_open())
		{
			outFile << tree; //outputs tree into a file
			cout << "\n" << "Outputted data to " << argv[3] << endl;
		}
		else
			cout << "Could not open output file." << endl;

		outFile << "Total Nodes: " << tree.leafNodeCount() << endl;
		outFile << "Tree Depth: " << tree.depth();

		outFile.close(); //Closes the output file
	}
}