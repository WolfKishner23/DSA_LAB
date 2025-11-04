#include <bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

int precedence(char token) {
    if(token == '+' || token == '-') return 1;
    else if(token == '*' || token == '/') return 2;
    else if(token == '^') return 3;
    return -1;
}

string infixToPostFix(string expr) {
    stack<char> s;
    string output = "";

    for(int i=0; i<expr.length(); i++){
        char token = expr[i];

        if(isalnum(token)){
            output += token;
        }
        else if(token=='('){
            s.push(token);
        }
        else if(token==')'){
            while(!s.empty() && s.top() != '('){
                output += s.top();
                s.pop();
            }
            if(!s.empty() && s.top()=='('){
                s.pop();
            }
        }
        else if(isOperator(token)){
            while(!s.empty() && 
                  ((precedence(s.top()) > precedence(token)) || 
                   (precedence(s.top()) == precedence(token) && token != '^'))){
                output += s.top();
                s.pop();
            }
            s.push(token);
        }
    }

    while(!s.empty()){
        output += s.top();
        s.pop();
    }

    return output;
}


string infixToPrefix(string expr) {
    reverse(expr.begin(), expr.end());

    for(int i=0; i<expr.length(); i++){
        if(expr[i] == '(') expr[i] = ')';
        else if(expr[i] == ')') expr[i] = '(';
    }

    string postfix = infixToPostFix(expr);

    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int applyOp(int a, int b, char op) {
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '^': return pow(a,b);
    }
    return 0;
}

int evaluatePostfix(string expr) {
    stack<int> s;
    for(int i=0; i<expr.length(); i++){
        char token = expr[i];

        if(isdigit(token)){
            s.push(token - '0');  
        }
        else if(isOperator(token)){
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            int result = applyOp(op1, op2, token);
            s.push(result);
        }
    }
    return s.top();
}

int evaluatePrefix(string expr) {
    stack<int> s;
    for(int i=expr.length()-1; i>=0; i--){
        char token = expr[i];

        if(isdigit(token)){
            s.push(token - '0');  
        }
        else if(isOperator(token)){
            int op1 = s.top(); 
                      s.pop();

            int op2 = s.top(); 
                      s.pop();
                      
            int result = applyOp(op1, op2, token);
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    int choice;
    string expr;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Evaluate Prefix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Infix Expression: ";
                cin >> expr;
                cout << "Postfix: " << infixToPostFix(expr) << endl;
                break;

            case 2:
                cout << "Enter Infix Expression: ";
                cin >> expr;
                cout << "Prefix: " << infixToPrefix(expr) << endl;
                break;

            case 3:
                cout << "Enter Postfix Expression: ";
                cin >> expr;
                cout << "Evaluation Result: " << evaluatePostfix(expr) << endl;
                break;

            case 4:
                cout << "Enter Prefix Expression: ";
                cin >> expr;
                cout << "Evaluation Result: " << evaluatePrefix(expr) << endl;
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 5);

    return 0;
}
