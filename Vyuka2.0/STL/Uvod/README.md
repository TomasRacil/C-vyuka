## Úvod do STL v C++

Standard Template Library (STL) je sada knihoven v C++, která poskytuje kolekce datových struktur (kontejnery) a algoritmy pro práci s nimi. STL je klíčovou součástí moderního C++ a usnadňuje psaní efektivního a robustního kódu.

### Hlavní komponenty STL

STL se skládá ze tří hlavních komponent:

* **Kontejnery:** Uchovávají data. Mezi nejčastěji používané kontejnery patří `vector`, `list`, `set`, `map` a `queue`.
* **Iterátory:** Umožňují procházet prvky kontejnerů.
* **Algoritmy:** Poskytují funkce pro práci s kontejnery, jako je vyhledávání, řazení, kopírování a modifikace prvků.

### Příklad: Použití vektoru a algoritmu `sort`

```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  // Vytvoření vektoru celých čísel
  std::vector<int> cisla = {5, 2, 8, 1, 9};

  // Výpis neřazeného vektoru
  std::cout << "Nerazena cisla: ";
  for (int cislo : cisla) {
    std::cout << cislo << " ";
  }
  std::cout << std::endl;

  // Seřazení vektoru pomocí algoritmu sort
  std::sort(cisla.begin(), cisla.end());

  // Výpis seřazeného vektoru
  std::cout << "Serazena cisla: ";
  for (int cislo : cisla) {
    std::cout << cislo << " ";
  }
  std::cout << std::endl;

  return 0;
}
```

**Výstup:**

```
Nerazena cisla: 5 2 8 1 9 
Serazena cisla: 1 2 5 8 9 
```

V tomto příkladu:

* `std::vector<int>` deklaruje vektor pro ukládání celých čísel.
* `cisla.begin()` a `cisla.end()` jsou iterátory, které označují začátek a konec vektoru.
* `std::sort` je algoritmus, který seřadí prvky ve vektoru.

### Výhody STL

* **Efektivita:** STL kontejnery a algoritmy jsou optimalizované pro výkon.
* **Znovupoužitelnost:** STL komponenty lze snadno používat v různých projektech.
* **Rozšiřitelnost:** STL umožňuje definovat vlastní kontejnery a algoritmy.
* **Standardizace:** STL je součástí standardní knihovny C++, takže je dostupná na všech platformách.
