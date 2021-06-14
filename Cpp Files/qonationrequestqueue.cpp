#include "qonationrequestqueue.h"
#include "QMessageBox"

qonationRequestQueue::qonationRequestQueue()
{

}

void Node::setData(string data)
{
    this->data = data;
}

void Node::setNext(Node* next)
{
    this->next=next;
}

string Node::getData()
{
    return this->data;
}

Node* Node::getNext()
{
    return this->next;
}

void qonationRequestQueue:: enQueue(string value)
{
    Node* newNode = new Node;
    newNode->setData(value);
    newNode->setNext(NULL);
    if (front == NULL) {
        front = rare = newNode;
    }
    else {
        rare->setNext(newNode);
        rare = newNode;
    }
    counter++;
}

void qonationRequestQueue::deQueue()
{
    if (rare == NULL) {
        cout << "Queue is empty\n";
        counter = 0;
    }
    else if (front == rare) {
        Node* pointer = front;
        front = rare = NULL;
        delete(pointer);
        counter--;
    }
    else {
        Node* pointer = front;
        front = front->getNext();
        delete(pointer);
        counter--;
    }
}

void qonationRequestQueue::display()
{
    if (front == NULL) {
        cout << "Queue is empty\n";
    }
    else {
        Node* current = front;
        while (current != NULL) {
            cout << current->getData() << endl;
            current = current->getNext();
        }
    }
}

string qonationRequestQueue::peek()
{
    if (front == NULL) {

        //QMessageBox::information(nullptr/*or parent*/, "Important",
          //QString("No Donation request left"));

        return "Queue is empty";
    }
    else {
        return front->getData();
    }

}

int qonationRequestQueue::size(){
    return counter;
}
