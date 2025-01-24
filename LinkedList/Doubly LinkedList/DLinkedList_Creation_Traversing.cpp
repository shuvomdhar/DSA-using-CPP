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

class doublyLinkedList
{
    void createNode(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

public:
    void populateList(Node *&head)
    {
        int num;
        cout << "How many list do you want to create? ";
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
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Node *head = NULL;
    doublyLinkedList dll;
    dll.populateList(head);
    dll.traversing(head);
    return 0;
}