#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

void insertAtHead(Node *&head, Node *&tail, int data)
{

    if (head == NULL && tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPos(Node *&head, Node *&tail, int data, int pos)
{
    Node *prev = NULL;
    Node *curr = head;

    if (pos == 1)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;

        if (tail == NULL)
            tail = newNode;
        return;
    }

    int count = 1;

    while (count < pos && curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    Node *newNode = new Node(data);
    prev->next = newNode;
    newNode->next = curr;
}

int findLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void deletion(Node *&head, Node *&tail, int pos)
{

    int length = findLength(head);
    int count = 0;

    if (head == NULL)
    {
        cout << "Linked list is empty.\n";
        return;
    }

    else if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    else if (pos == length)
    {
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;

        tail = temp;
        temp->next = NULL;
    }

    else
    {
        Node *prev = NULL;
        Node *curr = head;

        if (pos == 0)
        {
            head = curr->next;
            delete curr;
            return;
        }

        while (count < pos && curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtTail(head, tail, 50);
    insertAtPos(head, tail, 60, 2);
    printLL(head);
    cout << endl;
    deletion(head, tail, 2);
    printLL(head);

    return 0;
}