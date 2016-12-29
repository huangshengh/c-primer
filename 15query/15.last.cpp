#include "text.h"
#include "binary.h"
#include "query.h"
#include "query_base.h"
#include "wordquery.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::vector;

vector<string> getinput();

int main()
{
	ifstream in("D:\c++Primer\alice.txt");
	TextQuery t(in);  
	cout << "Executing Query for:\n" << endl;
	vector<string>  query_words = getinput();

}



vector<string> getinput()
{
	vector<string> words;
	string word;
	while (cin>>word)
	{
		words.push_back(word);
	}
	return words;
}