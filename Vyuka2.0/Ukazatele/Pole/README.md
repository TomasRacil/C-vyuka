## Ukazatele a pole v C++

Ukazatele a pole v C++ spolu úzce souvisí. Pole lze chápat jako ukazatel na první prvek pole. To umožňuje pracovat s poli pomocí ukazatelové aritmetiky.
![Ukazatele a pole](https://www.log2base2.com/images/c/array-and-pointer-1.png)

### Ukazatelová aritmetika

S ukazateli lze provádět základní aritmetické operace:

* **Sčítání:** `ukazatel + n` posune ukazatel o `n` prvků dopředu v paměti.
* **Odčítání:** `ukazatel - n` posune ukazatel o `n` prvků dozadu v paměti.
* **Inkrement:** `ukazatel++` posune ukazatel na další prvek v paměti.
* **Dekrement:** `ukazatel--` posune ukazatel na předchozí prvek v paměti.

### Přístup k prvkům pole pomocí ukazatelů

K prvkům pole lze přistupovat pomocí ukazatelů a operátoru dereference (`*`).

```c++
int pole[5] = {1, 2, 3, 4, 5};
int *ukazatel = pole; // ukazatel ukazuje na první prvek pole

std::cout << *ukazatel << std::endl; // Vypíše 1
std::cout << *(ukazatel + 1) << std::endl; // Vypíše 2
std::cout << *(ukazatel + 2) << std::endl; // Vypíše 3
```

### Předávání polí funkcím

Pole se funkcím předávají jako ukazatel na první prvek pole.

```c++
void vypisPole(int *pole, int velikost) {
  for (int i = 0; i < velikost; i++) {
    std::cout << *(pole + i) << " ";
  }
  std::cout << std::endl;
}

int main() {
  int pole[5] = {1, 2, 3, 4, 5};
  vypisPole(pole, 5); // Vypíše 1 2 3 4 5
  return 0;
}
```

### Dvourozměrná pole (matice)

Dvourozměrné pole lze chápat jako pole polí. K prvkům matice lze přistupovat pomocí ukazatelů a ukazatelové aritmetiky.
![Dvourozmerne pole](https://www.log2base2.com/images/c/2d-row-pointer.png)

```c++
int matice[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int *ukazatel = &matice[0][0]; // ukazatel ukazuje na první prvek matice

std::cout << *(ukazatel + 0) << std::endl; // Vypíše 1
std::cout << *(ukazatel + 1) << std::endl; // Vypíše 2
std::cout << *(ukazatel + 3) << std::endl; // Vypíše 4
std::cout << *(ukazatel + 4) << std::endl; // Vypíše 5
```

### Příklad

```c++
#include <iostream>

int main() {
  int pole[5] = {10, 20, 30, 40, 50};
  int *ukazatel = pole;

  for (int i = 0; i < 5; i++) {
    std::cout << *(ukazatel + i) << " "; // Vypíše 10 20 30 40 50
  }
  std::cout << std::endl;

  return 0;
}
```

### Cvičení

**Zadání:**

Vytvořte funkci `sectiPole(int *pole, int velikost)`, která sečte všechny prvky v poli a vrátí jejich součet. V `main` funkci deklarujte pole, naplňte ho hodnotami, zavolejte funkci `sectiPole` a vypište výsledek.
