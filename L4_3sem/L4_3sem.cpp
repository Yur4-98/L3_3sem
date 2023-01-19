
#include <iostream>
#include "Pair.h"
#include "Sequence.h"
#include "PriorityQueue.h"
#include "Graph.h"
#include "Menu.h"
using namespace std;






int main() {

	menu<int,int>();

	/*
	ArraySequence<Point<int, int>> seq;
	Point<int, int> p0(0);
	Point<int, int> p1(1);
	Point<int, int> p2(2);
	seq.Append(p0);
	seq.Append(p1);
	seq.Append(p2);
	Graph<int, int> gr;
	cout <<gr.Get_or() <<endl;
	cout << gr.GetPoints().GetSize() <<endl;
	Graph<int, int> gr1(true);
	cout << gr1.Get_or() <<endl;
	cout << gr1.GetPoints().GetSize() <<endl;
	Graph<int, int> gr2(false);
	cout << gr2.Get_or()  <<endl;
	cout << gr2.GetPoints().GetSize() <<endl;*//*
	Graph<int, int> gr3(seq);
	cout << gr3.Get_or() <<endl;
	cout << (gr3.GetPoints()[0] == seq[0]) <<endl;
	cout << (gr3.GetPoints()[1] == seq[1]);
	cout << (gr3.GetPoints()[2] == seq[2]) <<endl;
	Graph<int, int> gr4(false, seq);
	cout << gr4.Get_or()  <<endl;
	cout << (gr4.GetPoints()[0] == seq[0]) <<endl;
	cout << (gr4.GetPoints()[1] == seq[1]);
	cout << (gr4.GetPoints()[2] == seq[2]);*/
}


