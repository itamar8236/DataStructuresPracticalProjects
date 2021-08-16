// Avraham Glasberg 206218745 and Itamar Cohen 318558236
// Data structures B 
// exercise 1
// the program is manage a disscuses's trees. the program allow the user to:
// create new discussion, Add a new response, Delete a sub-discussion, Print all discussion trees, Print a sub-tree, Search a string in all discussion trees and exit.

#include "treeList.h"
#include "tree.h"

// create list of tree
void treeList::createTreeList(string title) 
{
	tree* tr = new tree;
	tr->buildTree(title);
	lst.push_front(*tr);
}

// this func get pointer to Node and delete the match tree from the list
void treeList::deleteTreeList(tree::Node* nd) 
{
	list<tree>::iterator it = lst.begin(); // find the tree
	for (; it != lst.end(); it++) { 
		if (it->root == nd) 
			lst.erase(it); // delete the tree from the list
	}
}

// this func search disscuse and print for all his apperance in the list the path to him and the sub tree of him
bool treeList::searchAndPrint(string dis)
{
	bool found = false;
	list<tree>::iterator it = lst.begin();
	for (; it != lst.end(); it++) // run on all the tree 
	{
		if (it->printSubTree(dis))
		{
			found = true;
			it->printRoute(dis);
			cout << endl;
		}
	
		
	}
	return found;
}

// this func add respone to disscuse in the asked tree 
bool treeList::addRespToTree(string title, string cont, string respons) 
{
	bool found = false; // flag for check if the needed disscus is exist and return the "answer"
	list<tree>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
	{
		if (it->root->content == title)
			if (it->addSon(cont, respons)) // add the respons in the right place
				found = true; // turn on the flag
	}
	return found;
}

// this func delete disscus from the tree
bool treeList::deleteDisFromTree(string title, string cont) 
{
	bool found = false; // flag
	list<tree>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
	{
		if (it->root->content == title && title == cont)
		{
			lst.erase(it);
			return true;
		}
		else if (it->root->content == title)
			if (it->deleteTree(cont))
				found = true;
	}
	return found;
}

// this func print the tree that is root's content is equal to "title"
void treeList::printTree(string title) 
{
	list<tree>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
	{
		if (it->root->content == title)
			it->printTree();
	}
}

// this func get strings and print the sub tree of the first string
void treeList::printSubTree(string title, string cont)
{
	list<tree>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
	{
		if (it->root->content == title)
		{
			it->printSubTree(cont);
			it->printRoute(cont);
		}
	}
}

// this func print all the trees
void treeList::printAllTrees()
{
	int i = 0;
	list<tree>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
	{
		i++;
		cout << "Tree #" << i << endl;
		it->printTree();
		cout << endl;
	}
}