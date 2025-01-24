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

class CircularLinkedList
{
    void createNode(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head; // Point to itself
            return;
        }
        Node *temp = head;
        while (temp->next != head)
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
        cout << "(head)" << endl;
    }
};

class Inserting
{
    void insertAtBeginning(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head; // Point to itself
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode; // Update head
    }

    void insertAtEnd(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head; // Point to itself
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Complete the circular link
    }

    void insertAtPosition(Node *&head, int data, int pos)
    {
        Node *newNode = new Node(data);
        if (pos == 1) // Insert at the beginning
        {
            insertAtBeginning(head, data);
            return;
        }
        Node *temp = head;
        int count = 1;
        // Traverse until the position is reached or end of the circular list
        while (count < pos - 1 && temp->next != head)
        {
            temp = temp->next;
            count++;
        }
        if (temp->next == head) // If position is at the end
        {
            insertAtEnd(head, data);
            return;
        }
        // Insert at the specific position
        newNode->next = temp->next;
        temp->next = newNode;
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
        cout << "Enter the position of the node to be inserted: ";
        cin >> pos;
        for (int i = 0; i < node_num; i++)
        {
            int value;
            cout << "Enter the value of node " << i + 1 << ": ";
            cin >> value;
            insertAtPosition(head, value, pos);
        }
    }
};

class Deleting
{
public:
    void deleteAtBeginning(Node *&head)
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        else if (head->next == head)
        {
            delete head; // Only one node
            head = NULL;
            return;
        }
        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd(Node *&head)
    {
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        Node *temp = head;
        if (head->next == head)
        {
            delete head; // Only one node
            head = NULL;
            return;
        }
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }

    void deleteAtPosition(Node *&head, int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (pos == 1)
        {
            deleteAtBeginning(head);
            return;
        }
        Node *temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head)
        {
            temp = temp->next;
            count++;
        }
        if (temp->next == head)
        {
            cout << "Position out of range. Cannot delete." << endl;
            return;
        }
        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
};

int main()
{
    Node *head = NULL;
    CircularLinkedList cll;
    cll.populateList(head);
    cll.traversing(head);

    // Insert at the beginning of the list
    Inserting ins;
    ins.defining1(head);
    cll.traversing(head);
    // Insert at the end of the list
    ins.defining2(head);
    cll.traversing(head);
    // Insert at the middle of the list
    ins.defining3(head);
    cll.traversing(head);

    // Delete at the beginning of the list
    Deleting del;
    del.deleteAtBeginning(head);
    cll.traversing(head);
    // Delete at the end of the list
    del.deleteAtEnd(head);
    cll.traversing(head);
    // Delete at the middle of the list
    int pos;
    cout << "Enter the position to delete: ";
    cin >> pos;
    del.deleteAtPosition(head, pos);
    cll.traversing(head);

    return 0;
}
