#include<iostream>
#include<memory>
using namespace std;
int main(){
	unique_ptr<int> p(new int(42));
	unique_ptr<int> q(p);
	//use of deleted function
	//reason: the std libary declared the unique_ptr's copy_function and assign_function as delete to forbid the copy and assign.
	unique_ptr<int> t = p;
	return 0;
}
