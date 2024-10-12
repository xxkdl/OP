#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Функція для знаходження мінімального значення у послідовності
void n1(const vector<int>& sequences) {
    int minValue = numeric_limits<int>::max(); // Ініціалізуємо мінімальне значення максимальним можливим значенням
    for (int num : sequences) {
        if (num < minValue) {
            minValue = num;
        }
    }
    cout << "Мінімальне значення: " << minValue << endl;
}

// Функція для знаходження індексу найбільшого додатного елемента
void n2(const vector<int>& sequences) {
    int maxIndex = -1;
    int maxValue = numeric_limits<int>::min();
    for (int i = 0; i < sequences.size(); ++i) {
        if (sequences[i] > 0 && sequences[i] > maxValue) {
            maxValue = sequences[i];
            maxIndex = i;
        }
    }
    if (maxIndex != -1) {
        cout << "Індекс найбільшого додатного елемента: " << maxIndex << endl;
    }
    else {
        cout << "Немає додатних елементів у послідовності." << endl;
    }
}

// Функція для знаходження мінімального значення більшим за P
void n3(const vector<int>& sequences, int P) {
    int minValue = numeric_limits<int>::max();
    for (int num : sequences) {
        if (num > P && num < minValue) {
            minValue = num;
        }
    }
    if (minValue != numeric_limits<int>::max()) {
        cout << "Мінімальне значення більше ніж " << P << ": " << minValue << endl;
    }
    else {
        cout << "Немає значень, більших за " << P << "." << endl;
    }
}

// Функція для знаходження індексу останнього входження P
void n4(const vector<int>& sequences, int P) {
    int lastIndex = -1;
    for (int i = 0; i < sequences.size(); ++i) {
        if (sequences[i] == P) {
            lastIndex = i;
        }
    }
    if (lastIndex != -1) {
        cout << "Останнє входження " << P << " знаходиться на індексі: " << lastIndex << endl;
    }
    else {
        cout << P << " не знайдено у послідовності." << endl;
    }
}

// Функція для знаходження кількості входжень P
void n5(const vector<int>& sequences, int P) {
    int count = 0;
    for (int num : sequences) {
        if (num == P) {
            count++;
        }
    }
    cout << "Кількість входжень " << P << ": " << count << endl;
}

int main() {
    vector<int> sequences;
    int n, choice, P;

    cout << "Введіть кількість елементів у послідовності: ";
    cin >> n;

    cout << "Введіть елементи послідовності: ";
    sequences.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequences[i];
    }

    do {
        cout << "\nВиберіть завдання (1-5, 0 для виходу): ";
        cin >> choice;

        switch (choice) {
        case 1:
            n1(sequences);
            break;
        case 2:
            n2(sequences);
            break;
        case 3:
            cout << "Введіть значення P: ";
            cin >> P;
            n3(sequences, P);
            break;
        case 4:
            cout << "Введіть значення P: ";
            cin >> P;
            n4(sequences, P);
            break;
        case 5:
            cout << "Введіть значення P: ";
            cin >> P;
            n5(sequences, P);
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
