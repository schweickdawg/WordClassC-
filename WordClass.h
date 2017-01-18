#ifndef _wordclass_
#define _wordclass_
#include<vector>
using namespace std;
#include<string>
#include<fstream>
using namespace std;
class WordClass
{
public:
	//constructors
	WordClass();
	WordClass(string);  //used to open a dict file
	~WordClass();
	//functions
	void doesNothing();
	bool contains(string, string);
	bool contains(char, string);
	string reverse(string);
	string upper(string);
	string upper(char);
	string lower(string);
	string lower();
	string lower(char);
	int howManyOf(string, string);
	int wordCount();
	int indexOfWord(string);
	int indexOfWord(string, int);
	int howManyOf(char, string);
	int indexAt(char, string);
	int indexAt(int, char, string);
	int indexAt(string, string);
	int indexAt(int, string, string);
	string alphaString(string);
	string wordAt(int);
	bool isSubset(string, string);

private:
	int wordsInFileCounter;
	vector<string> library;
	ifstream inputFileHandle;
	ofstream outputFileHandle;
	string currWord;
};

#endif
