#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
    Node(int value)
    {
        this->prev = NULL;
        this->data = value;
        this->next = NULL;
    }
};

class circularDoublyLinkedList
{
    void createNode(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head; // Circular link
            newNode->prev = head; // Circular link
            return;
        }
        Node *last = head->prev; // Get the last node
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }

public:
    void populateList(Node *&head)
    {
        int num;
        cout << "How many nodes do you want to create? ";
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int data;
            cout << "Enter the data for node " << i + 1 << ": ";
            cin >> data;
            createNode(head, data);
        }
    }

    void traversing(Node *&head)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        cout << "The list is: ";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(circular)" << endl;
    }
};

int main()
{
    Node *head = NULL;
    circularDoublyLinkedList cdll;
    cdll.populateList(head);
    cdll.traversing(head);
}