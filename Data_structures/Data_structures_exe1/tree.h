// Avraham Glasberg 206218745 and Itamar Cohen 318558236
// Data structures B 
// exercise 1
// the program is manage a disscuses's trees. the program allow the user to:
// create new discussion, Add a new response, Delete a sub-discussion, Print all discussion trees, Print a sub-tree, Search a string in all discussion trees and exit.

#pragma once
#include<string>
#include<list>
#include<iostream>
using namespace std;
class tree
{
public:
	class Node
	{
	public:
		string content;//string of the content of discusion
		list<Node> lst;//list of resposes to discusion

		Node(const Node& nd);//copy ctr
		Node(string str);//ctr
		Node* searchNode(string str);//searching node by content
		Node* searchNodeFather(Node& cur);//searching father by current node
		void deleteNode(string str);//deleting node by content
		void printNode(tree& tr);//printing node in tree tr.
	};
	Node* root;//the root of the tree
public:
	tree(Node* nd);//ctr
	tree() { root = NULL; }//ctr
	~tree();//dstr
	void buildTree(string dis);//start a tree by string

	bool addSon(string father, string son);//adding sin node to father node by strings
	bool deleteTree(string str);//deleting tree by string
	void printTree();//printing all tree
	void printRoute(string str);//printing route to node by string
	bool printSubTree(string str);//printing sub tree by string

private:
	Node* findNode(string str);//finding node by string
	Node* findNodeFather(Node& cur);//finding father by current node
	int height(Node& cur);//the height of current node
	void printRouteNode(Node* cur);//print route by node.
};
