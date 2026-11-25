#include <iostream>
using namespace std;

// ---------- Оголошення функцій (до main) ----------
// Завдання 1.1: Proc40
bool IsPalindrome(int K);                       // чи є число K (0<K<1000) паліндромом
void task_proc40();                             // задача Proc40 цілком

// Завдання 1.2: Proc12
void SortInc3(double &A, double &B, double &C); // впорядкування A, B, C за зростанням
void task_proc12();                             // задача Proc12 цілком

// Завдання 2: Integer6
bool in_A(int &pA);                             // введення двозначного числа з перевіркою
int tens_digit(int pA);                         // підрахунок: цифра десятків
int units_digit(int pA);                        // підрахунок: цифра одиниць
void out_res(int pT, int pU);                   // виведення результату
void task_Int6();                               // задача Integer6 цілком

int main() {
    int menu;
    cout << "Task number (1 - Proc40, 2 - Proc12, 3 - Integer6): ";
    cin >> menu;
    if (cin.fail()) {                           // перевірка: введено не число
        cout << "Wrong task! (Only 1,2,3)" << endl;
        return 0;
    }
    // вибір завдання
    switch (menu) {
        case 1: task_proc40(); break;
        case 2: task_proc12(); break;
        case 3: task_Int6(); break;
        default: cout << "Wrong task! (Only 1,2,3)" << endl;
    }
    return 0;
}

// ---------- Визначення функцій (після main) ----------

// Proc40: true, якщо запис числа читається однаково зліва направо і справа наліво
bool IsPalindrome(int K) {
    int first = K / 100;                        // перша цифра (сотні, для 1-2 цифрових = 0)
    int last = K % 10;                          // остання цифра (одиниці)
    if (K < 10) return true;                    // однозначне число - завжди паліндром
    if (K < 100) return (K / 10 == K % 10);     // двозначне: цифри однакові
    return first == last;                       // тризначне: перша цифра = остання
}

// Proc40: задача цілком - перевіряємо п'ять чисел (без циклів)
void task_proc40() {
    int k1, k2, k3, k4, k5;
    cout << "************* Proc 40 *****************" << endl;
    cout << "Enter five integers (0 < K < 1000): ";
    cin >> k1 >> k2 >> k3 >> k4 >> k5;
    if (cin.fail() || k1 <= 0 || k1 >= 1000 || k2 <= 0 || k2 >= 1000 ||
        k3 <= 0 || k3 >= 1000 || k4 <= 0 || k4 >= 1000 || k5 <= 0 || k5 >= 1000) { // перевірка
        cout << "Wrong numbers!" << endl;
        return;
    }
    // кількість паліндромів: true перетворюється на 1, false - на 0
    int count = IsPalindrome(k1) + IsPalindrome(k2) + IsPalindrome(k3) +
                IsPalindrome(k4) + IsPalindrome(k5);
    cout << "Palindromes count = " << count << endl;
}

// Proc12: впорядковує A, B, C за зростанням (параметри - вхідні і вихідні, за посиланням)
void SortInc3(double &A, double &B, double &C) {
    double t;                                   // допоміжна змінна для обміну
    if (A > B) { t = A; A = B; B = t; }         // найменше з A, B - в A
    if (B > C) { t = B; B = C; C = t; }         // найбільше - в C
    if (A > B) { t = A; A = B; B = t; }         // остаточно впорядковуємо A, B
}

// Proc12: задача цілком - впорядковуємо два набори (A1,B1,C1) і (A2,B2,C2)
void task_proc12() {
    double a1, b1, c1, a2, b2, c2;
    cout << "************* Proc 12 *****************" << endl;
    cout << "Enter A1 B1 C1: ";
    cin >> a1 >> b1 >> c1;
    if (cin.fail()) {                           // перевірка першого набору
        cout << "Wrong numbers!" << endl;
        return;
    }
    cout << "Enter A2 B2 C2: ";
    cin >> a2 >> b2 >> c2;
    if (cin.fail()) {                           // перевірка другого набору
        cout << "Wrong numbers!" << endl;
        return;
    }
    SortInc3(a1, b1, c1);                       // сортуємо перший набір
    SortInc3(a2, b2, c2);                       // сортуємо другий набір
    cout << "Set 1 sorted: " << a1 << " " << b1 << " " << c1 << endl;
    cout << "Set 2 sorted: " << a2 << " " << b2 << " " << c2 << endl;
}

// Integer6: введення двозначного числа з перевіркою; true - помилка
bool in_A(int &pA) {
    cout << "Integer6." << endl;
    cout << "A (two-digit) = ";
    cin >> pA;
    if (cin.fail()) return true;                // не число
    if (pA < 0) pA = -pA;                       // працюємо з модулем
    if (pA < 10 || pA > 99) return true;        // не двозначне
    return false;
}

// Integer6: цифра десятків - цілочисельне ділення
int tens_digit(int pA) {
    return pA / 10;
}

// Integer6: цифра одиниць - залишок від ділення
int units_digit(int pA) {
    return pA % 10;
}

// Integer6: виведення результату
void out_res(int pT, int pU) {
    cout << "Tens = " << pT << endl;
    cout << "Units = " << pU << endl;
}

// Integer6: задача цілком
void task_Int6() {
    int A;
    if (in_A(A))                                // некоректні дані
        cout << "A must be two-digit integer!" << endl;
    else
        out_res(tens_digit(A), units_digit(A)); // підрахунок і виведення
}
