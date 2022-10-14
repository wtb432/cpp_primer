#include<iostream>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<vector>
using namespace std;
int main(){
	istream_iterator<int> item_iter(cin),eof;
	ostream_iterator<int> item_outer(cout," ");
	vector<int> vec(item_iter,eof);
	sort(vec.begin(),vec.end());
	copy(vec.cbegin(),vec.cend(),item_outer);

	return 0;
}
