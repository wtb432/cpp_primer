#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<fstream>
#include<cctype>
#include<string>
using namespace std;
int main(){
	map<string,size_t> word_count;
	ifstream ftr("Violet.txt");
	string word;
	set<string> exclude = {"the","but","and","or","an","a"};
	while(ftr>>word){
		transform(word.begin(),word.end(),word.begin(),::tolower);
		word.erase(remove_if(word.begin(),word.end(),ispunct),word.end());
		if(exclude.find(word) == exclude.end()){
			auto p = word_count.insert({word,1});
			if(!p.second){
				p.first->second++;
			}
		}
	}
	for(const auto& w:word_count){
		cout<<w.first<<" occurs "<<w.second<<endl;
	}
	return 0;
}
