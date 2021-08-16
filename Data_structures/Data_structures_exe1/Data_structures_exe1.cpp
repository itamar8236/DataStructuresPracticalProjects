// Avraham Glasberg 206218745 and Itamar Cohen 318558236
// Data structures B 
// exercise 1
// the program is manage a disscuses's trees. the program allow the user to:
// create new discussion, Add a new response, Delete a sub-discussion, Print all discussion trees, Print a sub-tree, Search a string in all discussion trees and exit.

#include <iostream>
#include <list>
#include <string>
#include "tree.h"
#include"treeList.h"

using namespace std;

int main()
{
	treeList tl;
	string title, father, val, son;
	char ch;
	cout << "DISCUSSION TREE\n";
	cout << "Choose one of the following:" << endl;
	cout << "n: New discussion tree" << endl;
	cout << "s: Add a new response" << endl;
	cout << "d: Delete a sub-discussion" << endl;
	cout << "p: Print all discussion trees" << endl;
	cout << "r: Print a sub-tree" << endl;
	cout << "w: Search a string in all discussion trees" << endl;
	cout << "e: exit:" << endl;
	do
	{
		cin >> ch;
		switch (ch)
		{
		case 'n':cout << "enter the discussion title (with no space) "; cin >> val; tl.createTreeList(val); break;
		case 's':cout << "enter the discussion title (with no space) "; cin >> title;
			cout << "enter the last message (with no space) "; cin >> father;
			cout << "enter the new respond "; cin >> son;
			if (tl.addRespToTree(title, father, son)) cout << "success\n"; else cout << "ERROR\n"; break;
		case 'd':cout << "enter the discussion title (with no space) "; cin >> title;
			cout << "enter string of subtree to delete (with no space) "; cin >> val;
			if (tl.deleteDisFromTree(title, val)) cout << "success\n"; else cout << "ERROR\n"; break;
		case 'p':tl.printAllTrees();  break;
		case 'r':
			cout << "enter the discussion title (with no space) "; cin >> title;
			cout << "enter the last message (with no space) "; cin >> val;
			tl.printSubTree(title, val); cout << endl;  break;
		case 'w':cout << "enter a string (with no space) "; cin >> val;
			if (tl.searchAndPrint(val)) cout << endl; else cout << "ERROR" << endl; break;
		case 'e':cout << "bye "; break;
		default: cout << "ERROR\n";  break;
		}
	} while (ch != 'e');

	return 0;
}
//Running example:
//DISCUSSION TREE
//Choose one of the following :
//n: New discussion tree
//s : Add a new response
//d : Delete a sub - discussion
//p : Print all discussion trees
//r : Print a sub - tree
//w : Search a string in all discussion trees
//e : exit:
//n
//enter the discussion title(with no space) first
//n
//enter the discussion title(with no space) second
//s
//enter the discussion title(with no space) first
//enter the last message(with no space) f1
//enter the new respond f1
//ERROR
//s
//enter the discussion title(with no space) first
//enter the last message(with no space) first
//enter the new respond f1
//success
//s
//enter the discussion title(with no space) first
//enter the last message(with no space) first
//enter the new respond f2
//success
//s
//enter the discussion title(with no space) first
//enter the last message(with no space) f1
//enter the new respond f2
//success
//s
//enter the discussion title(with no space) second
//enter the last message(with no space) second
//enter the new respond s1
//success
//d
//enter the discussion title(with no space) first
//enter string of subtree to delete (with no space) f2
//success
//p
//Tree #1
//second
//s1
//
//Tree #2
//first
//f1
//


