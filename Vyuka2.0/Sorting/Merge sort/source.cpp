#include <time.h>
#include <iostream>

using namespace std;

// Funkce pro sloučení dvou seřazených podpolí
void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Vytvoření dočasných polí
    int *L = new int[n1];
    int *R = new int[n2];

    // Kopírování dat do dočasných polí
    for (int i = 0; i < n1; i++)
        L[i] = *(arr + left + i);
    for (int j = 0; j < n2; j++)
        R[j] = *(arr + mid + 1 + j);

    // Sloučení dočasných polí zpět do arr[left..right]
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            *(arr + k) = L[i];
            i++;
        }
        else
        {
            *(arr + k) = R[j];
            j++;
        }
        k++;
    }

    // Kopírování zbývajících prvků z L[], pokud existují
    while (i < n1)
    {
        *(arr + k) = L[i];
        i++;
        k++;
    }

    // Kopírování zbývajících prvků z R[], pokud existují
    while (j < n2)
    {
        *(arr + k) = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

// Hlavní funkce merge sortu
void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        // Najdi střed
        int mid = left + (right - left) / 2;

        // Rekurzivně seřaď obě poloviny
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Sloučení seřazených polovin
        merge(arr, left, mid, right);
    }
}

// // Funkce pro sloučení dvou seřazených podpolí
// void merge(int arr[], int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     // Vytvoření dočasných polí
//     int L[n1], R[n2];

//     // Kopírování dat do dočasných polí
//     for (int i = 0; i < n1; i++) {
//         L[i] = arr[left + i];
//     }
//     for (int j = 0; j < n2; j++) {
//         R[j] = arr[mid + 1 + j];
//     }

//     // Sloučení dočasných polí zpět do arr[left..right]
//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     // Kopírování zbývajících prvků z L[], pokud existují
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     // Kopírování zbývajících prvků z R[], pokud existují
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// // Hlavní funkce merge sortu
// void mergeSort(int arr[], int left, int right) {
//     if (left < right) {
//         // Najdi střed
//         int mid = left + (right - left) / 2;

//         // Rekurzivně seřaď obě poloviny
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);

//         // Sloučení seřazených polovin
//         merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

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