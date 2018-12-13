#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
	string id; //Hash rawEvent and Parent
	string parent;  // Parent ID
	string rawEvent; //User Input
	string Lhash; // Hash Left child except histories
	string Rhash; // Hash right child except histories
	vector<string> lhist;
	vector<string> rhist;

	int right = 0;  //If this equals 1, the node is a right child
	int number;  //Index of the node inside the vector

	Node(string event); //Constructor with a new event

	void displayNode();

};