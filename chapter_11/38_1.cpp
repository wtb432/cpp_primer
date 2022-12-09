#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<cctype>

using std::string;
using std::cin;
using std::cout;
using std::remove_if;
using Map = std::unordered_map<std::string,std::size_t>;



auto strip(string& str) -> string const&
{
	for(auto& ch:str) ch = tolower(ch);
	str.erase(remove_if(str.begin(),str.end(),ispunct),str.end());
	return str;
}

auto strip_and_count(){
	Map counts;
	for(string w;cin>>w;++counts[strip(w)]);
	return counts;
}

auto print(Map const& m)
{
	for(auto const& kv:m)
		cout<<kv.first<<" : "<<kv.second<<"\n";
}

int main(){
	cout<<"Enter a few words please:\n";
	print(strip_and_count());
	return 0;
}
