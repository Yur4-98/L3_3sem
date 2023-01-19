#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Sequence.h"
#include "Graph.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>


int get_variant(int count) {
	int variant = 0;

	do
	{
		cin >> variant;
		if (variant < 1 || variant > count)
		{
			cout << "Incorrec input. Try again: ";
		}
	} while (variant < 1 || variant > count);
	return variant;
}

void print_main_menu() {
	system("cls");

	cout << "1. Input graph" << endl;
	cout << "2. Output graph" << endl;
	cout << "3. Coloring" << endl;
	cout << "4. Way search" << endl;
	cout << "5. Dijkstra" << endl;
	cout << "6. X - O" << endl;
	cout << "7. Exit" << endl;
	cout << ">";
}
void print_input_menu() {
	system("cls");

	cout << "1. Input from console" << endl;
	cout << "2. Input from file" << endl;
	cout << "3. Back" << endl;
	cout << ">";
}
void print_output_menu() {
	system("cls");

	cout << "1. Output from console" << endl;
	cout << "2. Output from file" << endl;
	cout << "3. Back" << endl;
	cout << ">";
}






template <typename Data_Point, typename Data_Edge>
void Input_menu(Graph<Data_Point, Data_Edge>* graph) {
	int var = 3;
	do
	{
		print_input_menu();
		var = get_variant(3);
		switch (var)
		{
		case 1:
			input_console(graph);
			break;
		case 2:
			input_file(graph);
			break;
		}
	} while (var != 3);
}

template <typename Data_Point, typename Data_Edge>
void Output_menu(Graph<Data_Point, Data_Edge>* graph) {
	int var = 5;
	do
	{
		print_output_menu();
		var = get_variant(3);
		switch (var)
		{
		case 1:
			output_console(graph);
			break;
		case 2:
			output_file(graph);
			break;
		}
	} while (var != 3);
}

template <typename Data_Point, typename Data_Edge>
void output_console(Graph<Data_Point, Data_Edge>* graph) {
	graph->Print();
	cout << endl;
	system("pause");
}
/*
template <typename Data_Point, typename Data_Edge>/////
void output_file1(Graph<Data_Point, Data_Edge>* graph) {
	ofstream file("out.txt");

	for (int i = 0; i < arr->GetSize(); i++) {
		file << (*graph)[i] << " ";
	}
}*/

template <typename Data_Point, typename Data_Edge>
void output_file(Graph<Data_Point, Data_Edge>* graph) {
	
	ArraySequence<int> tmp_ar;
	ArraySequence<int>* tmp_arr = &tmp_ar;
	tmp_arr->Append(graph->GetPoints().GetSize());
	
	for (int i = 0; i < graph->GetPoints().GetSize(); i++) {
		for (int j = 0; j < graph->Get_point(i)->Get_out_edges()->GetSize(); j++)
		{
			tmp_arr->Append(graph->Get_point(i)->Get_out_edges()->Get(j).Get_Data());
			tmp_arr->Append(graph->Get_point(i)->Get_out_edges()->Get(j).Get_start());
			tmp_arr->Append(graph->Get_point(i)->Get_out_edges()->Get(j).Get_end());
		}
	}

	
	int bufSize = sizeof(int) * tmp_arr->GetSize();
	ofstream file("inp.bin", ios::binary);//"out.txt");
	//for (int i = 0; i < tmp_arr->GetSize(); i++)
	//{
		file.write((char*)&((*tmp_arr)[0]), bufSize);
		//cout << "*";
	//}
	//int bufSize = sizeof(int) * (tmp_ar.GetSize());
	//file.write((char*)&(tmp_ar), bufSize);
	file.close();
	for (int i = 0; i < tmp_arr->GetSize(); i++)
	{
		cout << tmp_arr->Get(i) << " ";
	}
	system("pause");
}

template <typename Data_Point, typename Data_Edge>
void Way_menu(Graph<Data_Point, Data_Edge>* graph) {
	int id1, id2;
	
	cout << "Enter start id" << endl;
	cin >> id1;
	if (id1 > graph->GetPoints().GetSize())
	{
		return;
	}
	cout << "Enter end id" << endl;
	cin >> id2;
	if (id2 > graph->GetPoints().GetSize())
	{
		return;
	}

	ArraySequence<int> way = graph->bfs(id1, id2);

	for (int i = 0; i < way.GetSize(); i++)
	{
		cout << way[i] << " ";
	}
}

