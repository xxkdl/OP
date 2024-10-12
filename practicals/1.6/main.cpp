#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


void n1() {
    int A, B;
    cout << "Введіть два цілі числа A і B: ";
    cin >> A >> B;

    if (A == B) {
        cout << "A дорівнює B." << endl;
    }
    else {
        cout << "A не дорівнює B." << endl;
    }
}

void n2() {
    int A;
    cout << "Введіть ціле число A: ";
    cin >> A;

    if ((A & 7) == 0) {
        cout << "A є кратним 8." << endl;
    }
    else {
        cout << "A не є кратним 8." << endl;
    }
}

void n3() {
    string seq1, seq2;
    cout << "Введіть першу послідовність (наприклад, 101): ";
    cin >> seq1;
    cout << "Введіть другу послідовність (наприклад, 110): ";
    cin >> seq2;

    cout << "Результат AND: ";
    for (size_t i = 0; i < seq1.size(); ++i) {
        cout << ((seq1[i] - '0') & (seq2[i] - '0'));
    }
    cout << endl;

    cout << "Результат OR: ";
    for (size_t i = 0; i < seq1.size(); ++i) {
        cout << ((seq1[i] - '0') | (seq2[i] - '0'));
    }
    cout << endl;

    cout << "Результат XOR: ";
    for (size_t i = 0; i < seq1.size(); ++i) {
        cout << ((seq1[i] - '0') ^ (seq2[i] - '0'));
    }
    cout << endl;
}

void n4() {
    string seq1, seq2;
    cout << "Введіть першу послідовність (наприклад, 101): ";
    cin >> seq1;
    cout << "Введіть другу послідовність (наприклад, 110): ";
    cin >> seq2;

    cout << "Результат (додавання): ";
    for (size_t i = 0; i < seq1.size(); ++i) {
        cout << ((seq1[i] - '0') + (seq2[i] - '0')) % 2;
    }
    cout << endl;

    cout << "Результат NOT: ";
    for (char bit : seq1) {
        cout << (bit == '0' ? '1' : '0');
    }
    cout << endl;
}

void n5() {
    int A, B;
    cout << "Введіть два цілі числа A і B: ";
    cin >> A >> B;

    int carry;
    while (B != 0) {
        carry = A & B;  // Зберігаємо перенесення
        A = A ^ B;      // Додаємо без перенесення
        B = carry << 1; // Переносимо
    }
    cout << "Сума A і B: " << A << endl;
}

void n6() {
    int n;
    cout << "Введіть натуральне число: ";
    cin >> n;

    vector<int> sequence;
    cout << "Введіть послідовність (0 або 1): ";
    for (int i = 0; i < n; ++i) {
        int bit;
        cin >> bit;
        sequence.push_back(bit);
    }

    cout << "Зсув вліво: ";
    for (int i = 1; i < sequence.size(); ++i) {
        cout << sequence[i];
    }
    cout << "0" << endl; // Додаємо 0 в кінці

    cout << "Зсув вправо: 0"; // Витісняємо перший елемент
    for (int i = 0; i < sequence.size() - 1; ++i) {
        cout << sequence[i];
    }
    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "\nВиберіть завдання (1-7, 0 для виходу): ";
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
        case 6:
            n6();
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
