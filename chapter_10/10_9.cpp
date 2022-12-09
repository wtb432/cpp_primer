#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int main(){
	vector<string> vec;
	string str;
	while(cin>>str) vec.push_back(str);
	cout<<"input: ";
	for(string s:vec) cout<<s<<" ";
	cout<<"\n";
	sort(vec.begin(),vec.end());
	auto end_iter = unique(vec.begin(),vec.end());
	cout<<"unique: ";
	for(int i = 0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
       	cout<<"\n";
	vec.erase(end_iter,vec.end());
 	cout<<"erase: ";
	for(string s:vec) cout<<s<<" ";
	cout<<"\n";
	return 0;	
}