template <typename Data_Point, typename Data_Edge>
void dijkstra_menu(Graph<Data_Point, Data_Edge>* graph) {
	int id;
	cout << "Enter start id" << endl;
	cin >> id;

	ArraySequence<int> tmp = graph->dijkstra(id);

	for (int i = 0; i < tmp.GetSize(); i++)
	{
		cout <<i <<" ~ " << tmp[i] << endl;
	}
	system("pause");
}
template <typename Data_Point, typename Data_Edge>
void input_console(Graph<Data_Point, Data_Edge>* graph) {
	int size = 0;
	
	Graph<Data_Point, Data_Edge> gr_tmp;
	cout << "How many points in Graph?" << endl;
	cin >> size;
	//cout << "Enter:" << endl;
	for (int i = 0; i < size; i++)
	{
		gr_tmp.Add_Point();
		//cout << ">>";
		//cin >> n;
		//arr_tmp.Append(n);
	}
	int k = 1;
	int s, e;
	int t = 0, stop = 0;
	Data_Edge data;
	cout << "Enter edges, enter x<0 '-1' to stop" <<endl;
	while (true)
	{
		do
		{
			t = 0;
			cout << endl << "Enter start_id:" << endl;
			cin >> s;
			if (s < 0)
			{
				stop = 1;
				break;
			}
			if (s > gr_tmp.GetPoints().GetSize() - 1)
			{
				cout << "This Point not created" << endl;
			}
			else
			{
				t = 1;
			}
		} while (!t);
		if (stop)
		{
			break;
		}

		/*cout << endl << "Enter start_id:" << endl;
		cin >> s;
		if (s < 0)
		{
			break;
		}*/

		do
		{
			t = 0;
			cout << endl << "Enter end_id" << endl;
			cin >> e;
			if (e < 0)
			{
				stop = 1;
				break;
			}
			if (e > gr_tmp.GetPoints().GetSize() - 1)
			{
				cout << "This Point not created" << endl;
			}
			else
			{
				t = 1;
			}
		} while (!t);
		if (stop)
		{
			break;
		}
		/*
		cout << endl << "Enter end_id" << endl;
		cin >> e;*/
		cout << endl << "Enter weight" << endl;
		cin >> data;
		gr_tmp.Add_Edge(data, s, e);
	}

	*graph = gr_tmp;
}

template <typename Data_Point, typename Data_Edge>////////////
void input_file1(Graph<Data_Point, Data_Edge>* graph) {

	ifstream input("inp.txt");
	int ch;
	int Count = 0;
	while (input >> ch)
		Count++;
	input.close();

	ArraySequence<int> arr_tmp;
	Graph<Data_Point, Data_Edge> gr_tmp;
	ifstream file("inp.txt");
	for (int i = 0; i < Count; i++) {
		file >> ch;
		arr_tmp.Append(ch);
	}
	for (int i = 0; i < arr_tmp[0]; i++)
	{
		gr_tmp.Add_Point();
	}

	for (int i = 0; i < (arr_tmp.GetSize()-1) /3; i++)
	{
		gr_tmp.Add_Edge(arr_tmp[1+i*3], arr_tmp[2+i*3], arr_tmp[3+i*3]);
	}

	

	*graph = gr_tmp;
}

template <typename Data_Point, typename Data_Edge>
void input_file(Graph<Data_Point, Data_Edge>* graph) {
	

	
	ArraySequence<int> arr_tmp;
	char* buffer;
	int bufSize = sizeof(int);
	buffer = new char[bufSize];
	int* buf = (int*)buffer;
	ifstream file("inp.bin", ios::binary);

	while (file.read((char*)buf, bufSize))
	{
		arr_tmp.Append(buf[0]);
	}
	file.close();
	/* 
	cout << arr_tmp.GetSize() <<endl;
	for (int i = 0; i < arr_tmp.GetSize(); i++)
	{
		cout << arr_tmp[i];
	}
	system("pause");*/
	
	Graph<Data_Point, Data_Edge> gr_tmp;
	
	for (int i = 0; i < arr_tmp[0]; i++)
	{
		gr_tmp.Add_Point();
	}
	//cout << arr_tmp[0];
	//system("pause");
	
	int s(0), e(0);
	Data_Edge data(0);
	for(int i = 0; i < (arr_tmp.GetSize() - 1) / 3; i++)
	{
		gr_tmp.Add_Edge(arr_tmp[1 + 3 * i], arr_tmp[2 + 3 * i], arr_tmp[3 + 3 * i]);
	}
	
	*graph = gr_tmp;
	delete[] buffer;
	
}

