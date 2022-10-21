#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<fstream>
#include<sstream>
#include<iterator>
#include<memory>
using namespace std;
int main(){
	ifstream ftr("Violet.txt");
	vector<string> lines;
	map<string,set<int>> word_line;
	int index = 0;
	string line;
	while(getline(ftr,line)){
		index++;
		lines.push_back(line);
		istringstream ssm(line);
		string word,cword;
		while(ssm>>word){
			remove_copy_if(word.begin(),word.end(),back_inserter(cword),[](char ch)->bool{return ispunct(ch);});
			word_line[cword].insert(index);
			cword.clear();
			word.clear();
		}
	}
	while(true){
		cout<<"enter word to look for, or q to quit: ";
		string s;
		while(!(cin>>s)|| s =="q") break;
		auto p = word_line.find(s);
		if(p!=word_line.end()){
			cout<<s<<" : ";
			for(int num:p->second){
				cout<<num<<" ";
			}
			cout<<endl;
		}else{
			cout<<s<<" don't occured."<<endl;
		}
	
	}
	return 0;
}
