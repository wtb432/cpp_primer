#include<iostream>
#include<numeric>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
int main(){
	istream_iterator<int> item_in(cin),eof;
	ostream_iterator<int> item_out(cout," ");
	vector<int> vec(item_in,eof);
	sort(vec.begin(),vec.end());
	unique_copy(vec.cbegin(),vec.cend(),item_out);
	return 0;
}
