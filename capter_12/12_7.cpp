#include <iostream>
#include <vector>
#include <memory>
using namespace std;
// using Ptr = shared_ptr<vector<int>>
auto _populate() -> vector<int>
{
	vector<int> vec;
	for (int i; cout << "Pls Enter:\n", cin >> i; vec.push_back(i))
		;
	return vec;
}
auto print(shared_ptr<vector<int>> vec) -> ostream &
{
	for (auto i : *vec)
		cout << i << " ";
	return cout;
}

int main()
{
	shared_ptr<vector<int>> vec = make_shared<vector<int>>(_populate());
	print(vec) << endl;
	return 0;
}
