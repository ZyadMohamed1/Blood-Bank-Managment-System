#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Node {
private:
	int data;
	Node* next;
public:
    void setDataB(int);
    void setNextB(Node*);
    int getDataB();
    Node* getNextB();
};

class bloodBagsQueue
{
private:
	Node* front = NULL;
	Node* rare = NULL;

public:
	void enQueue(int);
	void deQueue();
	void display();
	void Withdraw(int);
	int peek();
};
