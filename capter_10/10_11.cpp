#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
	vector<string> vec;
	string str;
	while(cin>>str){
		vec.push_back(str);
	}	
	stable_sort(vec.begin(),vec.end(),[](string a,string b){
		return a.size()<b.size();	
	});
	for(string s:vec) cout<<s<<" ";
	cout<<"\n";
	return 0;
}
