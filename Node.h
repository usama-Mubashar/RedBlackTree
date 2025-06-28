#include <iostream>
#include<string>
#include <fstream>
using namespace std;
template <class T>
struct Node {
	T data;
	string color;
	Node *left, *right;

	Node(T data) 
	{
		this->data = data;
		color = "Red";
		left = nullptr;
		right = nullptr;
	}
};