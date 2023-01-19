#pragma once
#include "Complex.h"
#include "Sequence.h"
#include "PriorityQueue.h"
#include "Pair.h"


template <typename Data_Point, typename Data_Edge>
class Edge;
template <typename Data_Point, typename Data_Edge>
class Graph;
string color[] =
{
	"", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK",
	"BLACK", "BROWN", "WHITE", "PURPLE", "VOILET"
};

template <typename Data_Point, typename Data_Edge>
class Point {
private:
	Data_Point data;
	int id;

	ArraySequence<Edge<Data_Point, Data_Edge>> in_edges;
	ArraySequence<Edge<Data_Point, Data_Edge>> out_edges;
public:
	friend Graph<Data_Point, Data_Edge>;
	Point() {
		id = -1;
		data = Data_Point();
	}
	Point(int i) {
		id = i;
		data = Data_Point();
	}
	Point(Data_Point value, int i) {
		data = value;
		id = i;
	}

	int Get_id() {
		return id;
	}

	Data_Point Get_data() {
		return data;
	}
	void Set_data(Data_Point x) {
		data = x;
	}
	ArraySequence<Edge<Data_Point, Data_Edge>> *Get_in_edges() {
		return &in_edges;
	}
	ArraySequence<Edge<Data_Point, Data_Edge>> *Get_out_edges() {
		return &out_edges;
	}
	void operator= (Point<Data_Point, Data_Edge> y);
	bool operator> (Point<Data_Point, Data_Edge> y);
	bool operator< (Point<Data_Point, Data_Edge> y);
	bool operator== (Point<Data_Point, Data_Edge> y);
};

template <typename Data_Point, typename Data_Edge>
bool Point<Data_Point, Data_Edge>::operator== (Point<Data_Point, Data_Edge> y) {
	if (this->id == y.id && this->data == y.data && this->in_edges == y.in_edges && this->out_edges == y.out_edges)
	{
		return true;
	}
	else
	{
		return false;
	}
}



