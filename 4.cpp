// Write a program to convert given Infix expression into its equivalent Prefix expression.

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
   

    char in[50], pre[50];
    Stack s;
    int j = 0;

    cout << "\n\tINFIX TO PREFIX CONVERSION\n";
    cout << "\nEnter Infix Expression (no spaces): ";
    cin >> in;

    int l = strlen(in);
    strrev(in);          
    s.push('(');         
    in[l++] = ')';       
    in[l] = '\0';        

    for (int i = 0; i < l; i++) {
        char ch = in[i];

        if (isalnum(ch)) {
            pre[j++] = ch;
        } 
        else {
            switch (ch) {

                case ')':
                    s.push(ch);
                    break;

                case '^':
                    while (s.peep() == '^')
                        pre[j++] = s.pop();
                    s.push(ch);
                    break;

                case '/':
                case '*':
                case '+':
                case '-':
                    while (strchr("^/*+-", s.peep()))
                        pre[j++] = s.pop();
                    s.push(ch);
                    break;

                case '(':
                    while (s.peep() != ')')
                        pre[j++] = s.pop();
                    s.pop();  
                    break;
            }
        }
    }

    while (s.peep() != '(')
        pre[j++] = s.pop();

    pre[j] = '\0';
    strrev(pre);

    cout << "\nPrefix Expression: " << pre;
   
}