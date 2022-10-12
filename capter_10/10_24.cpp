#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>
using namespace std;
using namespace std::placeholders;
void elimpse(vector<string>& strs){
	sort(strs.begin(),strs.end());
	auto p = unique(strs.begin(),strs.end());
	strs.erase(p,strs.end());
}
bool is_Shorter(string const& lhs,string const& rhs){
	return lhs.size()<rhs.size();
}
bool check_size(const string& s,size_t sz){
	return s.size()>=sz;
}
void print(ostream& os,const string &s){
	os<<s<<endl;
}
void biggies(vector<string>& strs,size_t sz){
	elimpse(strs);
	stable_sort(strs.begin(),strs.end(),bind(is_Shorter,_1,_2));
	auto wc = partition(strs.begin(),strs.end(),bind(check_size,_1,sz));
	for_each(strs.begin(),wc,bind(print,ref(cout),_1));
}
int main(){
	 vector<string> strs{
		                 "asjdf","opoi","qughrbi","78965","12345","1234","564ad","ac"
		        };
	biggies(strs,5);
	return 0;
}
