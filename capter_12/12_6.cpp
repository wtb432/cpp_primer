#include<iostream>
#include<vector>
#include<string>
using namespace std;
using Ptr = vector<int>*;
auto make_dynamically()
{
	return new vector<int>{};
}
auto populate(Ptr vec)
{
	for(int i;cout<<"Pls Enter:\n",cin>>i;vec->push_back(i));
	return vec;
}
auto print(Ptr vec) -> ostream&
{
	for(auto i:*vec) cout<<i<<" ";
	return cout;
}
int main(){
	auto vec = populate(make_dynamically());
	print(vec)<<endl;	
	delete vec;
	return 0;
}

