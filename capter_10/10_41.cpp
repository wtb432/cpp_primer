#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<iterator>
using namespace std;
int main(){
	vector<int> vec1(20),vec2;
	iota(vec1.begin(),vec1.end(),0);
	replace_copy(vec1.begin(),vec1.end(),back_inserter(vec2),5,66);
	for_each(vec2.begin(),vec2.end(),[](int i){ cout<<i<<" ";});
	return 0;
}
