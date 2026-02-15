#include <iostream>

struct Node
{
	char data;
	Node* left;
	Node* right;

	Node(char ch)
	{
		data = ch;
		left = nullptr;
		right = nullptr;
	}
};

void PreorderTraversal(Node& tree)
{
	if (tree.left == nullptr && tree.right == nullptr)
	{
		return;
	}

	for (size_t i = 0; i < length; i++)
	{

	}
}

void InorderTraversal(Node& tree)
{

}

void PostorderTraversal(Node& tree)
{

}

int main()
{
	Node tree('A');

	PreorderTraversal(tree);

	InorderTraversal(tree);

	PostorderTraversal(tree);
}