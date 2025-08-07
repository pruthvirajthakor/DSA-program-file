struct Node {
    int data;
    Node *next;
};

class LinkedList {
    Node *head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "\nList is empty!";
        } else {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "\nDeleted node from beginning.";
        }
    }

    void display() {
        if (head == NULL) {
            cout << "\nList is empty!";
        } else {
            Node *temp = head;
            cout << "\nLinked List: ";
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL";
        }
    }
};

void main() {
   
    LinkedList list;
    int choice, val;

    while (1) {
        cout << "\n\n1. Insert\n2. Delete from Beginning\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAtEnd(val);
                break;

            case 2:
                list.deleteFromBeginning();
                break;

            case 3:
                list.display();
                break;

            case 4:
                exit(0);

            default:
                cout << "Invalid choice!";
        }
    }

    
}