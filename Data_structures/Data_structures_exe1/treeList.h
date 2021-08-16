// Avraham Glasberg 206218745 and Itamar Cohen 318558236
// Data structures B 
// exercise 1
// the program is manage a disscuses's trees. the program allow the user to:
// create new discussion, Add a new response, Delete a sub-discussion, Print all discussion trees, Print a sub-tree, Search a string in all discussion trees and exit.

#pragma once
#include <iostream>
#include <list>
#include "tree.h"

using namespace std;

class treeList 
{
private:
	list<tree> lst;

public:

	treeList() {}; // ctor 
	~treeList() { lst.clear(); } // dtor 
	void createTreeList(string title); //create tree List
	void deleteTreeList(tree::Node* nd);//delete Tree List
	bool searchAndPrint(string dis); //search
	bool addRespToTree(string title, string cont, string respons); // add Response To the Tree
	bool deleteDisFromTree(string title, string cont); // delete Dis From Tree
	void printTree(string title); // print the title Tree
	void printSubTree(string title, string cont); // print Sub Tree
	void printAllTrees(); // print All Trees
};

