
#include <iostream>
#include <string>
//#include <format> //C++ 20
#include <time.h>



using namespace std;

void task_1(int f_len, int fl_len) {
    /*
    * Fuknkce vypisuje cisla od 0 do 100. 
    * Pokud narazi na cislo, ktere je nasobkem poctu pismen ve vasem krestnim jmenu vynecha toto cislo. 
    * Pokud narazi na cislo, ktere je nasobkem poctu pismen souctu vaseho krestniho jmena a prijmeni, vypise dvojnasobek tohoto cisla. 
    * Pokud jsou obe podminky splneny vypise 'X'.
    */
    for (int i = 0; i <= 100; i++) {

        if (i % f_len == 0) {
            if (i % fl_len == 0) {
                cout << "X\t";
            }
            else {
                cout << "\t";
            }
        }
        else if (i % fl_len == 0) {
            //cout << format("{}\t", (i * 2)); //C++ 20
            cout << i * 2 << "\t";
        }
        else {
            //cout << format("{}\t", i); //C++ 20
            cout << i << "\t";
        }
        if (i % 10 == 0) {
            cout << endl;
        }
    }
}

void task_2(int** arr, int rows, int cols, int l_name) {
    /*
    * Funkce v dvojrozmernem poli najde nejvyssi a nejnizsi cislo. 
    * Take pocet vyskytu cisla l_name
    */

    int min = arr[0][0], max = arr[0][0], count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
            else if (arr[i][j] < min) {
                min = arr[i][j];
            }
            if (arr[i][j] == l_name) {
                count++;
            }
        }
    }
    //cout << format("Nejvyssi cilo je {}\nNejnizsi cislo je {}\n a pocet vyskytu cisla {} je {}", max, min, l_name, count); //C++ 20
    cout << "Nejvyssi cilo je " << max << "\nNejnizsi cislo je " << min << "\na pocet vyskytu cisla " << l_name << " je " << count<<endl;
}

int factorial(int num) {
    /*
    * Funkce pocita rekurzivne faktorial.    
    */
    if (num < 0) {
        cout << "Nen� definov�n.\n";
        return NULL;
    }
    else if (num == 1 || num ==0) {
        return 1;
    }
    else {
        return num*factorial(num-1);
    }
}

void print_2d_array(int** arr, int rows, int cols) {
    /*
    * Tisk 2d pole.
    */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //cout << format("{}\t", arr[i][j]);
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int** initialize_2d_array(int rows, int cols) {
    /*
    * Inicializace 2d pole.
    */
    srand(time(0));
    int** arr;
    arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = (int)rand() % 100;
        }
    }
    return arr;
}


int main()
{

    string first_name, last_name;

    int f_len, l_len, fl_len, rows, cols, num;

    cout << "Zadejte vase krestni jmeno:";
    cin >> first_name;
    f_len = first_name.length();
    //cout << format("Delka krestniho jmena je: {}\n", f_len); //C++ 20
    cout << "Delka krestniho jmena je: " << f_len<< endl;

    cout << "Zadejte vase prijmeni jmeno:";
    cin >> last_name;
    l_len = last_name.length();
    //cout << format("Delka prijmeni je: {}\n", l_len); // C++ 20
    cout << "Delka prijmeni je: " << l_len<<endl;


    fl_len = f_len + l_len;

    task_1(f_len, fl_len);


    cout << "Zadej pocet radku: ";
    cin >> rows;
    cout << "Zadej pocet sloupcu: ";
    cin >> cols;

    int** array = initialize_2d_array(rows, cols);

    print_2d_array(array,rows,cols);

    task_2(array, rows, cols, l_len);

    cout << "Zadej ciso pro spocitani faktorialu: ";
    cin >> num;
    cout << "Faktorial je: "<<factorial(num) <<endl;
}

