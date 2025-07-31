// Write a program to evaluate given Postfix expression.

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
        cout << "\nEvaluation of Postfix Expression: " << s[top];
    }
};

void main() {


    char post[50], x[1];
    int l, a, b, rs, i;
    stack s;

    cout << "\nEnter Postfix Expression: ";
    cin >> post;

    l = strlen(post);

    for (i = 0; i < l; i++) {
        switch (post[i]) {

            case '^':
                a = s.pop();
                b = s.pop();
                rs = pow(b, a);
                s.push(rs);
                break;

            case '/':
                a = s.pop();
                b = s.pop();
                rs = b / a;
                s.push(rs);
                break;

            case '*':
                a = s.pop();
                b = s.pop();
                rs = b * a;
                s.push(rs);
                break;

            case '+':
                a = s.pop();
                b = s.pop();
                rs = b + a;
                s.push(rs);
                break;

            case '-':
                a = s.pop();
                b = s.pop();
                rs = b - a;
                s.push(rs);
                break;

            default:
                x[0] = post[i];
                x[1] = '\0';
                a = atoi(x);
                s.push(a);
                break;
        }
    }

    s.display();
 
}
