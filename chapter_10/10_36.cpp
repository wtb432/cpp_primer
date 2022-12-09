#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<list>
#include<random>
#include<chrono>
using namespace std;
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
template <class T> void listShuffle(list<T> &L){
	vector<T> V(L.begin(),L.end());
	shuffle(V.begin(),V.end(),gen);
	L.assign(V.begin(),V.end());
}
int main(){
	list<int> li(15);
	iota(li.begin(),li.end(),0);
	listShuffle(li);
	auto p = find(li.crbegin(),li.crend(),0);
	cout<<distance(p,li.crend())<<endl;
}
