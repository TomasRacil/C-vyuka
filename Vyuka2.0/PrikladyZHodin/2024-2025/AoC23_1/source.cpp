#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    fstream advent_vstup;
    int sum = 0;

    advent_vstup.open("advent_vstup_maly.txt", ios::in);
    if (advent_vstup.is_open())
    {
        string radek;
        int cislo;
        while (getline(advent_vstup, radek))
        {
            cislo = 0;
            // cout << radek << endl;
            int i = 0;
            while (true)
            {
                if (isdigit(radek[i]))
                {
                    cislo = (radek[i] - '0') * 10;
                    break;
                }
                i++;
            }
            i = radek.length() - 1;
            while (true)
            {
                if (isdigit(radek[i]))
                {
                    cislo += (radek[i] - '0');
                    break;
                }
                i--;
            }
            sum += cislo;
            // for (int i = 0; i < radek.length(); i++)
            // {
            //     if (isdigit(radek[i])){
            //         cout << radek[i] - '0';
            //         if (cisla[0]=="\0")
            //         {
            //             cisla[0]=radek[i];
            //         }

            //         }
            // }
            cout << endl;

            // cisla[0] = '\0';
            // cisla[1] = '\0';
            // int i = 0;
            // while (cisla[0] == '\0')
            // {
            //     if (isdigit(radek[i]))
            //     {
            //         cisla[0] = radek[i];
            //     }
            //     i++;
            // }
            // i = radek.length() - 1;
            // while (cisla[1] == '\0')
            // {
            //     if (isdigit(radek[i]))
            //     {
            //         cisla[1] = radek[i];
            //     }
            //     i--;
            // }
            // sum += ((int(cisla[0]) - 48) * 10 + int(cisla[1]) - 48);
        }
    }

    cout << sum << endl;

    return 0;
}

// int main()
// {

//     fstream advent_vstup;
//     int sum = 0;

//     advent_vstup.open("advent_vstup.txt", ios::in);
//     if (advent_vstup.is_open())
//     {
//         string radek;
//         char cisla[2];
//         while (getline(advent_vstup, radek))
//         {
//             cisla[0] = '\0';
//             cisla[1] = '\0';
//             for (int i = 0; i < radek.length(); i++)
//             {

//                 if (isdigit(radek[i]))
//                 {
//                     if (cisla[0] == '\0')
//                         cisla[0] = radek[i];
//                     else
//                         cisla[1] = radek[i];
//                 }
//             }
//             if (cisla[1] == '\0')
//                 cisla[1] = cisla[0];
//             sum += stoi(std::string() + cisla[0] + cisla[1]);
//         }
//     }

//     cout << sum << endl;

//     return 0;
// }