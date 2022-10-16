#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<string> exclude = {"aa","bb","cc","dd","ee","ff"};
	for(string word;cout<<"Enter the word:\n",cin>>word;){
		auto is_excluded = binary_search(exclude.begin(),exclude.end(),word);
		auto reply = is_excluded ? "excluded":"not excluded";
		cout<<reply<<endl;
	}
	
}
