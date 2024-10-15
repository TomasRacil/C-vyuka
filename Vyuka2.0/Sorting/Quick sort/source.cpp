#include <time.h>
#include <iostream>

using namespace std;

// Funkce pro rozdělení pole a výběr pivota
int partition(int *arr, int low, int high)
{
    int pivot = *(arr + high); // Pivot je poslední prvek
    int i = (low - 1);         // Index menšího prvku

    for (int j = low; j <= high - 1; j++)
    {
        // Pokud je aktuální prvek menší nebo roven pivotu
        if (*(arr + j) <= pivot)
        {
            i++; // Zvýšení indexu menšího prvku
            // Výměna arr[i] a arr[j]
            int temp = *(arr + i);
            *(arr + i) = *(arr + j);
            *(arr + j) = temp;
        }
    }
    // Výměna arr[i + 1] a arr[high] (pivot)
    int temp = *(arr + i + 1);
    *(arr + i + 1) = *(arr + high);
    *(arr + high) = temp;
    return (i + 1);
}

// Hlavní funkce quick sortu
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        // pi je index rozdělení, arr[pi] je nyní na správném místě
        int pi = partition(arr, low, high);

        // Rekurzivně seřaď prvky před a po rozdělení
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// // Funkce pro rozdělení pole a výběr pivota
// int partition(int arr[], int low, int high) {
//     int pivot = arr[high]; // Pivot je poslední prvek
//     int i = (low - 1);     // Index menšího prvku

//     for (int j = low; j <= high - 1; j++) {
//         // Pokud je aktuální prvek menší nebo roven pivotu
//         if (arr[j] <= pivot) {
//             i++;             // Zvýšení indexu menšího prvku
//             swap(arr[i], arr[j]); // Výměna prvků
//         }
//     }
//     // Výměna arr[i + 1] a arr[high] (pivot)
//     swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }

// // Hlavní funkce quick sortu
// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         // pi je index rozdělení, arr[pi] je nyní na správném místě
//         int pi = partition(arr, low, high);

//         // Rekurzivně seřaď prvky před a po rozdělení
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

int main()
{
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Nesetříděné pole: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    struct timespec start, end;

    // Začátek měření procesorového času
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    quickSort(arr, 0, n - 1);

    // Konec měření procesorového času
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    cout << "\nSetříděné pole: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Výpočet doby trvání v nanosekundách
    long long duration = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    cout << "Doba trvání algoritmu (CPU): " << duration << " nanosekund" << endl;

    return 0;
}