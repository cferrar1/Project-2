#pragma once
#include "Node.h"
#include <vector>
// Author: Cameron Ferrarini


class Tree
{
public:
	vector<Node> nodes;
	int levels = 0;

	void updateParent(Node child);  //Updates l/rhash and appends new l/rhash to l/rhist
	void addNode(string event);

	void displayTree();
	void displayID(string id);
	void updateID(string id, string event);
	int findIDIndex(string id); //returns the vector index of the Node with the given ID


};
