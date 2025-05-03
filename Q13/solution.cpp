// Implementation of Infix to Postfix conversion and implementation

#include <iostream>
#include <cctype>  
#include <cmath>  
#include <string>  
#include "stack_sll.h"

using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
string infixToPostfix(string infix) {
    stack_sll s;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } 
        else if (ch == '(') {
            s.push(ch);
        } 
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop();
        } 
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}
int evaluatePostfix(string postfix) {
    stack_sll s;

    for (char ch : postfix) {
        if (isdigit(ch)) { 
            s.push(ch - '0'); 
        } 
        else { 
            int operand2 = s.pop();
            int operand1 = s.pop();

            switch (ch) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
                case '^': s.push(pow(operand1, operand2)); break;
            }
        }
    }
    return s.pop();
}
int main() {
    int choice;
    string infix, postfix;

    do {
        cout << "\nMENU\n";
        cout << "1. Enter Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                getline(cin, infix);
                break;
            case 2:
                if (infix.empty()) {
                    cout << "Please enter an infix expression first.\n";
                } else {
                    postfix = infixToPostfix(infix);
                    cout << "Postfix Expression: " << postfix << endl;
                }
                break;
            case 3:
                if (postfix.empty()) {
                    cout << "Please convert an infix expression first.\n";
                } else {
                    int result = evaluatePostfix(postfix);
                    cout << "Evaluation Result: " << result << endl;
                }
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
