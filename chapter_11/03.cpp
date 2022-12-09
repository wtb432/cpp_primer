#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<fstream>
using namespace std;
int main(){
	map<string,size_t> word_count;
	ifstream ftr("Violet.txt");
	string word;
	set<string> exclude = {"The","But","And","Or","An","A","the","but","and","or","an","a"};
	while(ftr>>word){
		if(exclude.find(word) == exclude.end()){
			++word_count[word];
		}
	}
	for(const auto& w:word_count )
		cout<<w.first<<" occurs "<<w.second<<((w.second>1)?" times":" time")<<endl;
	return 0;
}
