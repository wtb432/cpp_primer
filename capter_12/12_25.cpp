#include<iostream>
#include<memory>
using namespace std;
int main(){
	int *pa = new int[10];
	delete [] pa;
}
