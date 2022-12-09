#include<iostream>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<vector>
#include<fstream>
using namespace std;
int main(){
	vector<string> vec;
	fstream fst("Violet.txt");
	istream_iterator<string> item_iter(fst),eof;
	ostream_iterator<string> outer_iter(cout," ");
	copy(item_iter,eof,inserter(vec,vec.begin()));
	copy(vec.begin(),vec.end(),outer_iter);
	return 0;
}
