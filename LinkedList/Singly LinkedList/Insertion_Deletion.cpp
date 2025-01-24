#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
protected:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Destructor to free allocated memory
    ~LinkedList()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            delete temp; // Free memory of the node
        }
        head = NULL;
        cout << "Memory freed and LinkedList destroyed." << endl;
    }

    void addNode(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void populateList()
    {
        int num;
        cout << "Enter how many nodes are there in the list: ";
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int value;
            cout << "Enter the value of node " << i + 1 << ": ";
            cin >> value;
            addNode(value);
        }
    }

    void traversing()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "Linked List: ";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl
             << endl;
    }

    // Insertion at the head of the LinkedList
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void defining1()
    {
        int node_num;
        cout << "Enter the number of nodes to be inserted at head: ";
        cin >> node_num;
        for (int i = 0; i < node_num; i++)
        {
            int value;
            cout << "Enter the value of node " << i + 1 << ": ";
            cin >> value;
            insertAtBeginning(value);
        }
    }

    // Insertion at the end of the LinkedList
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void defining2()
    {
        int node_num;
        cout << "Enter the number of nodes to be inserted at end: ";
        cin >> node_num;
        for (int i = 0; i < node_num; i++)
        {
            int value;
            cout << "Enter the value of node " << i + 1 << ": ";
            cin >> value;
            insertAtEnd(value);
        }
    }

    // Insertion in the middle of the LinkedList
    void insertAtMiddle(int value, int pos)
    {
        if (pos == 1)
        {
            insertAtBeginning(value);
            return;
        }
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            int count = 1;
            while (count < pos - 1)
            {
                temp = temp->next;
                count += 1;
            }
            if (temp->next == NULL)
            {
                insertAtEnd(value);
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void defining3()
    {
        int pos;
        cout << "Enter the position where you want to insert the node: ";
        cin >> pos;
        int node_num;
        cout << "Enter the number of nodes to be inserted at middle: ";
        cin >> node_num;
        for (int i = 0; i < node_num; i++)
        {
            int value;
            cout << "Enter the value of node " << i + 1 << ": ";
            cin >> value;
            insertAtMiddle(value, pos);
        }
    }

    // Deletion at the head of the LinkedList
    void deletionAtBeginning()
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }
        else if (temp->next == NULL)
        {
            delete temp;
            head = NULL;
            return;
        }
        else
        {
            head = temp->next;
            delete temp;
            return;
        }
    }

    // Deletion at the end of the LinkedList
    void deletionAtEnd()
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }
        if (temp->next == NULL)
        {
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
        return;
    }

    // Deletion in the middle of the LinkedList
    void deletionAtMiddle(int pos)
    {
        if (pos == 1)
        {
            deletionAtBeginning();
            return;
        }
        else
        {
            Node *temp = head;
            if (temp->next == NULL)
            {
                deletionAtEnd();
                return;
            }
            int count = 1;
            while (count < pos - 1)
            {
                temp = temp->next;
                count += 1;
            }
            Node *nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
            return;
        }
    }
};

int main()
{
    LinkedList list;
    list.populateList();
    cout << "LinkedList before insertion :-" << endl;
    list.traversing();

    // Inserting nodes at the head of the LinkedList
    cout << "Insertion at the head ~ " << endl;
    list.defining1();
    cout << "LinkedList after insertion at the head :- " << endl;
    list.traversing();

    // Inserting nodes at the end of the LinkedList
    cout << "Insertion at the end ~ " << endl;
    list.defining2();
    cout << "LinkedList after insertion at the end :- " << endl;
    list.traversing();

    // Inserting nodes at the middle of the LinkedList
    cout << "Insertion at the middle ~ " << endl;
    list.defining3();
    cout << "LinkedList after insertion at the middle :- " << endl;
    list.traversing();

    // Deletion nodes at the head of the LinkedList
    cout << "Deletion at the head ~ " << endl;
    list.deletionAtBeginning();
    cout << "LinkedList after deletion at the head :- " << endl;
    list.traversing();

    // Deletion nodes at the end of the LinkedList
    cout << "Deletion at the end ~ " << endl;
    list.deletionAtEnd();
    cout << "LinkedList after deletion at the end :- " << endl;
    list.traversing();

    // Deletion nodes at the middle of the LinkedList
    cout << "Deletion at the middle ~ " << endl;
    int pos;
    cout << "Enter the position of the node to be deleted: ";
    cin >> pos;
    list.deletionAtMiddle(pos);
    cout << "LinkedList after deletion at the middle :- " << endl;
    list.traversing();

    return 0;
}