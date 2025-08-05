// Write a program to implement the Double-Ended Queue (Deque) using array and class

class dqueue {
    int q[10], f, r, n;

public:
    dqueue() {
        f = -1;
        r = -1;
        n = 10;
    }

    void dqinsert_left(int data) {
        if (f == 0) {
            cout << "\nDQ is full from left side";
            return;
        }

        if (f == -1) {
            f = n - 1;
            r = n - 1;
        } else {
            f--;
        }

        q[f] = data;
    }

    void dqinsert_right(int data) {
        if (r == n - 1) {
            cout << "\nDQ is full from right side";
            return;
        }

        r++;
        q[r] = data;

        if (f == -1)
            f = 0;
    }

    int dqdelete_left() {
        int data;

        if (f == -1) {
            cout << "\nDQ is underflow";
            return 0;
        }

        data = q[f];
        q[f] = 0;

        if (f == r) {
            f = -1;
            r = -1;
        } else {
            f++;
        }

        return data;
    }

    int dqdelete_right() {
        int data;

        if (r == -1) {
            cout << "\nDQ is underflow";
            return 0;
        }

        data = q[r];
        q[r] = 0;

        if (f == r) {
            f = -1;
            r = -1;
        } else {
            r--;
        }

        return data;
    }

    void display() {
        int i;

        if (f == -1) {
            cout << "\nDQ is empty";
        } else {
            cout << "\nCurrent DQ elements:\n";

            if (f > r) {
                for (i = f; i < n; i++)
                    cout << q[i] << "\t";
                for (i = 0; i <= r; i++)
                    cout << q[i] << "\t";
            } else {
                for (i = f; i <= r; i++)
                    cout << q[i] << "\t";
            }
        }
    }
};

void main() {
   

    int ch, e;
    dqueue dq;

    do {
        cout << "\n\tDouble-Ended Queue (DQ) Implementation";
        cout << "\n\t1. Insert from Left";
        cout << "\n\t2. Insert from Right";
        cout << "\n\t3. Delete from Left";
        cout << "\n\t4. Delete from Right";
        cout << "\n\t5. Display";
        cout << "\n\t6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter element: ";
                cin >> e;
                dq.dqinsert_left(e);
                break;

            case 2:
                cout << "Enter element: ";
                cin >> e;
                dq.dqinsert_right(e);
                break;

            case 3:
                e = dq.dqdelete_left();
                if (e != 0)
                    cout << "\nThe deleted element is: " << e;
                break;

            case 4:
                e = dq.dqdelete_right();
                if (e != 0)
                    cout << "\nThe deleted element is: " << e;
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << "\nBye Bye...";
                break;

            default:
                cout << "\nWrong choice!";
        }

      
    } while (ch != 6);
}

