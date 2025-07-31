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
        return top == -1;
    }
};

void main() {
   

    char in[50];
    Stack s;

    cout << "\n\tINFIX TO POSTFIX CONVERSION\n";
    cout << "\nEnter Infix Expression (no spaces): ";
    cin >> in;

    int l = strlen(in);
    in[l++] = ')';
    in[l] = '\0';
    s.push('(');

    cout << "\nPostfix Expression: ";

    for (int i = 0; i < l; i++) {
        char ch = in[i];

        if (isalnum(ch)) {
            cout << ch << " ";
        } else {
            switch (ch) {
                case '(':
                    s.push(ch);
                    break;

                case '^':
                    while (s.peep() == '^')
                        cout << s.pop() << " ";
                    s.push(ch);
                    break;

                case '*':
                case '/':
                case '+':
                case '-':
                    while (strchr("^/*+-", s.peep()))
                        cout << s.pop() << " ";
                    s.push(ch);
                    break;

                case ')':
                    while (s.peep() != '(')
                        cout << s.pop() << " ";
                    s.pop(); // remove '('
                    break;
            }
        }
    }


}