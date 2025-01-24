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
        cout << "The list is: ";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl
             << endl;
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
            return;
        }
        Node *temp = head;
        newNode->next = temp;
        temp->prev = newNode;
        head = newNode;
    }

    // Insert at the end of the list
    void insertAtEnd(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert at the middle of the list
    void insertAtMiddle(Node *&head, int data, int pos)
    {
        Node *newNode = new Node(data);
        if (pos == 1)
        {
            insertAtBeginning(head, data);
            return;
        }
        else
        {
            Node *temp = head;
            int count = 1;
            while (count < pos - 1 && temp->next != NULL)
            {
                temp = temp->next;
                count++;
            }
            if (temp->next == NULL)
            {
                insertAtEnd(head, data);
                return;
            }
            else
            {
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
            }
        }
    }

public:
    // Insert at the beginning of the list
    void defining1(Node *&head)
    {
        int node_num;
        cout << "Enter the number of nodes to be inserted at head: ";
        cin >> node_num;
        for (int i = 0; i < node_num; i++)
        {
            int value;
            cout << "Enter the value of node " << i + 1 << ": ";
            cin >> value;
            insertAtBeginning(head, value);
        }
    }

    // Insert at the end of the list
    void defining2(Node *&head)
    {
        int node_num;
        cout << "Enter the number of nodes to be inserted at end: ";
        cin >> node_num;
        for (int i = 0; i < node_num; i++)
        {
            int value;
            cout << "Enter the value of node " << i + 1 << ": ";
            cin >> value;
            insertAtEnd(head, value);
        }
    }

    // Insert at the middle of the list
    void defining3(Node *&head)
    {
        int node_num, pos;
        cout << "Enter the number of nodes to be inserted at middle: ";
        cin >> node_num;
        cout << "Enter the position where you want to insert the node: ";
        cin >> pos;
        for (int i = 0; i < node_num; i++)
        {
            int value;
            cout << "Enter the value of node " << i + 1 << ": ";
            cin >> value;
            insertAtMiddle(head, value, pos);
        }
    }
};

class deleting
{
public:
    // Delete the first node of the list
    void deletionAtBeginning(Node *&head)
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }
        head = head->next;
        delete temp;
    }

    // Delete the end node of the list
    void deletionAtEnd(Node *&head)
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }
        else if (temp->next == NULL)
        {
            temp = temp->next;
            delete temp;
            head = NULL;
            return;
        }
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // Delete the middle node of the list
    void deletionAtMiddle(Node *&head, int pos)
    {
        if (pos == 1)
        {
            deletionAtBeginning(head);
            return;
        }
        else
        {
            Node *temp = head;
            int count = 1;
            if (temp->next == NULL)
            {
                deletionAtEnd(head);
                return;
            }
            while (count < pos - 1)
            {
                temp = temp->next;
                count++;
            }
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }
};

int main()
{
    Node *head = NULL;
    doublyLinkedList dll;
    dll.populateList(head);
    dll.traversing(head);

    // Inserting nodes at the beginning of the list
    inserting ins;
    ins.defining1(head);
    dll.traversing(head);
    // Inserting nodes at the end of the list
    ins.defining2(head);
    dll.traversing(head);
    // Inserting nodes at the middle of the list
    ins.defining3(head);
    dll.traversing(head);

    // Deleting nodes at the beginning of the list
    deleting del;
    del.deletionAtBeginning(head);
    dll.traversing(head);
    // Deleting nodes at the end of the list
    del.deletionAtEnd(head);
    dll.traversing(head);
    // Deleting nodes at the middle of the list
    int pos;
    cout << "Enter the position of the node to be deleted: ";
    cin >> pos;
    del.deletionAtMiddle(head, pos);
    dll.traversing(head);
    return 0;
}