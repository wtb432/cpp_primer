#include<iostream>
#include<algorithm>
#include<iterator>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int main(){
	vector<int> vec(10);
	iota(vec.begin(),vec.end(),0);
	for(auto it = prev(vec.cend());true;it--){
		cout<<*it<<" ";
		if(it==vec.cbegin()) break;
	}
	return 0;
}
