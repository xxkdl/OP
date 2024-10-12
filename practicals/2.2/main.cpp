#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

// 1. Замінити у B[m] входження значень із A[n] на середнє значення A[n]
void n1(const vector<vector<int>>& sequences) {
    int n, m;
    cout << "Введіть розмір послідовності A: ";
    cin >> n;
    vector<int> A(n);
    cout << "Введіть елементи A: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Введіть розмір послідовності B: ";
    cin >> m;
    vector<int> B(m);
    cout << "Введіть елементи B: ";
    for (int i = 0; i < m; i++) cin >> B[i];

    // Обчислюємо середнє значення A
    int sumA = 0;
    for (int i = 0; i < n; i++) sumA += A[i];
    double avgA = sumA / double(n);

    // Замінюємо в B всі входження елементів із A на середнє A
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (B[i] == A[j]) {
                B[i] = avgA;
            }
        }
    }

    cout << "Модифікована послідовність B: ";
    for (int i = 0; i < m; i++) cout << B[i] << " ";
    cout << endl;
}

// 2. Замінити мінімальні значення в кожній послідовності на суму її елементів
void n2(const vector<vector<int>>& sequences) {
    int m, n;
    cout << "Введіть кількість послідовностей: ";
    cin >> m;

    vector<vector<int>> A(m);

    // Заповнюємо множину послідовностей
    for (int i = 0; i < m; i++) {
        cout << "Введіть кількість елементів у послідовності " << i + 1 << ": ";
        cin >> n;
        A[i].resize(n);
        cout << "Введіть елементи послідовності " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Замінюємо мінімальні значення на суму елементів послідовності
    for (int i = 0; i < m; i++) {
        int sum = 0, minVal = A[i][0];
        for (int j = 0; j < A[i].size(); j++) {
            sum += A[i][j];
            if (A[i][j] < minVal) {
                minVal = A[i][j];
            }
        }
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] == minVal) {
                A[i][j] = sum;
            }
        }
    }

    // Виводимо результат
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// 3. Замінити в A[n] входження значень із B[m] на добуток B[m]
void n3(const vector<vector<int>>& sequences) {
    int n, m;
    cout << "Введіть розмір послідовності A: ";
    cin >> n;
    vector<int> A(n);
    cout << "Введіть елементи A: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Введіть розмір послідовності B: ";
    cin >> m;
    vector<int> B(m);
    cout << "Введіть елементи B: ";
    for (int i = 0; i < m; i++) cin >> B[i];

    // Обчислюємо добуток елементів B
    int productB = 1;
    for (int i = 0; i < m; i++) productB *= B[i];

    // Замінюємо входження елементів із B у A на добуток B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                A[i] = productB;
            }
        }
    }

    cout << "Модифікована послідовність A: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
}

// 4. Замінити в кожному стовпці множини A[m, m] максимальні значення на добуток елементів цього стовпця
void n4(const vector<vector<int>>& sequences) {
    int m;
    cout << "Введіть розмір квадратної матриці A (m x m): ";
    cin >> m;

    vector<vector<int>> A(m, vector<int>(m));
    cout << "Введіть елементи матриці A:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // Замінюємо максимальні значення в кожному стовпці на добуток елементів цього стовпця
    for (int j = 0; j < m; j++) {
        int maxVal = A[0][j];
        int product = 1;
        for (int i = 0; i < m; i++) {
            if (A[i][j] > maxVal) {
                maxVal = A[i][j];
            }
            product *= A[i][j];
        }
        for (int i = 0; i < m; i++) {
            if (A[i][j] == maxVal) {
                A[i][j] = product;
            }
        }
    }

    cout << "Модифікована матриця A:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// 5. Замінити в A[n] всі від’ємні значення на максимальні значення із підпослідовності B[m]
void n5(const vector<vector<int>>& sequences) {
    int n, m;
    cout << "Введіть розмір послідовності A: ";
    cin >> n;
    vector<int> A(n);
    cout << "Введіть елементи A: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Введіть розмір послідовності B: ";
    cin >> m;
    vector<int> B(m);
    cout << "Введіть елементи B: ";
    for (int i = 0; i < m; i++) cin >> B[i];

    // Знаходимо максимальне значення з B
    int maxB = B[0];
    for (int i = 1; i < m; i++) {
        if (B[i] > maxB) maxB = B[i];
    }

    // Замінюємо всі від'ємні значення в A на maxB
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) A[i] = maxB;
    }

    cout << "Модифікована послідовність A: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
}

// 6. Замінити в кожній послідовності A[i] від’ємні значення на суму додатних елементів цієї послідовності
void n6(const vector<vector<int>>& sequences) {
    int m, n;
    cout << "Введіть кількість послідовностей: ";
    cin >> m;

    vector<vector<int>> A(m);

    for (int i = 0; i < m; i++) {
        cout << "Введіть кількість елементів у послідовності " << i + 1 << ": ";
        cin >> n;
        A[i].resize(n);
        cout << "Введіть елементи послідовності " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Замінюємо від'ємні значення на суму додатних елементів
    for (int i = 0; i < m; i++) {
        int positiveSum = 0;
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] > 0) positiveSum += A[i][j];
        }

        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] < 0) A[i][j] = positiveSum;
        }
    }

    cout << "Модифіковані послідовності: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// 7. Замінити в B[m] всі додатні значення мінімальним значенням із підпослідовності A[n]
void n7(const vector<vector<int>>& sequences) {
    int n, m;
    cout << "Введіть розмір послідовності A: ";
    cin >> n;
    vector<int> A(n);
    cout << "Введіть елементи A: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Введіть розмір послідовності B: ";
    cin >> m;
    vector<int> B(m);
    cout << "Введіть елементи B: ";
    for (int i = 0; i < m; i++) cin >> B[i];

    // Знаходимо мінімальне значення з A
    int minA = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] < minA) minA = A[i];
    }

    // Замінюємо всі додатні значення в B на minA
    for (int i = 0; i < m; i++) {
        if (B[i] > 0) B[i] = minA;
    }

    cout << "Модифікована послідовність B: ";
    for (int i = 0; i < m; i++) cout << B[i] << " ";
    cout << endl;
}

int main() {
    int choice;
    int m;
    vector<vector<int>> sequences(m);
    do {
        cout << "\nВиберіть завдання (1-7, 0 для виходу): ";
        cin >> choice;

        switch (choice) {
        case 1:
            n1(sequences);
            break;
        case 2:
            n2(sequences);
            break;
        case 3:
            n3(sequences);
            break;
        case 4:
            n4(sequences);
            break;
        case 5:
            n5(sequences);
            break;
        case 6:
            n6(sequences);
            break;
        case 7: {
            n7(sequences);
            break;
        }
        case 0:
            cout << "Вихід." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}
