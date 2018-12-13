#include "stdafx.h"
#include "Tree.h"



void Tree::addNode(string event)
{
	int nodeSize = nodes.size(); //Coincidentally, this is also the index of the new node
	Node newNode = Node(event);
	newNode.number = nodeSize + 1;
	if (nodeSize == 0)
	{
		newNode.parent = "ABCDEFGH"; 
	}
	else
	{
		Node parent = nodes[(newNode.number / 2) - 1];
		newNode.parent = parent.id;
	}
	string str = newNode.rawEvent + newNode.parent;
	newNode.id = hash<string>{}(str);
	newNode.number = nodeSize+1;
	nodes.push_back(newNode);
	updateParent(newNode);
}

void Tree::displayTree()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		cout << nodes[i].id << "  ";
	}
}

void Tree::displayID(string id)
{
	int index = findIDIndex(id);
	if (index != 9999)
	{
		nodes[index].displayNode();
	}

}

void Tree::updateID(string id,string event)
{
	int index = findIDIndex(id);
	if (index != 9999)
	{
		nodes[index].rawEvent = event;
		updateParent(nodes[index]);
	}
}

int Tree::findIDIndex(string idin)
{
	int index = 9999;
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].id == idin)
		{
			index = i;
		}
	}
	if (index == 9999)
	{
		cout << ("That id could not be found") << endl;
	}
	return index;
}

void Tree::updateParent(Node child)
{
	if (child.number > 1)
	{
		child.right = child.number % 2;
		int parentIndex = (child.number / 2) - 1;
		Node parent = nodes[parentIndex];
		string toBeHashed = child.id + child.parent + child.rawEvent + child.Lhash + child.Rhash;
		if (child.right == 0)
		{
			parent.Lhash = hash<string>{}(toBeHashed); //hash of everything but hist in child
			parent.lhist.push_back(parent.Lhash);
		}
		else
		{
			parent.Rhash = hash<string>{}(toBeHashed); //hash of everything but hist in child
			parent.rhist.push_back(parent.Rhash);
		}
		nodes[parentIndex] = parent;
		updateParent(parent);
	}
}
