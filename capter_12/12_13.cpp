#include<iostream>
#include<memory>
using namespace std;
int main(){
	auto sp = make_shared<int>();
	auto p = st.get();
	//delete p;
	//obviously,delete p will destroy the memory ,then when program ends ,the reference will
	//decrese to 0,so generate error:double free
}
