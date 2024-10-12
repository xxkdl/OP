#include <iostream>
using namespace std;

// 1. Блочна структура програм
void n11() {
    int a = 10;
    cout << "Блок 1, a = " << a << endl;

    // Вкладений блок
    {
        int b = 20;
        cout << "Вкладений блок в Блоці 1, b = " << b << endl;
    }
}

void n12() {
    int c = 30;
    cout << "Блок 2, c = " << c << endl;
}

// 2. Статичний розподіл пам'яті
static int globalStaticVar = 100;  

void n2() {
    static int staticVar = 0;  
    staticVar++;
    cout << "Статична змінна в функції: " << staticVar << endl;
}

// 3. Динамічний розподіл пам'яті
void n3() {
    int* dynamicVar1 = new int(5);  
    cout << "Динамічна змінна 1: " << *dynamicVar1 << endl;

    // Вкладений блок
    {
        int* dynamicVar2 = new int(10);
        cout << "Динамічна змінна 2: " << *dynamicVar2 << endl;
        delete dynamicVar2;  
    }

    delete dynamicVar1;  
}

// 4. Операція глобального дозволу видимості імен
void n4() {
    int var = 20;  // Локальна змінна
    cout << "Локальна змінна: " << var << endl;
    cout << "Глобальна змінна за допомогою резолюції області: " << ::globalStaticVar << endl;  // Використання глобального імені
}

// 5. Динамічний розподіл пам'яті в "купі"
void n5() {

    int* heapVar1 = new int(15);
    cout << "Heap змінна 1: " << *heapVar1 << endl;

    int* heapVar2 = new int(25);
    cout << "Heap змінна 2: " << *heapVar2 << endl;

    delete heapVar1;
    heapVar1 = nullptr;  
}

int main() {
    int choice;
    do {
        cout << "\nВиберіть завдання (1-5, 0 для виходу): ";
        cin >> choice;

        switch (choice) {
        case 1:
            n11();
            n12();
            break;
        case 2:
            cout << "Глобальна статична змінна: " << globalStaticVar << endl;
            n2 ();
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