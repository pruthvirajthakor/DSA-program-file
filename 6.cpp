// Write a program to evaluate given Prefix expression.

class stack {
    int s[10], top;

public:
    stack() {
        top = -1;
    }

    void push(int data) {
        top++;
        s[top] = data;
    }

    int pop() {
        int data;
        data = s[top];
        top--;
        return data;
    }

    void display() {
        cout << "\nEvaluation of Prefix Expression: " << s[top];
    }
};

void main() {
    char pre[50], x[1];
    int l, a, b, rs, i;
    stack s;

    cout << "\nEnter Prefix Expression (no spaces): ";
    cin >> pre;

    l = strlen(pre);
    strrev(pre);

    for (i = 0; i < l; i++) {
        switch (pre[i]) {

            case '^':
                a = s.pop();
                b = s.pop();
                rs = pow(a, b);
                s.push(rs);
                break;

            case '/':
                a = s.pop();
                b = s.pop();
                rs = a / b;
                s.push(rs);
                break;

            case '*':
                a = s.pop();
                b = s.pop();
                rs = a * b;
                s.push(rs);
                break;

            case '+':
                a = s.pop();
                b = s.pop();
                rs = a + b;
                s.push(rs);
                break;

            case '-':
                a = s.pop();
                b = s.pop();
                rs = a - b;
                s.push(rs);
                break;

            default:
                x[0] = pre[i];
                x[1] = '\0';
                a = atoi(x);
                s.push(a);
                break;
        }
    }

    s.display();

}