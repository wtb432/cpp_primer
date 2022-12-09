#include<iostream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
using namespace std;
int main(){
	map<int ,list<int>> mp;
	map<vector<int>::iterator,int> mv;
	map<list<int>::iterator,int> ml;

	vector<int> vi;
	mv.insert(pair<vector<int>::iterator,int>(vi.begin(),0));
	//but when use this one 
	//error: no match for 'operator<' in '_x < _y'
	list<int> li;
	ml.insert(pair<list<int>::iterator,int>(li.begin(),0));
}
