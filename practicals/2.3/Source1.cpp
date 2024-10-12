#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

// 1. ?¤? ?£÷ÿ¢ð ô?¡??ý?÷??¡¢¬ ôÿ ?ð¥ §ð¡?? ¢ÿ ÷?ý¡? ¢£÷ÿ¢ð åå ?ÿ ? ?¡¢ÿ??¯? ?ÿ ý?ô?????® ÿ??? ð¢?£ ö£?¬öÿ¨òð.
void n1(vector<int>& B) {
    for (int i = 0; i < B.size() - 1; i++) {
        for (int j = 0; j < B.size() - i - 1; j++) {
            if (B[j] > B[j + 1]) {
                swap(B[j], B[j + 1]);
            }
        }
    }
}

// 2. ?¤? ?£÷ÿ¢ð ô?¡??ý?÷??¡¢¬ ÷?ý?ã??ð¥ §ð¡?? ¢ÿ ÷?ý¡? ¢£÷ÿ¢ð åå ?ÿ ¡ôÿýÿ??¯? ÿ??? ð¢??? ÷ðö? òð.
void n2(vector<int>& B) {
    for (int i = 0; i < B.size() - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < B.size(); j++) {
            if (B[j] > B[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(B[i], B[maxIndex]);
    }
}

// 3. ??ý¡? ¢£÷ÿ¢ð ò???£ ô?¡??ý?÷??¡¢¬ ÷ ????ð?? ?ÿ ? ?¡¢ÿ??¯? ?ÿ ý?ô?????® ÿ??? ð¢?£ ö£?¬öÿ¨òð.
void n3(vector<int>& seq) {
    for (int i = 0; i < seq.size() - 1; i++) {
        for (int j = 0; j < seq.size() - i - 1; j++) {
            if (seq[j] > seq[j + 1]) {
                swap(seq[j], seq[j + 1]);
            }
        }
    }
}

// 4. ?¤? ?£÷ÿ¢ð ??÷£ ô?¡??ý?÷??¡¢¬ ? ?ÿò¡ð?ÿ?¬?ð¥ ??????¢?÷ ò????å ô?¡??ý?÷??¡¢? ¢ÿ ÷?ý¡? ¢£÷ÿ¢ð åå ?ÿ ¡ôÿýÿ??¯? ?ÿ ý?ô?????® ÿ??? ð¢?£ ÷ðö? òð.
void n4(vector<int>& B) {
    for (int i = 0; i < B.size() - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < B.size(); j++) {
            if (B[j] > B[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(B[i], B[maxIndex]);
    }
}

// 5. ??ý¡? ¢£÷ÿ¢ð ??????¢ð ????÷??å ý?ÿ???ÿ?? ò÷ÿý ÿ¢??å ?ÿ¢ ð¦? ?ÿ ? ?¡¢ÿ??¯? ÿ??? ð¢??? ÷ðö? òð.
void n5(vector<int>& diag) {
    for (int i = 0; i < diag.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < diag.size(); j++) {
            if (diag[j] < diag[minIndex]) {
                minIndex = j;
            }
        }
        swap(diag[i], diag[minIndex]);
    }
}

// 6. ??ý¡? ¢£÷ÿ¢ð ò???? ¡¢?÷ô?¦¬ ?ÿ¢ ð¦? ?ÿ ¡ôÿýÿ??¯? ?ÿ ý?ô?????® ÿ??? ð¢?£ ö£?¬öÿ¨òð.
void n6(vector<vector<int>>& A, int m, int col) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (A[j][col] < A[j + 1][col]) {
                swap(A[j][col], A[j + 1][col]);
            }
        }
    }
}

