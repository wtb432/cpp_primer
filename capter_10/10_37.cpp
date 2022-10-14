#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<list>
#include<iterator>
using namespace std;
int main(){
	vector<int> vec(10);
	iota(vec.begin(),vec.end(),0);
	list<int> li;
	copy(vec.crbegin()+3,vec.crend()-3,back_inserter(li));
	for_each(li.cbegin(),li.cend(),[&](int i){cout<<i<<" ";});
	return 0;
}
