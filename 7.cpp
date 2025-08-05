// Write a program to implement the Tower of Hanoi using recursion.

class toh {
    int n;
    char a, b, c;
public:
    toh() {
    }

    toh(int no, char t1, char t3, char t2) {
        n = no;
        a = t1;
        b = t2;
        c = t3;
    }

    void tower(int n, char a, char c, char b) {
        if (n == 1) {
            cout << "\n Disk 1 moved from Tower " << a << " to Tower " << c;
            return;
        }
        tower(n - 1, a, b, c);
        cout << "\n Disk " << n << " moved from Tower " << a << " to Tower " << c;
        tower(n - 1, b, c, a);
    }

    void start() {
	tower(n, a, c, b);
    }
};

int main() {
    int n;
    clrscr();
    cout << "\t\t\t TOWER OF HANOI \n\n";
    cout << "Enter the value of n : ";
    cin >> n;
    toh t(n, 'A', 'C', 'B');
    t.start(); // Call the correct function
}
