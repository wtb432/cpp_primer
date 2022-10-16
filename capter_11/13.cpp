#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int main(){
	vector<pair<string,int>> vec;
	string str;
	int num;
	while(cin>>str>>num) {
		vec.push_back(pair<string,int>(str,num));
		//vec.push_back(make_pair(str,num);
		//vec.push_back({str,num});
		//vec.emplace_back(str,i);
	}
	for(const auto p:vec) cout<<p.first<<" "<<p.second<<endl;
	return 0;
}
