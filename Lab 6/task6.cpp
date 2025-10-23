#include <iostream>
#include <algorithm>
using namespace std;

int const MAX = 10;

class Stack {
public:
    int top;
    char* array;
    Stack() {
        top = -1;
        array = new char[MAX];
    }
    Stack(int val) {
        top = -1;
        array = new char[val];
    }


    bool push(char x);
    char pop();
    char peek();
    bool isEmpty();
};

bool Stack::push(char x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        array[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

char Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        char x = array[top--];
        return x;
    }
}

char Stack::peek() {
    if (top < 0) {
        return 0;
    }
    else {
        char x = array[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}


int precedence(char x) {
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return -1;
}

string infixToPreFix(string infix) {
	reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    string prefix = "";
    Stack s(infix.length());
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c))
            prefix += c;
        else if (c == '(')
            s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                char op = s.pop();
                prefix += op;
            }
            if (s.peek() == '(')
                s.pop();
        }
        else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                char op = s.pop();
                prefix += op;
            }
            s.push(c);
        }

    }
    while (!s.isEmpty()) {
        char op = s.pop();
        prefix += op;
    }

	reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main()
{
    string infix;
    cout << "Enter infix expression (e.g., a+b*(c^d-e)^(f+g*h)-i): ";
    cin >> infix;

    string prefix = infixToPreFix(infix);
    cout << "prefix expression: " << prefix << endl;

    return 0;
}