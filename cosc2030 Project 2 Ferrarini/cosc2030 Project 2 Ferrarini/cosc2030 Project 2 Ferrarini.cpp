﻿// cosc2030 Project 2 Ferrarini.cpp : Defines the entry point for the console application.
// Author: Cameron Ferrarini

#include "stdafx.h"
#include "Node.h"
#include "Tree.h"

int main()
{
	string input;
	string temp;
	string temp2;
	Tree binarytree;
	do
	{
		cout << "Input a function, help for a list of functions, or end to end.  ";
		getline(cin, input);
		if (input == "end")
		{
		}
		else if (input == "display node")
		{
			cout << "Which node would you like to display? (Input ID) ";
			getline(cin, temp);
			binarytree.displayID(temp);
			cout << endl << endl;
		}
		else if (input == "display tree")
		{
			binarytree.displayTree();
			cout << endl << endl;
		}
		else if (input == "add")
		{
			cout << "What is the raw event for this node? ";
			getline(cin, temp);
			binarytree.addNode(temp);
			cout << endl << endl;
		}
		else if (input == "update")
		{
			cout << "Which node would you like to update? (ID) ";
			getline(cin, temp);
			cout << "What is the new event? ";
			getline(cin, temp2);
			binarytree.updateID(temp, temp2);
		}
		else
		{
			cout << "-------HELP-------" << endl;
			cout << "Input 'display tree' to view the tree as ID values" << endl;
			cout << "Input 'display node' to view the contents of a node" << endl;
			cout << "Input 'add' to add a new node to the tree" << endl;
			cout << "Input 'update' to modify the event of an existing node" << endl;
			cout << "Input 'end' to end the program" << endl << endl << endl;
		}
	} while (input != "end");


	return 0;
}

