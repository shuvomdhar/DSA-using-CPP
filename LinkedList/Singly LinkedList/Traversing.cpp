#include <iostream>
using namespace std;

class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node

    // Constructor to initialize a node
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head; // Pointer to the first node of the list

public:
    // Constructor to initialize an empty list
    LinkedList()
    {
        head = nullptr;
    }

    // Function to add a new node at the end of the list
    void addNode(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode; // If the list is empty, make the new node the head
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            { // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode; // Add the new node at the end
        }
    }

    // Function to traverse and display the list
    void traverse()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "Linked List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to populate the list with user input
    void populateList()
    {
        int n, value;
        cout << "Enter the number of nodes: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter value for node " << i + 1 << ": ";
            cin >> value;
            addNode(value);
        }
    }
};

int main()
{
    LinkedList list; // Create a linked list object

    // Populate the list with user input
    list.populateList();

    // Traverse and display the list
    list.traverse();

    return 0;
}
