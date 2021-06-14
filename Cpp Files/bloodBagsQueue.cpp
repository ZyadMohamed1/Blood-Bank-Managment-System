#include "bloodBagsQueue.h"
#include "QMessageBox"

void Node::setDataB(int data)
{
	this->data = data;
}

void Node::setNextB(Node* next)
{
	this->next = next;
}

int Node::getDataB()
{
	return this->data;
}

Node* Node::getNextB()
{
	return this->next;
}

void bloodBagsQueue::enQueue(int value)
{
	Node* newNode = new Node;
    newNode->setDataB(value);
    newNode->setNextB(NULL);
	if (front == NULL) {
		front = rare = newNode;
	}
	else {
        rare->setNextB(newNode);
		rare = newNode;
	}
}

void bloodBagsQueue::deQueue()
{
	if (rare == NULL) {
		cout << "Queue is empty\n";
	}
	else if (front == rare) {
		Node* pointer = front;
		front = rare = NULL;
		delete(pointer);
	}
	else {
		Node* pointer = front;
        front = front->getNextB();
		delete(pointer);
	}
}

void bloodBagsQueue::display()
{
	if (front == NULL) {
		cout << "Queue is empty\n";
	}
	else {
		Node* current = front;
		while (current != NULL) {
            cout << current->getDataB() << endl;
            current = current->getNextB();
		}
		cout << "\n++++++++++++++\n";
	}
}

void bloodBagsQueue::Withdraw(int num)
{
	int diffrence, Remainder;
	if (front == NULL) {
		cout << "Queue is empty\n";
	}
	else {
		Node* current = front;
		while (num != 0) {

            diffrence = current->getDataB() - num;
			if (diffrence > 0) {
                current->setDataB(diffrence);
				num = 0;
			}
			else if (diffrence == 0) {
				deQueue();
				num = 0;
			}
			else {
				num = diffrence * -1;
                current->setDataB(0);
			}

            current = current->getNextB();

		}
	}
}

int bloodBagsQueue::peek()
{
	if (front == NULL) {
		cout << "Queue is empty\n";
		return NULL;
	}
	else {
        return front->getDataB();
	}

}
