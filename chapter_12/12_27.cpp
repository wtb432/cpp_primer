#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<sstream>
using namespace std;
class TextQuery{
private:
	map<string,set<int>> word_line;
       	vector<string> lines;	

public:
	TextQuery(ifstream& ftr){
		string line;
		int index = 0;
		while(getline(ftr,line)){
			index++;
			lines.push_back(line);
			stringstream ssm(line);
			string word;
			while(ssm>>word){
				word_line[word].insert(index);
			}
		}
		
	}
	set<int> query(string word){
		return word_line[word];	
	}


};
ostream& print(ostream& os,set<int> p){
	for(int num:p) cout<<num<<" ";
	return os;
}
void runQueries(ifstream &infile){
	TextQuery tq(infile);
	while(true){
		cout<<"enter word to look for, or q to quit: ";
		string s;
		if(!(cin>>s) || s =="q") break;
		print(cout,tq.query(s))<<endl;
	}
}
int main(){
	ifstream ftr("Violet.txt");
	runQueries(ftr);
	return 0;
}
