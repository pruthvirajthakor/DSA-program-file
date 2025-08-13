/* Write a program to implement a doubly linked list in C++.
Perform the following operations:

    1. Create a linked list
    2. Insert elements
    3. Delete node from beginning
    4. Display the list
*/


struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;


void insertNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

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
        newNode->prev = temp;
    }
    cout << "\nNode inserted: " << value;
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        cout << "\nList is empty. Deletion not possible.";
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    cout << "\nNode deleted: " << temp->data;
    delete temp;
}


void displayList()
{
    if (head == NULL)
    {
        cout << "\nList is empty.";
        return;
    }
    Node *temp = head;
    cout << "\nDoubly Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL";
}

void main()
{
    
    int choice, value;
    while (1)
    {
        cout << "\n\n*** DOUBLY LINKED LIST MENU ***";
        cout << "\n1. Insert Node";
        cout << "\n2. Delete Node from Beginning";
        cout << "\n3. Display List";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertNode(value);
            break;

        case 2:
            deleteFromBeginning();
            break;

        case 3:
            displayList();
            break;

        case 4:
            exit(0);

        default:
            cout << "\nInvalid choice!";
        }
    }

}
