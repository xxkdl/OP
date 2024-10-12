#include <iostream>
#include <cmath>
using namespace std;


//1. Знайти значення суми чисел від 1 до 5:
void n1() {
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += i;
    }
    cout << "Сума чисел від 1 до 5: " << sum << endl;
}


//2. Знайти факторіал числа N :
void n2() {
    int N, factorial = 1;
    cout << "Введіть число N: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        factorial *= i;
    }

    cout << "Факторіал числа " << N << ": " << factorial << endl;
}


//3. Знайти суму всіх парних чисел на проміжку від 0 до N :
void n3() {
    int N, sum = 0;
    cout << "Введіть число N: ";
    cin >> N;

    for (int i = 0; i <= N; i += 2) {
        sum += i;
    }

    cout << "Сума всіх парних чисел від 0 до " << N << ": " << sum << endl;
}


//4. Знайти добуток перших n елементів арифметичної прогресії :
void n4() {
    int a1, d, n, product = 1;
    cout << "Введіть перший член прогресії (a1): ";
    cin >> a1;
    cout << "Введіть різницю прогресії (d): ";
    cin >> d;
    cout << "Введіть кількість елементів (n): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        product *= (a1 + i * d);
    }

    cout << "Добуток перших " << n << " елементів прогресії: " << product << endl;
}


//5. Протабулювати функцію f(x) = cos(x) на проміжку від 0 до п з кроком h = 0.01:
void n5() {
    const double pi = 3.141592653589793;
    double h = 0.01;

    for (double x = 0; x <= pi; x += h) {
        cout << "f(" << x << ") = " << cos(x) << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\nВиберіть завдання (1-5, 0 для виходу): ";
        cin >> choice;

        switch (choice) {
        case 1:
            n1();
            break;
        case 2:
            n2();
            break;
        case 3:
            n3();
            break;
        case 4:
            n4();
            break;
        case 5:
            n5();
            break;
        case 0:
            cout << "Вихід." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}