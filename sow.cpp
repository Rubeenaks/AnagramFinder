#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<map>
#define _DEFINE_DEPRECATED_HASH_CLASSES 0

using namespace std;

int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
map <int, string> sow_hash;

struct sowpods
{
	string word;
	int num;
}sow[10];

void read_file()
{
	ifstream words_file;
	words_file.open("test.txt");
	int i = 0;
	while (i < 10)
	{
		getline(words_file, sow[i].word );
		i++;
	}
}

void create_key()
{
	for (int i = 0; i < 10; i++)
	{
		int prod = 1;
		for (int j = 0; j < sow[i].word.length(); j++)
		{
			char a = sow[i].word[j];
			a = a - 97;
			prod = prod * primes[a];
			sow[i].num = prod;	
		}
	}
}

void insert()
{
	for (int i = 0; i < 10; i++)
	{
		sow_hash[sow[i].num] = sow[i].word;
	}
}
void print()
{
	for (int i = 0; i < 10; i++)
	{
		cout<<sow[i].num<< " "<<sow_hash[sow[i].num]<<endl;
	}
}

int main()
{
	read_file();
	create_key();
	insert();
	print();
}
