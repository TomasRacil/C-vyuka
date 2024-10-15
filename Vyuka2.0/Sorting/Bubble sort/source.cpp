#include <time.h>
#include <iostream>

using namespace std;

void bubbleSort(int *arr, int n)
{
    bool swapped;
    int *ptr;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        ptr = arr; // Nastavení pointeru na začátek pole
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*(ptr + j) > *(ptr + j + 1))
            {
                // Výměna prvků pomocí pointerů
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
                swapped = true;
            }
            ptr++; // Posunutí pointeru na další prvek
        }
        // Pokud nedošlo k žádné výměně, pole je seřazené
        if (swapped == false)
            break;
    }
}

// void bubbleSort(int arr[], int n) {
//     bool swapped;
//     for (int i = 0; i < n - 1; i++) {
//         swapped = false;
//         for (int j = 0; j < n - i - 1; j++) {
//             // Pokud je aktuální prvek větší než následující, prohodí je
//             if (arr[j] > arr[j + 1]) {
//                 swap(arr[j], arr[j + 1]);
//                 swapped = true;
//             }
//         }
//         // Pokud nedošlo k žádné výměně, pole je seřazené
//         if (swapped == false) {
//             break;
//         }
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

    bubbleSort(arr, n);

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