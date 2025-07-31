// Write a program to implement Stack (Push, Pop, Peep, Display) operations using class and array.

class stack
{
    int n, top;
    int s[20];

public:
    stack()
    {
        n = 5;
        top = -1;
    }

    stack(int no)
    {
        n = no;
        top = -1;
    }

    void push(int data)
    {
        if (top == n - 1)
        {
            cout << "\nStack overflow";
            return;
        }
        top++;
        s[top] = data;
    }

    int pop()
    {
        int data;
        if (top == -1)
        {
            cout << "\nStack underflow";
            return 0;
        }
        data = s[top];
        top--;
        return data;
    }

    int peep()
    {
        int i, data;
        cout << "\nWhich element you want (1 for top, 2 for next...): ";
        cin >> i;
        if ((top - i + 1) < 0)
        {
            cout << "\nStack underflow on peep";
            return 0;
        }
        data = s[top - i + 1];
        return data;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "\nStack is empty";
        }
        else
        {
            cout << "\nThe contents of stack are:\n";
            for (int i = top; i >= 0; i--)
                cout << "\t" << s[i] << "\n";
        }
    }
};

void main()
{
    int e, ch;
    stack s;

    do
    {
        clrscr();
        cout << "\n\t\t-: STACK IMPLEMENTATION :-";
        cout << "\n\t1. Push";
        cout << "\n\t2. Pop";
        cout << "\n\t3. Display";
        cout << "\n\t4. Peep";
        cout << "\n\t5. Exit";
        cout << "\n\n\tEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter element to push: ";
            cin >> e;
            s.push(e);
            break;

        case 2:
            e = s.pop();
            if (e != 0)
                cout << "\nDeleted element is: " << e;
            break;

        case 3:
            s.display();
            break;

        case 4:
            e = s.peep();
            if (e != 0)
                cout << "\nSelected element is: " << e;
            break;

        case 5:
            exit(0);

        default:
            cout << "\nWrong choice!";
        }

      } while (ch != 5);
}
