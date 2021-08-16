// Avraham Glasberg 206218745 and Itamar Cohen 318558236
// Data structures B 
// exercise 1
// the program is manage a disscuses's trees. the program allow the user to:
// create new discussion, Add a new response, Delete a sub-discussion, Print all discussion trees, Print a sub-tree, Search a string in all discussion trees and exit.

#include "tree.h"
#pragma once
#include<string>
#include<list>
#include<iostream>
using namespace std;

//Node Class

//copy constructor of Node Class
tree::Node::Node(const Node& nd)
{
	content = nd.content;
	if (!nd.lst.empty())
	{
		list<Node>::const_iterator it = nd.lst.begin();
		for (; it != nd.lst.end(); it++)
		{
			lst.push_back(Node(*it));
		}
	}
}

//constructor of Node Class
tree::Node::Node(string str)
{
	content = str;
}

//this function gets a string and returns pointer to it's node
tree::Node* tree::Node::searchNode(string str)
{
	if (content == str)
		return this;
	else if (lst.empty())
		return NULL;
	else
	{
		Node* p = NULL;
		list<Node>::iterator it = lst.begin();
		for (; it != lst.end(); it++)
		{
			if (p == NULL)
				p = it->searchNode(str);
		}
		return p;
	}
}

//this function gets node and returns pointer to it's father
tree::Node* tree::Node::searchNodeFather(Node& cur)
{

	if (!lst.empty())
	{
		Node* p = NULL;
		list<Node>::iterator it = lst.begin();
		for (; it != lst.end(); it++)
		{
			if (&(*it) == &cur)
				return this;
		}
		for (it = lst.begin(); it != lst.end(); it++)
		{
			if (p == NULL)
				p = it->searchNodeFather(cur);
		}
		return p;
	}
	else
		return NULL;
}

//this function gets a string and deleting the right node from the tree
void tree::Node::deleteNode(string str)
{
	if (!lst.empty())
	{
		list<Node>::iterator it = lst.begin();
		for (; it != lst.end(); it++)
		{
			if (it->content == str)
			{
				lst.erase(it);
				break;
			}
		}
		it = lst.begin();
		for (; it != lst.end(); it++)
		{
			it->deleteNode(str);
		}
	}
}

//this function gets a tree and print the node in the tree.
void tree::Node::printNode(tree& tr)
{
	for (int i = 0; i < tr.height(*this); i++)
		cout << "   ";
	cout << content << endl;
	if (!lst.empty())
	{
		list<Node>::iterator it = lst.begin();
		for (; it != lst.end(); it++)
		{
			it->printNode(tr);
		}
	}
}


//tree class

//constructor of tree class
tree::tree(Node* nd)
{
	root = new Node(nd->content);
	if (!nd->lst.empty())
	{
		list<Node>::iterator it = nd->lst.begin();
		for (; it != nd->lst.end(); it++)
		{
			Node node(*it);
			root->lst.push_back(node);
		}
	}
}

//distructor
tree::~tree()
{
	if (root != NULL)
	{
		delete root;
		root = NULL;
	}
}

//this function gets a string and build a new tree with that string
void tree::buildTree(string str)
{
	if (root != NULL)
		(root->lst).clear();
	root = new Node(str);
}

//this function gets a string and returns pointer to it's node
tree::Node* tree::findNode(string str)
{
	if (root != NULL)
		return root->searchNode(str);
	else
		return NULL;
}

//this function gets a node and returns pointer to it's father
tree::Node* tree::findNodeFather(Node& cur)
{
	if (root != NULL)
		if (root == &cur)
			return NULL;
		else
			return root->searchNodeFather(cur);

}

//this function gets 2 strings and add the second as the first's son.
bool tree::addSon(string father, string son)
{
	bool found = false;
	if (root != NULL)
	{
		Node* p = this->findNode(father);
		if (p != NULL)
		{
			p->lst.push_back(Node(son));
			found = true;
		}
	}
	return found;
}

//this function gets a string and delete the sub tree with this content
bool tree::deleteTree(string str)
{
	bool found = this->findNode(str) != NULL;
	if (found)
	{
		if (root->content == str)
		{
			delete root;
			root = NULL;
		}
		else
			root->deleteNode(str);
	}
	return found;
}

//this function prints all tree
void tree::printTree()
{
	if (root != NULL)
		root->printNode(*this);
}

//this function gets a node and return it's heght in the tree.
int tree::height(Node& cur)
{
	if (&cur == root)
		return 0;
	else
	{
		Node* father = this->findNodeFather(cur);
		return 1 + this->height(*father);
	}
}

//this function gets a string and prints the route to it's node
void tree::printRoute(string str)
{
	Node* p = this->findNode(str);
	if (p != NULL && p != root)
		printRouteNode(p);
}

//this function gets a pointer to node and prints the route to this node
void tree::printRouteNode(Node* cur)
{
	cout << cur->content;
	if (cur != root)
	{
		cout << "=>";
		printRouteNode(this->findNodeFather(*cur));
	}
	/*if (cur != root)
	{
		Node* father = this->findNodeFather(*cur);
		this->printRouteNode(father);
	}
	for (int i = 0; i < this->height(*cur); i++)
		cout << "   ";
	cout << cur->content << endl;*/
}

//this function gets a string and print the sub tree of this content
bool tree::printSubTree(string str)
{
	bool found = false;
	Node* p = this->findNode(str);
	if (p != NULL)
	{
		found = true;
		tree tr(p);
		tr.printTree();
	}
	return found;
}

