#include <iostream>
using namespace std;


// 1. Задано ціле число А. Якщо А – додатне число, то додати до нього 1, в іншому випадку відняти від нього 2.
void n1() {
    int A;
    cout << "Введіть число A: ";
    cin >> A;

    if (A > 0) {
        A += 1;
    }
    else {
        A -= 2;
    }
    cout << "Результат 1: " << A << endl;
}

// 2. Задано два значення А і В. Визначити, чи А дорівнює В.
void n2() {
    int A, B;
    cout << "Введіть число A: ";
    cin >> A;
    cout << "Введіть число B: ";
    cin >> B;

    if (A == B) {
        cout << "A дорівнює B" << endl;
    }
    else {
        cout << "A не дорівнює B" << endl;
    }
}

// 3. Задано два значення А і В. Якщо значення не є рівними, присвоїти А значення В.
void n3() {
    int A, B;
    cout << "Введіть число A: ";
    cin >> A;
    cout << "Введіть число B: ";
    cin >> B;

    if (A != B) {
        A = B;
        cout << "Тепер A дорівнює B: A = " << A << endl;
    }
}

// 4. Задано два нерівних значення А і В. Відняти від більшого числа менше.
void n4() {
    int A, B;
    cout << "Введіть число A: ";
    cin >> A;
    cout << "Введіть число B: ";
    cin >> B;

    if (A != B) {
        if (A > B) {
            A -= B;
        }
        else {
            B -= A;
        }
        cout << "Результат 4: більше мінус менше = " << (A > B ? A : B) << endl;
    }
    else {
        cout << "Числа A та B повинні бути різними." << endl;
    }
}

// 5. Задано число А. Знайти абсолютне значення А (не використовуючи операцію модуля числа).
void n5() {
    int A;
    cout << "Введіть число A: ";
    cin >> A;

    int absValue;
    if (A >= 0) {
        absValue = A;
    }
    else {
        absValue = -A;
    }
    cout << "Абсолютне значення A: " << absValue << endl;
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