template <typename Data_Point, typename Data_Edge>
bool Point<Data_Point, Data_Edge>::operator> (Point<Data_Point, Data_Edge> y) {
	if (this->id > y.id)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename Data_Point, typename Data_Edge>
bool Point<Data_Point, Data_Edge>::operator< (Point<Data_Point, Data_Edge> y) {
	if (this->id < y.id)
	{
		return true;
	}
	else
	{
		return false;
	}
}


template <typename Data_Point, typename Data_Edge>
void Point<Data_Point, Data_Edge>::operator=(Point<Data_Point, Data_Edge> y) {
	this->data = y.data;
	this->id = y.id;
	this->in_edges = ArraySequence<Edge<Data_Point, Data_Edge>>(y.in_edges);
	this->out_edges = ArraySequence<Edge<Data_Point, Data_Edge>>(y.out_edges);
}

template <typename Data_Point, typename Data_Edge>
class Edge {
private:
	//Point<Data_Point, Data_Edge>* start_point;
	//Point<Data_Point, Data_Edge>* end_point;

	int start_id;
	int end_id;

	Data_Edge data;
public:
	friend Graph<Data_Point, Data_Edge>;
	Edge() {
		start_id = -1;
		end_id = -1;
		data = Data_Edge(1);
	}

	
	Edge(int start, int end) {
		start_id = start;
		end_id = end;
		data = Data_Edge(1);
	}

	Edge(Data_Edge info, int start, int end) {
		start_id = start;
		end_id = end;
		data = info;
	}
	
	int Get_end() {
		return this->end_id;
	}

	int Get_start() {
		return this->start_id;
	}

	Data_Edge Get_Data(){
		return data;
	}
	bool operator== (Edge<Data_Point, Data_Edge> y);
	bool operator!= (Edge<Data_Point, Data_Edge> y);
};

template <typename Data_Point, typename Data_Edge>
bool Edge<Data_Point, Data_Edge>::operator== (Edge<Data_Point, Data_Edge> y) {
	if (this->start_id == y.start_id && this->data == y.data && this->end_id == y.end_id)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename Data_Point, typename Data_Edge>
bool Edge<Data_Point, Data_Edge>::operator!= (Edge<Data_Point, Data_Edge> y) {
	return !(*this ==y);
}

template <typename Data_Point, typename Data_Edge> 
class Graph {
private:
	ArraySequence<Point<Data_Point, Data_Edge>> Points;
	bool OrGraf;

	void Repair() {

	}
public:
	
	Graph() {
		Points = ArraySequence<Point<Data_Point, Data_Edge>>();
		OrGraf = true;
	}

	Graph(bool f) {
		Points = ArraySequence<Point<Data_Point, Data_Edge>>();
		OrGraf = f;
	}

	Graph(ArraySequence<Point<Data_Point, Data_Edge>> sequence) {
		Points = sequence;
		OrGraf = true;
	}

	Graph(bool f, ArraySequence<Point<Data_Point, Data_Edge>> sequence) {
		Points = sequence;
		OrGraf = true;
	}

	bool Get_or() {
		return OrGraf;
	}

	ArraySequence<Point<Data_Point, Data_Edge>> GetPoints() {
		return Points;
	}

	Point<Data_Point, Data_Edge> *Get_point(int id) {
		int k = 0;
		for (int i = 0; i < Points.GetSize(); i++)
		{
			if (id == Points[i].Get_id())
			{
				k = i;
			}
		}
		return &(Points[k]);
	}

	void Print();

	void Add_Point() {
		Point<Data_Point, Data_Edge> point(Points.GetSize());
		Points.Append(point);
	}
	
	void Add_Point(int id) {
		Point<Data_Point, Data_Edge> point(id);
		Points.Append(point);
	}
	/*
	void Add_Point(Data_Point data) {
		Point<Data_Point, Data_Edge> point(data, Points.GetSize());
		Points.Append(point);
	}*/
	
	void Add_Edge(int start_id, int end_id) {
		if (OrGraf)
		{
			Edge<Data_Point, Data_Edge> edge(start_id, end_id);
			Get_point(start_id)->Get_out_edges()->Append(edge);
			Get_point(end_id)->Get_in_edges()->Append(edge);
		}
	}
	void Add_Edge(Data_Edge data, int start_id, int end_id) {
		if (OrGraf)
		{
			Edge<Data_Point, Data_Edge> edge(data, start_id, end_id);
			Get_point(start_id)->Get_out_edges()->Append(edge);
			Get_point(end_id)->Get_in_edges()->Append(edge);
		}
	}
	
	void Remove_Point(int id);

	void Remove_Edge(int start_id, int end_id);

	
	
	ArraySequence<int> bfs(int ID_point1, int ID_point2);
	
	ArraySequence<int> dijkstra(int ID_point);

	void colorGraph();
};

template <typename Data_Point, typename Data_Edge>
void Graph<Data_Point, Data_Edge>::Print() {
	for (int i = 0; i < Points.GetSize(); i++)
	{
		cout << Points[i].Get_id() << " : ";
		for (int j = 0; j < Points[i].Get_out_edges()->GetSize(); j++)
		{
			cout << Points[i].Get_out_edges()->Get(j).Get_end() << ", ";
			cout << Points[i].Get_out_edges()->Get(j).Get_Data() << "; ";
		}
		cout << endl;
	}
}

template <typename Data_Point, typename Data_Edge>
void Graph<Data_Point, Data_Edge>::Remove_Point(int id) {
	int k = Get_point(id)->Get_out_edges()->GetSize();
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < Get_point(Get_point(id)->Get_out_edges()->GetLast().Get_end())->Get_in_edges()->GetSize(); j++)
		{
			if (Get_point(Get_point(Get_point(id)->Get_out_edges()->GetLast().Get_end())->Get_in_edges()->Get(j).Get_start())->Get_id() == id)
			{
				Get_point(Get_point(id)->Get_out_edges()->GetLast().Get_end())->Get_in_edges()->Remove(j);
				break;
			}
		}
		Get_point(id)->Get_out_edges()->DelEnd();
	}
	k = Get_point(id)->Get_in_edges()->GetSize();
	for (int i = 0; i < k; i++)
	{

		for (int j = 0; j < Get_point(Get_point(id)->Get_in_edges()->GetLast().Get_start())->Get_out_edges()->GetSize(); j++)
		{
			if (Get_point(Get_point(Get_point(id)->Get_in_edges()->GetLast().Get_start())->Get_out_edges()->Get(j).Get_end())->Get_id() == id)
			{
				Get_point(Get_point(id)->Get_in_edges()->GetLast().Get_start())->Get_out_edges()->Remove(j);
				break;
			}
		}

		Get_point(id)->Get_in_edges()->DelEnd();
	}

	for (int i = id; i < Points.GetSize(); i++)
	{
		Points[i].id--;
	}
	Points[id].id = -1;
	ArraySequence<Point<Data_Point, Data_Edge>>* Points1 = Points.GetSubsequence(0, id - 1);
	ArraySequence<Point<Data_Point, Data_Edge>>* Points2 = Points.GetSubsequence(id + 1, Points.GetSize() - 1);
	ArraySequence<Point<Data_Point, Data_Edge>>* Points3 = Points1->Concat(Points2);
	/*for (int i = 0; i < Points3->GetSize(); i++)
	{

		for (int j = 0; j < Get_point(j)->Get_in_edges()->GetSize(); j++)
		{
			//Points3->Get(i)->Get_in_edges()->Get(j).start_point = &(Points3->Get(Points.Get(i + 1)->Get_in_edges()->Get(j).Get_start()->id));
			Points3->Get(i)->Get_out_edges()->Get(j).end_id = &(Points3->Get(i));
		}
		for (int j = 0; j < Get_point(j)->Get_out_edges()->GetSize(); j++)
		{
			Points3->Get(i)->Get_out_edges()->Get(j).start_id = &(Points3->Get(i));
		}

	}*/
	Points = *Points3;
	//Points.DelEnd();

}

