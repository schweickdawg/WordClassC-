#include"WordClass.h"
#include<iostream>
using namespace std;
WordClass::WordClass()
{
	//daddy  likes steak
}
WordClass::WordClass(string a)
{
	string temp;
	wordsInFileCounter=0;
	inputFileHandle.open(a.c_str());
	inputFileHandle>>temp;
	while(!inputFileHandle.eof())
	{
		library.push_back(temp);
		inputFileHandle>>temp;
		wordsInFileCounter++;
	}
	currWord="";
}
WordClass::~WordClass()
{

}
int WordClass::wordCount()
{
	return wordsInFileCounter;
}
//functions
string WordClass::wordAt(int place)
{
	currWord=library.at(place);
	return library.at(place);
}
int WordClass::indexOfWord(string s)
{
	int counter=1;
	for each (string word in library)
	{
		if (word!=s)
			counter++;
		else
			return counter;
	}
	return -1;
}
int WordClass::indexOfWord(string s, int place)
{
	for( int h = place+1; h<library.size(); h++)
	{
		if(library.at(h)==s)
			return h;
	}
	return -1;
}
bool WordClass::contains(string a, string b)
{
	if(a.length()>1)
	{
		cout<<"String to check may NOT exceed length of 1"<<endl;
		return false;
	}
	for(int y = 0; y<b.length(); y++)
	{
		if(a[0]==b[y])
			return true;
	}
	return false;
}
bool WordClass::contains(char a, string b)
{
	for(int y = 0; y<b.length(); y++)
	{
		if(a==b[y])
			return true;
	}
	return false;
}
string WordClass::reverse(string a)
{
	string temp="";
	for(int l = 0; l<a.length(); l++)
		temp=a.substr(l,1)+temp;
	return temp;
}
string WordClass::upper(string a)
{
	for(int d = 0; d<a.length(); d++)
		a[d]=toupper(a[d]);
	return a;
}
string WordClass::upper(char a)
{
	string temp;
	temp=toupper(a);
	return temp;
}
string WordClass::lower()
{
	return lower(currWord);
}
string WordClass::lower(string a)
{
	for(int d = 0; d<a.length(); d++)
		a[d]=tolower(a[d]);
	return a;
}
string WordClass::lower(char a)
{
	string temp;
	temp=tolower(a);
	return temp;
}
int WordClass::howManyOf(string letter, string target)
{
	if(letter.length()>1)
		return -1;
	int count=0;
	for(int j=0; j<target.length(); j++)
		if(letter==target.substr(j,1))
			count++;
	return count;
}
int WordClass::howManyOf(char letter, string target)
{
	int count = 0;
	for(int j=0; j<target.length(); j++)
		if(letter==target[j])
			count++;
	return count;
}
int WordClass::indexAt(char c, string target)
{
	for(int j=0; j<target.length(); j++)
		if(c==target[j])
			return j;
	return -1;
}
int WordClass::indexAt(int start, char c, string target)
{
	for(int j=start; j<target.length(); j++)
		if(c==target[j])
			return j;
	return -1;
}
int WordClass::indexAt(string s, string target)
{
	if(s.length()>target.length())
		return -1;
	for(int y = 0; y<=target.length()-s.length(); y++)
		if(s==target.substr(y, s.length()))
			return y;
	return -1;
}
int WordClass::indexAt(int start, string s, string target)
{
	if(s.length()>target.length())
		return -1;
	for(int y = start; y<=target.length()-s.length(); y++)
		if(s==target.substr(y, s.length()))
			return y;
	return -1;
}
string WordClass::alphaString(string word)
{
	string finished="";
	char *arr;
	arr=new char[word.length()+1];
	for(int t=0; t<word.length(); t++)
	{  //break word into char array
		arr[t]=word[t];
	}
	for(int t =0; t<word.length()-1; t++)  //sort chars
		for(int y = 0; y<word.length()-1; y++)
		{
			if(arr[y]>arr[y+1])
			{
				arr[word.length()]=arr[y];
				arr[y]=arr[y+1];
				arr[y+1]=arr[word.length()];
			}
		}
	for(int t=0; t<word.length(); t++)
		finished+=arr[t];
	return finished;
}
bool WordClass::isSubset(string part, string whole) //does the part exist entirely in the whole
{
	for(int y = 0; y<part.length();y++)
	{
		if(indexAt(part[y], whole)==-1)
			return false;
	}
	return true;
}
