#ifndef QONATIONREQUESTQUEUE_H
#define QONATIONREQUESTQUEUE_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Node {
    private:
        string data;
        Node* next;
public:
    void setData(string);
    void setNext(Node*);
    string getData();
    Node* getNext();
};
class qonationRequestQueue
{
public:
    qonationRequestQueue();

private:
    Node* front = NULL;
    Node* rare = NULL;
    int counter = 0;

public:
    void enQueue(string);
    void deQueue();
    void display();
    void Withdraw(string);
    int size();
    string peek();
};

#endif // QONATIONREQUESTQUEUE_H
