#include<iostream>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<vector>
using namespace std;
int main(){
	vector<int> vec(10);
	iota(vec.begin(),vec.end(),0);
	for_each(vec.crbegin(),vec.crend(),[&](int i){ cout<<i<<" ";});
	return 0;
}