template <typename Data_Point, typename Data_Edge>
void XO_menu() {
	Graph<int, int> gr;//готовим поле 3х3
	for (int i = 0; i < 9; i++)
	{
		gr.Add_Point();
		gr.Get_point(i)->Set_data(3 * i);
	}


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			gr.Add_Edge((3 * i + j),(3 * i + j + 1));
			gr.Add_Edge((3 * i + j + 1, (3 * i + j));//горизонт

			gr.Add_Edge(2,(3 * j + i), (3 * j + i + 3));
			gr.Add_Edge(2,(3 * j + i + 3), (3 * j + i)); //вертикаль
		}
	}

	for (int i = 0; i < 2; i++)
	{
		//gr.Add_Edge(3,(4 * i), (4 * i));
	}

	gr.Add_Edge(3, 0, 4);
	gr.Add_Edge(3, 4, 0);
	gr.Add_Edge(3, 4, 8);
	gr.Add_Edge(3, 8, 4);
	gr.Add_Edge(4, 2, 4);
	gr.Add_Edge(4, 4, 2);
	gr.Add_Edge(4, 4, 6);
	gr.Add_Edge(4, 6, 4);

	int k = 0, count = 0;
	int player = 1;
	int pos = 0, f = 0, t = 0;

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << 3 * i + j << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			switch (gr.Get_point(3 * i + j)->Get_data())
			{
			case 1:
				cout << "X ";
				break;
			case 2:
				cout << "O ";
				break;
			default:
				cout << "* ";
				break;
			}
		}
		cout << endl;
	}
	while (!k && count < 9)//вывод
	{
		
		switch (player)//ход
		{
		case 1:
			cout << "What is player 1 move?" << endl;
			t = 0;
			do
			{
				cout << "Enter nubper of position 0-8" << endl;
				cin >> pos;
				if (gr.Get_point(pos)->Get_data() == 1 || gr.Get_point(pos)->Get_data() == 2 || pos > 8)
				{
					cout << "This position is not free" << endl;
				}
				else
				{
					t = 1;
				}
			} while (!t);

			gr.Get_point(pos)->Set_data(1);
			count++;
			player++;
			break;
		case 2:
			cout << "what is player 2 move?" << endl;
			t = 0;
			do
			{
				cout << "enter nubper of position 0-8" << endl;
				cin >> pos;
				if (gr.Get_point(pos)->Get_data() == 1 || gr.Get_point(pos)->Get_data() == 2 || pos > 8)
				{
					cout << "This position is not free" << endl;
				}
				else
				{
					t = 1;
				}
			} while (!t);
			gr.Get_point(pos)->Set_data(2);
			count++;
			player--;
			break;
		default:
			break;
		}
		
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << 3 * i + j << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				switch (gr.Get_point(3 * i + j)->Get_data())
				{
				case 1:
					cout << "X ";
					break;
				case 2:
					cout << "O ";
					break;
				default:
					cout << "* ";
					break;
				}
			}
			cout << endl;
		}

		//проверка победы
		
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < gr.Get_point(i)->Get_out_edges()->GetSize(); j++)//ищем длину 2
			{
				if (gr.Get_point(i)->Get_data() == gr.Get_point(gr.Get_point(i)->Get_out_edges()->Get(j).Get_end())->Get_data())
				{
					for (int k = 0; k < gr.Get_point(gr.Get_point(i)->Get_out_edges()->Get(j).Get_end())->Get_out_edges()->GetSize(); k++)
					{//ищем длину 3
						if (gr.Get_point(gr.Get_point(gr.Get_point(i)->Get_out_edges()->Get(j).Get_end())->Get_out_edges()->Get(k).Get_end())->Get_data()
							== gr.Get_point(i)->Get_data()
							&& i != gr.Get_point(gr.Get_point(i)->Get_out_edges()->Get(j).Get_end())->Get_out_edges()->Get(k).Get_end())
						{
							//проверка на прямую`
							if (gr.Get_point(i)->Get_out_edges()->Get(j).Get_Data()
								== gr.Get_point(gr.Get_point(i)->Get_out_edges()->Get(j).Get_end())->Get_out_edges()->Get(k).Get_Data())
							{//плохо
								cout << "Player " << gr.Get_point(i)->Get_data() << " WIN" << endl;
								system("pause");
								return;

							}
							
						}
					}
				}
			}
		}
		system("pause");
	}
	cout << "No winner" << endl;
	system("pause");
	return;
}

template <typename Data_Point, typename Data_Edge>
void menu() {
	Graph<int, int> graph;
	int var = 7;
	do
	{
		print_main_menu();
		var = get_variant(7);
		switch (var)
		{
		case 1:
			Input_menu(&graph);
			break;
		case 2:
			Output_menu(&graph);
			break;
		case 3:
			graph.colorGraph();
			break;
		case 4:
			Way_menu(&graph);
			break;
		case 5:
			dijkstra_menu(&graph);
			break;
		case 6:
			XO_menu();
			break;
		}
//				if (var != 6)
//					system("pause");
	} while (var != 7);
}
