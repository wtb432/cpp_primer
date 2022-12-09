#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<iterator>
#include<fstream>
using namespace std;
int main(){
	ifstream fst("nums.txt");
	ofstream ost("odd.txt"),est("even.txt");
	istream_iterator<int> item_in(fst),eof;
	ostream_iterator<int> item_out_odd(ost," "),item_out_even(est," ");
	for_each(item_in,eof,[&](int i){
		if(i&1) *item_out_odd++ = i;
		else *item_out_even++ = i;
	});
	return 0;
}
