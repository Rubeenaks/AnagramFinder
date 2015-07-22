#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<map>
#include<vector>
#define _DEFINE_DEPRECATED_HASH_CLASSES 0

using namespace std;

int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
map <unsigned long long int, vector<string> > sow_hash;


void insert(unsigned long long int key, string value){
	if (sow_hash.find(key) == sow_hash.end()){
		vector<string> word_list (1, value);
		sow_hash[key] = word_list;
	}else{
		sow_hash[key].push_back(value);
	}
}

void printAnagrams() {
    for ( std::map<unsigned long long int, vector<string> >::const_iterator i = sow_hash.begin(); i != sow_hash.end(); ++i) {
        vector<string> word_list = i->second;
        if ( word_list.size() > 1 ) {
         for ( int j = 0; j < word_list.size(); j++ ) {
                cout << word_list[j] << "\t";
            }
            cout << endl;
        }
    }
}


void create_key(string word)
{
	
	for (int i = 0; i < 10; i++)
	{
		unsigned long long int prod = 1;
		for (int j = 0; j < word.length(); j++)
		{
			char a = word[j];
			a = a - 97;
			prod = prod * primes[a];	
		}
		insert(prod, word);
	}
}


void read_file()
{
	ifstream words_file;
	words_file.open("C:/Users/test/Downloads/test.txt");
	int i = 0;
	string word;
	while (i < 10)
	{
		getline(words_file, word );
		create_key(word);
		i++;
	}
}


int main()
{
	read_file();
	printAnagrams();
}
