#include <iostream>

class TreeNode
{
public:
	TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode &Td) : value(Td.value), count(Td.count), left(Td.left), right(Td.right) { ++*count; }

	TreeNode &operator=(TreeNode &Td);
	~TreeNode()
	{
		if (--*count == 0)
		{
			delete left;
			delete right;
			delete count;
		}
	}

private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};
class BinStrTree
{
private:
	TreeNode *root;

public:
	BinStrTree() : root(new TreeNode()) {}
	BinStrTree(const BinStrTree &BT) : root(new TreeNode(*BT.root)) {}
	BinStrTree &operator=(BinStrTree &);
	~BinStrTree() { delete root; }
};

TreeNode &TreeNode::operator=(TreeNode &Td)
{
	++*Td.count;
	if (--*count == 0)
	{
		delete left;
		delete right;
		delete count;
	}
	value = Td.value;
	left = Td.left;
	right = Td.right;
	count = Td.count;
	return *this;
}

BinStrTree &BinStrTree::operator=(BinStrTree &BT)
{
	TreeNode *new_root = new TreeNode(*BT.root);
	delete root;
	root = new_root;
	return *this;
}
int main()
{
	return 0;
}
