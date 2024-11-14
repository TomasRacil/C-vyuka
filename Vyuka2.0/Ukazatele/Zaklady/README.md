## Základy ukazatelů v C++

Ukazatele jsou proměnné, které uchovávají paměťovou adresu jiné proměnné. Umožňují přímý přístup k paměti a manipulaci s daty uloženými v paměti.

![Pointer](https://hackingcpp.com/cpp/lang/pointers1.svg)

### Deklarace ukazatele

Ukazatel se deklaruje s uvedením typu dat, na která ukazuje, a symbolem hvězdičky (`*`).

```c++
int *ukazatelNaInt; // Ukazatel na integer
double *ukazatelNaDouble; // Ukazatel na double
char *ukazatelNaChar; // Ukazatel na znak
```

### Operátor adresy (`&`)

Operátor adresy (`&`) vrací paměťovou adresu proměnné.

```c++
int cislo = 10;
int *ukazatel = &cislo; // ukazatel nyní ukazuje na adresu proměnné cislo
```

### Operátor dereference (`*`)

Operátor dereference (`*`) vrací hodnotu uloženou na paměťové adrese, na kterou ukazatel ukazuje.

```c++
int cislo = 10;
int *ukazatel = &cislo;
std::cout << *ukazatel << std::endl; // Vypíše 10
```

### Ukazatele a funkce

Ukazatele lze předávat jako argumenty funkcím. To umožňuje funkci modifikovat hodnoty proměnných v volající funkci.

```c++
void zvysCislo(int *cislo) {
  (*cislo)++;
}

int main() {
  int cislo = 5;
  zvysCislo(&cislo);
  std::cout << cislo << std::endl; // Vypíše 6
  return 0;
}
```

### Příklad

```c++
#include <iostream>

int main() {
  int cislo = 10;
  int *ukazatel = &cislo;

  std::cout << "Hodnota cislo: " << cislo << std::endl; // Vypíše 10
  std::cout << "Adresa cislo: " << &cislo << std::endl; // Vypíše adresu cislo
  std::cout << "Hodnota ukazatel: " << ukazatel << std::endl; // Vypíše adresu cislo
  std::cout << "Hodnota *ukazatel: " << *ukazatel << std::endl; // Vypíše 10

  *ukazatel = 20; // Změna hodnoty cislo prostřednictvím ukazatele
  std::cout << "Hodnota cislo po zmene: " << cislo << std::endl; // Vypíše 20

  return 0;
}
```

### Cvičení

**Zadání:**

Vytvořte funkci `prohod(int *a, int *b)`, která prohodí hodnoty dvou proměnných předaných jako ukazatele. V `main` funkci deklarujte dvě proměnné, zavolejte funkci `prohod` a vypište hodnoty proměnných před a po prohození.
