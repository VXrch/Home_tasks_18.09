#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InitArr(int arr[], int size) {

    for (int i = 0; i < size; i++)
    {
        arr[i] = -20 + rand() % 40;
    }
}

void PrintArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << "Arr[" << i << "] = " << arr[i] << endl;
    }
}

void BoubleSort(int arr[], int size, int move = 1) {

    int temp; // 10, 5, 2 ,8, 6

    if (move == 0) {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr[i] < arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    else if (move == 1) {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    else {
        cout << "Wrong choice!" << endl;
    }
}

void task_1() {

    /*1. Дан масив чисел розмірністю 10 елементів.Написа -
        ти функцію, яка сортує масив за зростанням або за
        спаданням, залежно від третього параметра функції.
        Якщо він дорівнює 1, сортування йде за спаданням,
        якщо 0, то за зростанням.Перші 2 параметри функ -
        ції — це масив і його розмір, третій параметр за за -
        мовчуванням дорівнює 1.*/

    const int size = 10;
    int arr[size];

    int move;

    InitArr(arr, size);
    PrintArr(arr, size);

    cout << "Enter how to sort your array\n[0] : 1 - 10\n[1] : 10 - 1\n --- "; cin >> move;
    BoubleSort(arr, size, move);
    PrintArr(arr, size);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BoubleSortInRange(int arr[], int size) {

    int range1 = -1, range2 = size, temp;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0 && range1 == -1) {
            range1 = i;
        }
        else if (arr[i] < 0) {
            range2 = i;
        }
    }

    for (int i = range1; i < range2; i++)
    {
        for (int j = range1; j < range2; j++)
        {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void task_2() {
    /*
    2. Дан масив випадкових чисел у діапазоні від - 20 до
        + 20. Необхідно знайти позиції крайніх від'ємних еле-
        ментів(найлівішого від'ємного елемента і найправі-
        шого від'ємного елемента) і впорядкувати елементи,
        що знаходяться між ними.*/

    const int size = 10;
    int arr[size];

    int move;

    InitArr(arr, size);
    PrintArr(arr, size);

    cout << "\n_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl << endl;

    BoubleSortInRange(arr, size);
    PrintArr(arr, size);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void random_numbers(int arr[], int size) {

    int temp, random;

    for (int i = 0; i < size; i++)
    {
        random = rand() % size;

        temp = arr[i];
        arr[i] = arr[random];
        arr[random] = temp;
    }
}

void random_number_in_range(int arr[], int size) {

    bool number_exist = false; int random_numb = 0;

    do
    {
        random_numb = rand() % size;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == random_numb) {
                number_exist = true; break;
            }
        }
    } while (number_exist == false);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == random_numb)
        {
            cout << "Number was found!\n" << "Arr [" << i << "] = " << random_numb;
        }
    }
}

void task_3() {

    /*3. Дан масив із 20 цілих чисел зі значеннями від 1 до 20.
        Необхідно:
    ■ написати функцію, що розкидає елементи масиву
        довільним чином;
    ■ створити випадкове число з того ж діапазону і знайти
        позицію цього випадкового числа в масиві;
    ■*** відсортувати елементи масиву, що знаходяться зліва
        від знайденої позиції за спаданням, а елементи ма -
        сиву, що знаходяться справа від знайденої позиції,
        за зростанням.*/

    const int size = 20;
    int arr[size];

    int move;

    InitArr(arr, size);
    PrintArr(arr, size);

    cout << "\n_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl << endl;

    random_numbers(arr, size);
    PrintArr(arr, size);

    random_number_in_range(arr, size);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main()
{
    srand(time(NULL));

    int task_number;

    cout << "Enter task number: "; cin >> task_number;
    if (task_number == 1) {
        task_1();
    }
    else if (task_number == 2) {
        task_2();
    }
    else if (task_number == 3) {
        task_3();
    }
    else {
        cout << "Wrong number!" << endl;
    }
}