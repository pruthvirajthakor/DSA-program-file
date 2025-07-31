// Write a program to implement the Tower of Hanoi using recursion.

class toh {
    int n;
    char a, b, c;

public:
    toh() { }

    toh(int no, char t1, char t3, char t2) {
        n = no;
        a = t1;
        b = t2;
        c = t3;
    }

    void tower(int n, char a, char b, char c) {
        if (n == 1) {
            cout << "\nMove disk 1 from peg " << a << " to " << c;
            return;
        }

        tower(n - 1, a, c, b);
        cout << "\nMove disk " << n << " from peg " << a << " to " << c;
        tower(n - 1, b, a, c);
    }

    void tower() {
        tower(n, a, b, c);
    }
};

void main() {
    clrscr();

    int n;
    cout << "\t\t\tTOWER OF HANOI\n\n";
    cout << "Enter the value of n: ";
    cin >> n;

    toh t(n, 'A', 'C', 'B');
    t.tower();

    
}
