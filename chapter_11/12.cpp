#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
	vector<pair<string,int>> vec;
	string str;
	int num;
	while(cin>>str>>num){
		vec.push_back(make_pair(str,num));
	}
	for_each(vec.begin(),vec.end(),[](pair<string,int> p){cout<<p.first<<" "<<p.second<<endl;});
	return 0;
}
