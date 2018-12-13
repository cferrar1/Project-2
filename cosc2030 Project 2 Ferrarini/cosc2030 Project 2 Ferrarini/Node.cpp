#include "stdafx.h"
#include "Node.h"

Node::Node(string event)
{
	rawEvent = event;
}

void Node::displayNode()
{
	cout << "ID: " << id << endl;
	cout << "Parent: "<< parent << endl;
	cout << "RAWE: " << rawEvent << endl;
	cout << "LHASH: " << Lhash << endl;
	cout << "RHASH: " << Rhash << endl;
	cout << "LHIST: ";
	for (int i = 0; i < lhist.size(); i++)
	{
		cout << lhist[i] << " ";
	}
	cout << endl << "RHIST: ";
	for (int i = 0; i < rhist.size(); i++)
	{
		cout << rhist[i] << " ";
	}
}
