#include<iostream>
#include<numeric>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;
int main(){
/*	vector<int> vec;
	list<int> lst;
	int i;
	while(cin>>i) lst.push_back(i);
	copy(lst.cbegin(),lst.cend(),vec.begin());
*/
	//segmentation fault,the vec is empty
	
	vector<int> vec;
	vec.reserve(10);
	fill_n(vec.begin(),10,0);
	for(int v:vec) cout<<v;
	cout<<endl;
	//error,reserve assigned 10 int to vec,but vec hasn't enough elements
}
