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

class inserting
{
    // Insert at the beginning of the list
    void insertAtBeginning(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        Node *last = head->prev; // Last node
        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
        head = newNode;
    }

    // Insert at the end of the list
    void insertAtEnd(Node *&head, int data)
    {
        if (head == NULL)
        {
            insertAtBeginning(head, data);
            return;
        }
        Node *newNode = new Node(data);
        Node *last = head->prev; // Last node
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }

    // Insert at the middle of the list
    void insertAtMiddle(Node *&head, int data, int pos)
    {
        if (pos == 1 || head == NULL)
        {
            insertAtBeginning(head, data);
            return;
        }
        Node *newNode = new Node(data);
        Node *temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

public:
    void defining(Node *&head, int choice, int pos = 0)
    {
        int node_num;
        cout << "Enter the number of nodes to be inserted: ";
        cin >> node_num;
        for (int i = 0; i < node_num; i++)
        {
            int value;
            cout << "Enter the value of node " << i + 1 << ": ";
            cin >> value;
            if (choice == 1) 
            {
                insertAtBeginning(head, value);
            }
            else if (choice == 2) 
            {
                insertAtEnd(head, value);
            }
            else if (choice == 3) 
            {
                insertAtMiddle(head, value, pos);
            }
        }
    }
};

class deleting
{
public:
    // Delete the first node of the list
    void deletionAtBeginning(Node *&head)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *last = head->prev;
        Node *temp = head;
        if (head->next == head) // Single node
        {
            delete head;
            head = NULL;
            return;
        }
        head = head->next;
        head->prev = last;
        last->next = head;
        delete temp;
    }

    // Delete the last node of the list
    void deletionAtEnd(Node *&head)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *last = head->prev;
        if (head->next == head) // Single node
        {
            delete head;
            head = NULL;
            return;
        }
        last->prev->next = head;
        head->prev = last->prev;
        delete last;
    }

    // Delete a node at a given position
    void deletionAtMiddle(Node *&head, int pos)
    {
        if (pos == 1)
        {
            deletionAtBeginning(head);
            return;
        }
        Node *temp = head;
        int count = 1;
        while (count < pos && temp->next != head)
        {
            temp = temp->next;
            count++;
        }
        if (temp->next == head && count < pos)
        {
            cout << "Invalid position." << endl;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
};

int main()
{
    Node *head = NULL;
    circularDoublyLinkedList cdll;
    cdll.populateList(head);
    cdll.traversing(head);

    inserting ins;
    int choice;
    cout << "Choose insertion type (1: Beginning, 2: End, 3: Middle): ";
    cin >> choice;
    if (choice == 3)
    {
        int pos;
        cout << "Enter position: ";
        cin >> pos;
        ins.defining(head, choice, pos);
    }
    else
    {
        ins.defining(head, choice);
    }
    cdll.traversing(head);

    deleting del;
    cout << "Choose deletion type (1: Beginning, 2: End, 3: Middle): ";
    cin >> choice;
    if (choice == 3)
    {
        int pos;
        cout << "Enter position: ";
        cin >> pos;
        del.deletionAtMiddle(head, pos);
    }
    else if (choice == 1)
    {
        del.deletionAtBeginning(head);
    }
    else if (choice == 2)
    {
        del.deletionAtEnd(head);
    }
    cdll.traversing(head);

    return 0;
}
