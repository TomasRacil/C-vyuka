#include <time.h>
#include <iostream>

using namespace std;

void insertionSort(int *arr, int n)
{
    int *ptr = arr; // Nastavení pointeru na začátek pole
    for (int i = 1; i < n; i++)
    {
        int key = *(ptr + i); // Uložení aktuálního prvku
        int j = i - 1;
        // Posouvání větších prvků o jednu pozici doprava
        while (j >= 0 && *(ptr + j) > key)
        {
            *(ptr + j + 1) = *(ptr + j);
            j = j - 1;
        }
        *(ptr + j + 1) = key; // Vložení aktuálního prvku na správné místo
    }
}

// void insertionSort(int arr[], int n) {
//     for (int i = 1; i < n; i++) {
//         int key = arr[i]; // Uložení aktuálního prvku
//         int j = i - 1;

//         // Posouvání větších prvků o jednu pozici doprava
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }

//         // Vložení aktuálního prvku na správné místo
//         arr[j + 1] = key;
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

    insertionSort(arr, n);

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
