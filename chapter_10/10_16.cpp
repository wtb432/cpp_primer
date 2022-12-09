#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void elimdups(vector<string>& strs){
	sort(strs.begin(),strs.end());
	auto end = unique(strs.begin(),strs.end());
	strs.erase(end,strs.end());
}
void biggies(vector<string>& strs,size_t sz){
	elimdups(strs);

	stable_sort(strs.begin(),strs.end(),[](string const& lhs,string const& rhs){
		return lhs.size()<rhs.size();
	});
	auto wc = find_if(strs.begin(),strs.end(),[sz](string const& s){
		return s.size()>=sz;
	});
	for_each(wc,strs.end(),[](const string &s){ cout<<s<<endl;});

}
int main(){
	vector<string> strs{
		"asjdf","opoi","qughrbi","78965","12345","1234","564ad","ac"	
	};
	biggies(strs,5);
	return 0;

}

