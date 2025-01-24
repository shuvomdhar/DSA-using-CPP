#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

class circularLinkedList
{
    void createNode(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head; // Link the new node to itself
            return;
        }
        Node *temp = head;
        while (temp->next != head) // Stop when reaching the last node
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Complete the circular link
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
        cout << "The Circular LinkedList is: ";
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "NULL" << endl << endl; // Circular lists don't truly end, but for display purposes.
    }
};

int main()
{
    Node *head = NULL;
    circularLinkedList cll;
    cll.populateList(head);
    cll.traversing(head);
    return 0;
}
