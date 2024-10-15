#include <time.h>
#include <iostream>

using namespace std;

void selectionSort(int *arr, int n)
{
    int *i, *j, *minIndex, temp;

    // Procházíme nesetříděnou část pole
    // i ukazuje na začátek nesetříděné části
    for (i = arr; i < arr + n - 1; i++)
    {
        // Nalezneme index nejmenšího prvku v nesetříděné části
        minIndex = i; // Předpokládáme, že první prvek je minimum
        // Procházíme zbytek nesetříděné části
        for (j = i + 1; j < arr + n; j++)
        {
            if (*j < *minIndex)
            {
                // Našli jsme menší prvek, aktualizujeme minIndex
                minIndex = j;
            }
        }

        // Prohodíme nejmenší prvek s prvním prvkem nesetříděné části
        temp = *minIndex;
        *minIndex = *i;
        *i = temp;
    }
}

// void selectionSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         int minIndex = i;
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j;
//             }
//         }
//         // Prohození prvků
//         int temp = arr[minIndex];
//         arr[minIndex] = arr[i];
//         arr[i] = temp;
//     }
// }

int main()
{
    int arr[] = {5, 3, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Nesetříděné pole: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    struct timespec start, end;

    // Začátek měření procesorového času
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    selectionSort(arr, n);

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
