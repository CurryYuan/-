#include "tree.h"
// Tree.cpp: 定义控制台应用程序的入口点。
//

using namespace std;

tree::tree()
{
	root = NULL;
}

bool tree::insert(int v)
{
	return insertHelp(&root,v);
}

void tree::display()
{
	cout << "tree inorder: ";
	displayHelp(root);
	cout << endl;
}

void tree::reverse()
{
	reverseHelp(root);
}

bool tree::insertHelp(node ** ro, int v)
{
	if (*ro == NULL) {
		*ro = new node(v);
		return true;
	}
	if (v > (*ro)->val)
		return insertHelp(&(*ro)->right, v);
	else if (v < (*ro)->val)
		return insertHelp(&(*ro)->left, v);
	else
		return false;
}

void tree::displayHelp(node * ro)
{
	if (ro == nullptr)
		return;
	displayHelp(ro->left);
	cout << ro->val << " ";
	displayHelp(ro->right);
}

void tree::reverseHelp(node*& ro)
{
	if (ro == NULL)
		return;
	node* temp = ro->left;
	ro->left = ro->right;
	ro->right = temp;
	reverseHelp(ro->left);
	reverseHelp(ro->right);
}
