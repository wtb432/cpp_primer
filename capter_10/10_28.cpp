#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<iterator>
#include<list>
using namespace std;
int main(){
	vector<int> vec(9);
	iota(vec.begin(),vec.end(),1);
	list<int> v1,v2,v3;
	copy(vec.begin(),vec.end(),back_inserter(v1));
	copy(vec.begin(),vec.end(),front_inserter(v2));
	copy(vec.begin(),vec.end(),inserter(v3,v3.begin()));
	for_each(v1.begin(),v1.end(),[](int i){cout<<i<<" ";});
	cout<<endl;
	for_each(v2.begin(),v2.end(),[](int i){cout<<i<<" ";});
	cout<<endl;
	for_each(v3.begin(),v3.end(),[](int i){ cout<<i<<" ";});
	cout<<endl;
	return 0;
}
