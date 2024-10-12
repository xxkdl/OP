#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;


// Prioritize actions
int precedence(char st) {
    if (st == '+' || st == '-') return 1;
    if (st == '*' || st == '/') return 2;
    return 0;
}


// Define arithmetic operations
int applyOperation(int n1, int n2, char st) {
    switch (st) {
    case '*':
        return n1 * n2;

    case '/':
        return n1 / n2;

    case '+':
        return n1 + n2;

    case '-':
        return n1 - n2;
    }
}


// Evaluate the expression
int evaluateExpression(const string& expression) {
    stack<int> number; //Stack for storing numbers / operands
    stack<char> oper; //Stack for storing operators

    istringstream iss(expression);
    string token;


    //Ignore spaces
    for (size_t i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') continue;
    }


    // Processing tokens 
    while (iss >> token) {
        if (isdigit(token[0])) {
            number.push(stoi(token));
        }
        else if (token.size() == 1 && strchr("+-*/", token[0])) {
            while (!oper.empty() && precedence(oper.top()) >= precedence(token[0])) {
                int n1 = number.top(); number.pop();
                int n2 = number.top(); number.pop();
                char op = oper.top(); oper.pop();
                number.push(applyOperation(n1, n2, op));
            }
            oper.push(token[0]);
        }
    }

    // Final processing of the remaining operators
    while (!oper.empty()) {
        int n2 = number.top(); number.pop();
        int n1 = number.top(); number.pop();
        char st = oper.top(); oper.pop();
        number.push(applyOperation(n1, n2, st));
    }

    return number.top();
}

// Display on the screen 
int main() {
    string expression;
    cout << "Write your example : ";
    getline(cin, expression);

    try {
        int result = evaluateExpression(expression);
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}