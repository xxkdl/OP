#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

//1. Максимальне значення за абсолютною величиною

using namespace std;

void n1(const vector<vector<int>>& sequences) {
    int m, n;
    cout << "Введіть кількість послідовностей: ";
    cin >> m;

    vector<vector<int>> A(m);

    // Заповнення колекції послідовностей
    for (int i = 0; i < m; i++) {
        cout << "Введіть кількість елементів у послідовності " << i + 1 << ": ";
        cin >> n;
        A[i].resize(n);
        cout << "Введіть елементи послідовності " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    int maxAbsValue = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            maxAbsValue = max(maxAbsValue, abs(A[i][j]));
        }
    }

    cout << "Максимальне абсолютне значення: " << maxAbsValue << endl;
}



//2. Індекси мінімального значення

void n2(const vector<vector<int>>& sequences) {
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

    int minValue = A[0][0];
    int minIndexM = 0, minIndexN = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] < minValue) {
                minValue = A[i][j];
                minIndexM = i;
                minIndexN = j;
            }
        }
    }
    cout << "Індекси мінімального значення (" << minIndexM << ", " << minIndexN << ")" << endl;
}

//3. Максимальне від’ємне значення

void n3(const vector<vector<int>>& sequences) {
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

    int maxNegValue = -1000000;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] < 0 && A[i][j] > maxNegValue) {
                maxNegValue = A[i][j];
            }
        }
    }

    if (maxNegValue == -1000000) {
        cout << "Негативні значення не знайдено." << endl;
    }
    else {
        cout << "Максимальне негативне значення: " << maxNegValue << endl;
    }
}

//4. Мінімальне додатне значення

void n4(const vector<vector<int>>& sequences) {
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

    int minPosValue = 1000000;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] > 0 && A[i][j] < minPosValue) {
                minPosValue = A[i][j];
            }
        }
    }

    if (minPosValue == 1000000) {
        cout << "Позитивні значення не знайдено." << endl;
    }
    else {
        cout << "Мінімальне позитивне значення: " << minPosValue << endl;
    }

}

// 5. Елементи побічної діагоналі

void n5(const vector<vector<int>>& sequences) {
    int m;
    cout << "Введіть розмір квадратної матриці: ";
    cin >> m;

    vector<vector<int>> A(m, vector<int>(m));

    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int minValue = A[0][m - 1];
    int minIndex = 0;

    for (int i = 1; i < m; i++) {
        if (A[i][m - i - 1] < minValue) {
            minValue = A[i][m - i - 1];
            minIndex = i;
        }
    }

    cout << "Мінімальне значення на побічній діагоналі знаходиться за індексом (" << minIndex + 1 << ", " << (m - minIndex) << ")" << endl;
}

// 6. Останнє входження R

void n6(const vector<vector<int>>& sequences) {
    int m, n, R;
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

    cout << "Введіть значення R: ";
    cin >> R;

    int lastM = -1, lastN = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] == R) {
                lastM = i;
                lastN = j;
            }
        }
    }

    if (lastM == -1) {
        cout << "R не знайдено в масиві." << endl;
    }
    else {
        cout << "Останнє входження R знаходиться в послідовності " << lastM + 1 << ", індекс " << lastN << endl;
    }
}

// 7. Знайти індекси останнього входження R
void n7(const vector<vector<int>>& sequences, int R) {
    int lastM = -1, lastN = -1;

    for (size_t m = 0; m < sequences.size(); ++m) {
        for (size_t n = 0; n < sequences[m].size(); ++n) {
            if (sequences[m][n] == R) {
                lastM = m;
                lastN = n;
            }
        }
    }

    if (lastM == -1) {
        cout << "Значення R не знайдено." << endl;
    }
    else {
        cout << "Останнє входження R: (" << lastM << ", " << lastN << ")" << endl;
    }
}

int main() {
    int choice;
    int m, n;

    cout << "Введіть кількість послідовностей (m): ";
    cin >> m;

    vector<vector<int>> sequences(m);

    for (int i = 0; i < m; ++i) {
        cout << "Введіть кількість елементів для послідовності " << i + 1 << ": ";
        cin >> n;
        sequences[i].resize(n);
        cout << "Введіть елементи послідовності " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> sequences[i][j];
        }
    }

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
            int R;
            cout << "Введіть число R: ";
            cin >> R;
            n7(sequences, R);
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