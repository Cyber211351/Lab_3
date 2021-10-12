#include <iostream>

#define SIZE 1000

using std::cout;
using std::cin;
using std::endl;

template <typename T>
void array_output(T mas, int size) {		
    cout << "Массив размером " << size << ":\n";
    for (int i = 0; i < size; i++) {
        cout << mas[i] << " ";		
    }
    cout << endl;
}

template <typename T>		
void array_input(T mas, int& size) {
    while (true) {
        cout << "Введите размер массива до 1000: ";
        cin >> size;
        if (size > 0 && size <= SIZE) break;		
        else cout << "Ошибка. n не может быть меньше 0 и больше 1000. Повторите ввод с учетом примечаний.\n";
    }
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        cin >> mas[i];
    }
}

template <>		
void array_input(char* mas, int& size) {
    while (true) {
        cout << "Введите размер массива: ";
        cin >> size;
        if (size > 0 && size <= SIZE) break;
        else cout << "Ошибка. n не может быть меньше 0 и больше 1000. Повторите ввод с учетом примечаний.\n";
    }
    cout << "введите элементы буквенного массива построчно:\n";
    for (int i = 0; i < size; i++) {
        while (true) {
            cin >> mas[i];
            if (mas[i] >= 'a' && mas[i] <= 'z') break;
            else cout << "Символ не является буквой английского алфавита. Повторите ввод\n\n";
        }
    }
}

void bubblesort(int* mas, int size) {		
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mas[j] > mas[j + 1]) {
                temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}

void countsort(char* mas, int size) {		
#define DIF_ELEM 26
    int arr[DIF_ELEM] = { 0 };				
    int j;
    for (int i = 0; i < size; i++) {		
        j = (int)(mas[i] - 'a');			
        arr[j]++;							
    }
    int i = 0;
    j = 0;
    while (j <= DIF_ELEM) {					
        if (arr[j] > 0) {					
            mas[i] = (char)((int)'a' + j);	
            i++;
            arr[j]--;
        }
        else j++;
    }
}

void mergesort(int* mas, int l, int r) {	
    if (l == r) return;						
    int mid = (l + r) / 2;					
    mergesort(mas, l, mid);					
    mergesort(mas, mid + 1, r);				
    int i = l;								
    int j = mid + 1;
    int* tmp = new int[r];					
    for (int step = 0; step < r - l + 1; step++) {
        if (j > r || (i <= mid && mas[i] < mas[j])) {
            tmp[step] = mas[i];
            i++;
        }
        else {
            tmp[step] = mas[j];
            j++;
        }
    }
    for (int step = 0; step < r - l + 1; step++) mas[l + step] = tmp[step];
    delete[] tmp;
}

template <typename T>
void check(T mas, int& size) {
    char option;
    if (size == 0) array_input<T>(mas, size);
    else {
        cout << "хотите повторить ввод массива (y/n): ";
        cin >> option;
        if (option == 'y') array_input<T>(mas, size);
    }
}

int main(int argc, char* argv) {
    system("chcp 65001 > nul");
    int mas1[SIZE], mas3[SIZE], n1 = 0, n2 = 0, n3 = 0;
    char mas2[SIZE];
    char option;
    while (true) {
        cout << "Выберите действие: \n"
            << "1. Пузырьковая сортировка\n"
            << "2. Сортиривка подсчетом\n"
            << "3. Сортировка методом слияния\n"
            << "4. Выход\n"
            << "Ваш выбор: ";
        cin >> option;
        switch (option) {
        case '1':
            check(mas1, n1);
            bubblesort(mas1, n1);
            cout << "\nОтсортированный массив: \n";
            array_output(mas1, n1);
            break;
        case '2':
            check(mas2, n2);
            countsort(mas2, n2);
            cout << "\nОтсортированный массив: \n";
            array_output(mas2, n2);
            break;
        case '3':
            check(mas3, n3);
            mergesort(mas3, 0, n3 - 1);
            cout << "\nОтсортированный массив: \n";
            array_output(mas3, n3);
            break;
        case '4':
            return 0;
            break;
        default:
            system("cls");
            continue; 
        }
        system("pause");
        system("cls");
    }
}