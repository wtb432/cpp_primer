#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
using namespace std::placeholders;
bool check(string str,int sz){
	return str.size()<=sz;
}
int main(){
	vector<string> vec{"sjf","yxc","tatakai","nbnb.","nb","op","ac"};
	cout<<count_if(vec.begin(),vec.end(),bind(check,_1,6))<<endl;
	return 0; 
}
