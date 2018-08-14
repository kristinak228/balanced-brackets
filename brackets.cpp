/*
Kristina Kolibab
8/14/18

Program to ensure a string of brackets is balanced

Compile: g++ -o brackets brackets.cpp -std=c++11
Execute: ./brackets
*/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void display_vector(vector<char> v){
	for(auto x : v) cout << x << " ";
	cout << endl;
}

bool is_balanced(string & str){	
	cout << str << endl;
 	vector<char> v;
	string::iterator itr = str.begin();
	while(itr != str.end()){	
		while(*itr == '{' || *itr == '(' || *itr == '['){
			v.push_back(*itr);
			itr++;
		}
		char ch = v.back();
		cout << "open: " << ch << " closed: " << *itr << endl;
		switch (ch)
		{
			case '{': 
				if(*itr != '}')	return false;
				break;
			case '(': 
				if(*itr != ')') return false;
				break;
			case '[': 
				if(*itr != ']')	return false;
				break;
		}
		v.pop_back(); 
		itr++;
	}
	return true;
}

int main(){
	string str = "{([])}"; // balanced
	string str2 = "{{(([[]])))}"; // not balanced

	if(is_balanced(str2)) cout << "Params are balanced!\n";
	else cout << "Params are NOT balanced!\n";

	return 0;
}