template <typename Data_Point, typename Data_Edge>
void Graph<Data_Point, Data_Edge>::Remove_Edge(int start_id, int end_id) {

	if (OrGraf)
	{

		for (int i = 0; i < Get_point(start_id)->Get_out_edges()->GetSize(); i++)
		{
			if (Get_point(Get_point(start_id)->Get_out_edges()->Get(i).Get_end())->Get_id() == end_id)
			{
				Get_point(start_id)->Get_out_edges()->Remove(i);
				break;
			}
		}

		for (int i = 0; i < Get_point(end_id)->Get_in_edges()->GetSize(); i++)
		{
			if (Get_point(Get_point(end_id)->Get_in_edges()->Get(i).Get_start())->Get_id() == start_id)
			{
				Get_point(end_id)->Get_in_edges()->Remove(i);
				break;
			}
		}
	}
}

template <typename Data_Point, typename Data_Edge>
ArraySequence<int> Graph<Data_Point, Data_Edge>::bfs(int ID_point1, int ID_point2) {
	ArraySequence<int> dist(Points.GetSize(), Points.GetSize());
	ArraySequence<int> p(Points.GetSize(), -1);
	dist[ID_point1] = 0;
	ArraySequence<int> q;
	q.Append(ID_point1);

	while (q.GetSize() != 0) {
		int v = q.GetLast();
		q.DelEnd();
		for (int j = 0; j < Get_point(v)->Get_out_edges()->GetSize(); j++)
		{
			if (dist[Get_point(v)->Get_out_edges()->Get(j).Get_end()] > dist[v] + 1)
			{
				p[Get_point(v)->Get_out_edges()->Get(j).Get_end()] = v;
				dist[Get_point(v)->Get_out_edges()->Get(j).Get_end()] = dist[v] + 1;

				q.Append(Get_point(v)->Get_out_edges()->Get(j).Get_end());
				if (Get_point(v)->Get_out_edges()->Get(j).Get_end() == ID_point1)
					break;
			}
		}
	}
	ArraySequence<int> path, res;

	if (dist[ID_point2] == Points.GetSize()) {
		return path;
	}
	int t = ID_point2;
	while (t != -1) {
		path.Append(t);

		t = p[t];
	}
	for (int i = path.GetSize() - 1; i >= 0; i--)
	{
		res.Append(path[i]);
	}

	return res;
}

template <typename Data_Point, typename Data_Edge>
ArraySequence<int> Graph<Data_Point, Data_Edge>::dijkstra(int ID_point) {
	ArraySequence<int> dist(Points.GetSize(), INT_MAX);

	dist[ID_point] = 0;
	ArraySequence<bool> used(Points.GetSize());
	int v;
	while (true) {
		
		v = -1;
		int tmp;
		for (int i = 0; i < Points.GetSize(); i++) {
			if (!used[i] && (v == -1 || dist[i] < dist[v])) {
				v = i;
				used[i] = true;
				//break;
			}
		}


		if (v == -1) {
			break;
		}

		for (int j = 0; j < Get_point(v)->Get_out_edges()->GetSize(); j++)
		{
			int u = Get_point(v)->Get_out_edges()->Get(j).Get_end();
			int len = Get_point(v)->Get_out_edges()->Get(j).Get_Data();
			if (dist[u] > dist[v] + len && dist[v] + len > 0) {
				dist[u] = dist[v] + len;
			}
		}
		//break;
	}

	return dist;
}

template <typename Data_Point, typename Data_Edge>
void Graph<Data_Point, Data_Edge>::colorGraph()///
{
	int n = Points.GetSize();
	ArraySequence < Pair<int, int> > result;
	for (int i = 0; i < n; i++)
	{
		Pair<int, int> p(i, 0);
		result.Append(p);
	}
	for (int u = 0; u < n; u++)
	{
		ArraySequence<int> assigned;
		// проверяем цвета смежных вершин
		for (int i = 0; i < Get_point(u)->Get_out_edges()->GetSize(); i++)
		{
			int tmp = Get_point(u)->Get_out_edges()->Get(i).Get_end();
			if (result[tmp].GetElement()) {
				int f = 0;
				for (int j = 0; j < assigned.GetSize(); j++)
				{
					if (assigned[j] == result[tmp].GetElement())
					{
						f = 1;
					}
				}
				if (f == 0)
					assigned.Append(result[tmp].GetElement());
			}
		}
		HeapSort(&assigned, cmp);

		// проверяем первый свободный цвет
		int color = 1;
		for (int c = 0; c < assigned.GetSize(); c++)
		{
			int tmp = assigned[c];
			if (color != tmp) {
				break;
			}
			color++;
		}
		// назначаем вершине первый доступный цвет
		result[u].SetElement(color);
	}

	for (int v = 0; v < n; v++)
	{
		cout << "The color assigned to vertex " << v << " is "
			<< color[result[v].GetElement()] << endl;
	}
}