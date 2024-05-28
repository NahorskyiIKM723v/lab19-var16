#include <iostream>
#include <Windows.h>
using namespace std;
template <typename T>
void insertSorted(T* arr, int& n, int capacity, const T& value, int count) {
    int pos = 0;
    while (pos < n && arr[pos] < value) {
        pos++;
    }
    if (n + count > capacity) {
        cerr << "Не вистачає місця у масиві для вставки" << endl;
        return;
    }
    for (int i = n - 1; i >= pos; i--) {
        arr[i + count] = arr[i];
    }
    for (int i = 0; i < count; i++) {
        arr[pos + i] = value;
    }
    n += count;
}
template <typename T>
void printArray(const T* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int capacity = 100;
    int arr[capacity];
    int n;

    cout << "Введіть кількість елементів у масиві: ";
    cin >> n;
    cout << "Введіть елементи масиву у відсортованому порядку: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int value;
    int count;
    cout << "Введіть значення, яке потрібно вставити: ";
    cin >> value;
    cout << "Введіть кількість вставок: ";
    cin >> count;
    cout << "Початковий масив: ";
    printArray(arr, n);
    insertSorted(arr, n, capacity, value, count);
    cout << "Масив після вставки: ";
    printArray(arr, n);

    return 0;
}
