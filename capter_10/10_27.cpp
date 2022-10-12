#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
int main(){
	vector<int> nums{1,3,6,2,4,5,3,5,6,3,7,8,6,5,3,6,654,1,53,4,6,3,6,4,6,7};
	list<int> li;
	sort(nums.begin(),nums.end());
	unique_copy(nums.begin(),nums.end(),inserter(li,li.begin()));
	for_each(li.begin(),li.end(),[](int i){cout<<i<<" ";});
	return 0;
}
