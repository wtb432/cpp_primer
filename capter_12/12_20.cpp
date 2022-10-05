#include "12_20.h"
#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream file("12_20.txt");
	StrBlob bl;
	for(string str;getline(file,str);)
		bl.push_back(str);
	StrBlobPtr p(bl.begin()),q(bl.end());
	for(;p!=q;p.incr()) cout<<p.deref()<<endl;
	return 0;
}
