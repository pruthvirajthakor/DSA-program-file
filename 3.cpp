// Write a program to convert given Infix expression into its equivalent Postfix expression.


class Stack {
    char s[50];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char ch) {
        s[++top] = ch;
    }

    char pop() {
        return s[top--];
    }

    char peep() {
        return s[top];
    }

    int isEmpty() {
        return (top == -1);
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void main() {
    

    char in[50];
    Stack s;

    cout << "\n\tINFIX TO POSTFIX CONVERSION\n";
    cout << "\nEnter Infix Expression (no spaces): ";
    cin >> in;

    // add ')' at end
    int l = strlen(in);
    in[l++] = ')';
    in[l] = '\0';

    // push '(' at start
    s.push('(');

    cout << "\nPostfix Expression: ";

    // -------- Conversion Logic --------
    for (int i = 0; i < l; i++) {
        char ch = in[i];

        if (isalnum(ch)) {
            // operand => direct print
            cout << ch << " ";
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (s.peep() != '(')
                cout << s.pop() << " ";
            s.pop(); // remove '('
        }
        else {  
            // operator case
            while (precedence(s.peep()) > precedence(ch) ||
                  (precedence(s.peep()) == precedence(ch) && ch != '^')) {
                cout << s.pop() << " ";
            }
            s.push(ch);
        }
    }


}



}
