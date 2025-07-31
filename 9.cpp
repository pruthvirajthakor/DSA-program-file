// Write a program to implement the Circular Queue using array and class.

class queue {
    int q[10], f, r, n;

public:
    queue() {
        f = -1;
        r = -1;
        n = 10;
    }

    void insert(int data) {
        if ((f == 0 && r == n - 1) || (f == r + 1)) {
            cout << "\n\tCQueue is Overflow";
            return;
        }

        if (r == n - 1)
            r = 0;
        else
            r++;

        q[r] = data;

        if (f == -1)
            f = 0;
    }

    int del() {
        int data;

        if (f == -1) {
            cout << "\n\tCQueue is Underflow";
            return 0;
        }

        data = q[f];

        if (f == r) {
            f = -1;
            r = -1;
        }
        else if (f == n - 1)
            f = 0;
        else
            f++;

        return data;
    }

    void display() {
        int i;

        if (f == -1) {
            cout << "\n\tCQueue is Empty";
        }
        else {
            cout << "\nThe Circular Queue is:\n";

            if (f > r) {
                for (i = f; i < n; i++)
                    cout << q[i] << "\t";
                for (i = 0; i <= r; i++)
                    cout << q[i] << "\t";
            }
            else {
                for (i = f; i <= r; i++)
                    cout << q[i] << "\t";
            }
        }
    }
};

void main() {
    clrscr();

    int e, ch;
    queue q;

    do {
        cout << "\n\t\tCircular Queue Implementation";
        cout << "\n\t1: Insert";
        cout << "\n\t2: Delete";
        cout << "\n\t3: Display";
        cout << "\n\t4: Exit";
        cout << "\n\tEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\n\tEnter the element: ";
                cin >> e;
                q.insert(e);
                break;

            case 2:
                e = q.del();
                if (e != 0)
                    cout << "\n\tThe deleted element is: " << e;
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "\nBye Bye!";
                break;

            default:
                cout << "\nWrong Choice!";
        }

       
    } while (ch != 4);
}