// 7. ?¤? ?£÷ÿ¢ð ??÷£ ô?¡??ý?÷??¡¢¬ ?? ¡£? ?????ÿ?¬?ð¥ ??????¢?÷ ò?????? ¡¢?÷ô¦¯ ¢ÿ ÷?ý¡? ¢£÷ÿ¢ð åå ?ÿ ? ?¡¢ÿ??¯? ?ÿ ý?ô?????® ÿ??? ð¢?£ ÷ðö? òð.
void n7(vector<int>& B) {
    for (int i = 0; i < B.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < B.size(); j++) {
            if (B[j] < B[minIndex]) {
                minIndex = j;
            }
        }
        swap(B[i], B[minIndex]);
    }
}

int main() {
    int choice = -1; // ??ð¦ðÿ?ð?ð £?? ÷«ö?  òÿò -1, §¢?ö« ð?ö??ÿ¢¬ ?¨ðö?ò
    do {
        cout << "\n?ðö? ?¢¬ ?ÿ÷ýÿ??¯ (1-7, 0 ý?¯ ÷ð¥?ý£): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int n;
            cout << "?÷?ý?¢¬ ò??¬ò?¡¢¬ ??????¢?÷ £ ô?¡??ý?÷??¡¢? A: ";
            cin >> n;
            vector<int> A(n), B;

            cout << "?÷?ý?¢¬ ??????¢ð ô?¡??ý?÷??¡¢? A: ";
            for (int i = 0; i < n; i++) {
                cin >> A[i];
                if (A[i] % 2 == 0) {
                    B.push_back(A[i]);
                }
            }

            n1(B);

            cout << "??ý¡? ¢?÷ÿ?ÿ ô?¡??ý?÷??¡¢¬ ôÿ ?ð¥ §ð¡?? B: ";
            for (int i = 0; i < B.size(); i++) {
                cout << B[i] << " ";
            }
            cout << endl;
            break;
        }
        case 2: {
            int n;
            cout << "?÷?ý?¢¬ ò??¬ò?¡¢¬ ??????¢?÷ £ ô?¡??ý?÷??¡¢? A: ";
            cin >> n;
            vector<int> A(n), B;

            cout << "?÷?ý?¢¬ ??????¢ð ô?¡??ý?÷??¡¢? A: ";
            for (int i = 0; i < n; i++) {
                cin >> A[i];
                if (A[i] < 0) {
                    B.push_back(A[i]);
                }
            }

            n2(B);

            cout << "??ý¡? ¢?÷ÿ?ÿ ô?¡??ý?÷??¡¢¬ ÷?ý'ã??ð¥ §ð¡?? B: ";
            for (int i = 0; i < B.size(); i++) {
                cout << B[i] << " ";
            }
            cout << endl;
            break;
        }
        case 3: {
            int m, n;
            cout << "?÷?ý?¢¬ ò??¬ò?¡¢¬ ô?¡??ý?÷??¡¢??: ";
            cin >> m;

            vector<vector<int>> A(m);

            for (int i = 0; i < m; i++) {
                cout << "?÷?ý?¢¬ ò??¬ò?¡¢¬ ??????¢?÷ £ " << i + 1 << "-? ô?¡??ý?÷??¡¢?: ";
                cin >> n;
                A[i].resize(n);
                cout << "?÷?ý?¢¬ ??????¢ð ô?¡??ý?÷??¡¢?: ";
                for (int j = 0; j < n; j++) {
                    cin >> A[i][j];
                }

                n3(A[i]);  // ?? ¢£ã?? ò???£ ô?¡??ý?÷??¡¢¬
            }

            cout << "??ý¡? ¢?÷ÿ?? ô?¡??ý?÷??¡¢?: " << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < A[i].size(); j++) {
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
        case 4: {
            int m, n;
            cout << "?÷?ý?¢¬ ò??¬ò?¡¢¬ ô?¡??ý?÷??¡¢??: ";
            cin >> m;

            vector<vector<int>> A(m);
            vector<int> B;

            for (int i = 0; i < m; i++) {
                cout << "?÷?ý?¢¬ ò??¬ò?¡¢¬ ??????¢?÷ £ " << i + 1 << "-? ô?¡??ý?÷??¡¢?: ";
                cin >> n;
                A[i].resize(n);
                cout << "?÷?ý?¢¬ ??????¢ð ô?¡??ý?÷??¡¢?: ";
                for (int j = 0; j < n; j++) {
                    cin >> A[i][j];
                }

                int maxElement = A[i][0];
                for (int j = 1; j < n; j++) {
                    if (A[i][j] > maxElement) {
                        maxElement = A[i][j];
                    }
                }
                B.push_back(maxElement);
            }

            n4(B);

            cout << "??ý¡? ¢?÷ÿ?ÿ ô?¡??ý?÷??¡¢¬ ?ÿò¡ð?ÿ?¬?ð¥ ??????¢?÷ B: ";
            for (int i = 0; i < B.size(); i++) {
                cout << B[i] << " ";
            }
            cout << endl;
            break;
        }
        case 5: {
            int m;
            cout << "?÷?ý?¢¬  ????  ò÷ÿý ÿ¢??å ?ÿ¢ ð¦?: ";
            cin >> m;

            vector<vector<int>> A(m, vector<int>(m));
            vector<int> diag;

            cout << "?÷?ý?¢¬ ??????¢ð ?ÿ¢ ð¦? A: " << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> A[i][j];
                    if (i == j) {
                        diag.push_back(A[i][j]);  // ??ýÿã?? ??????¢ ? ????÷??å ý?ÿ???ÿ??
                    }
                }
            }

            n5(diag);  // ?? ¢£ã?? ý?ÿ???ÿ?¬ ?ÿ ? ?¡¢ÿ??¯?

            cout << "??ý¡? ¢?÷ÿ?? ??????¢ð ????÷??å ý?ÿ???ÿ??: ";
            for (int i = 0; i < diag.size(); i++) {
                cout << diag[i] << " ";
            }
            cout << endl;
            break;
        }
        case 6: {
            int m;
            cout << "?÷?ý?¢¬  ????  ò÷ÿý ÿ¢??å ?ÿ¢ ð¦?: ";
            cin >> m;

            vector<vector<int>> A(m, vector<int>(m));

            cout << "?÷?ý?¢¬ ??????¢ð ?ÿ¢ ð¦? A: " << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> A[i][j];
                }
            }

            for (int col = 0; col < m; col++) {
                n6(A, m, col);  // ?? ¢£ã?? ¡¢?÷ô?¦¬
            }

            cout << "??ý¡? ¢?÷ÿ?? ¡¢?÷ô¦? ?ÿ¢ ð¦?: " << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
        case 7: {
            int m;
            cout << "?÷?ý?¢¬  ????  ?ÿ¢ ð¦?: ";
            cin >> m;

            vector<vector<int>> A(m, vector<int>(m));
            vector<int> B(m);

            cout << "?÷?ý?¢¬ ??????¢ð ?ÿ¢ ð¦? A: " << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> A[i][j];
                }
            }

            for (int col = 0; col < m; col++) {
                int minElement = A[0][col];
                for (int row = 1; row < m; row++) {
                    if (A[row][col] < minElement) {
                        minElement = A[row][col];
                    }
                }
                B[col] = minElement;  // ??ýÿã?? ?????ÿ?¬?ð? ??????¢ ¡¢?÷ô¦¯ ÷ ??÷£ ô?¡??ý?÷??¡¢¬
            }

            n7(B);  // ?? ¢£ã?? ô?¡??ý?÷??¡¢¬ ?????ÿ?¬?ð¥ ??????¢?÷

            cout << "??ý¡? ¢?÷ÿ?? ?????ÿ?¬?? ??????¢ð ¡¢?÷ô¦?÷: ";
            for (int i = 0; i < B.size(); i++) {
                cout << B[i] << " ";
            }
            cout << endl;
            break;
        }
        case 0:
            cout << "?ð¥?ý ? ô ?? ÿ?ð." << endl;
            break;
        default:
            cout << "??ô ÿ÷ð?¬?ð? ÷ðö? . ?ô ?ö£?¢? ©?  ÿ?." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
