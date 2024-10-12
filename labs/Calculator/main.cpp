#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;


//Визначаємо приоритетн?сть д?й
int precedence(char st) {
    if (st == '+' || st == '-') return 1;
    if (st == '*' || st == '/') return 2;
    return 0;
}


//Задаємо арифметичн? операц?ї
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


// Оц?нюмо вираження
int evaluateExpression(const string& expression) {
    stack<int> number; //Стек для збер?гання чисел / операнд?в
    stack<char> oper; //Стек для збер?гання оператор?в

    istringstream iss(expression);
    string token;


    //?гноруємо проб?ли
    for (size_t i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') continue;
    }


    // Обробка токен?в 
    while (iss >> token) {
        if (isdigit(token[0])) {
            number.push(stoi(token));
        }
        else if (token.size() == 1 && strchr("+-*/", token[0])) {
            while (!oper.empty() && precedence(oper.top()) >= precedence(token[0])) {
                int n1 = number.top(); number.pop();
                int n2 = number.top(); number.pop();
                char o1 = oper.top(); oper.pop();
                number.push(applyOperation(n1, n2, o1));
            }
            oper.push(token[0]);
        }
    }

    // Остаточне опрацювання оператор?в, що залишилися
    while (!oper.empty()) {
        int n2 = number.top(); number.pop();
        int n1 = number.top(); number.pop();
        char o2 = oper.top(); oper.pop();
        number.push(applyOperation(n1, n2, o2));
    }

    return number.top();
}

// Вивод на єкран 
int main() {
    setlocale(LC_ALL, "ukr");
    string expression;
    cout << "Напиш?ть ваш приклад: ";
    getline(cin, expression);

    try {
        int result = evaluateExpression(expression);
        cout << "В?дпов?дь: " << result << endl;
    }
    catch (const runtime_error& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
} 