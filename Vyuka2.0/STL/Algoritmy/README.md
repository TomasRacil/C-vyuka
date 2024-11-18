## STL algoritmy v C++

Standard Template Library (STL) v C++ nabízí sadu výkonných algoritmů pro práci s kontejnery. Tyto algoritmy jsou generické, což znamená, že je lze použít s různými typy kontejnerů a datovými typy.

### Hlavičkové soubory

Pro použití STL algoritmů je nutné zahrnout hlavičkový soubor `<algorithm>`. Některé algoritmy mohou vyžadovat i další hlavičkové soubory, například `<numeric>` pro numerické algoritmy.

### Iterátory

STL algoritmy pracují s iterátory, které slouží k procházení prvků v kontejneru. Iterátory se chovají podobně jako ukazatele a umožňují přístup k jednotlivým prvkům.

### Kategorie algoritmů

STL algoritmy lze rozdělit do několika kategorií:

* **Ne-modifikující algoritmy:** Tyto algoritmy nemodifikují prvky v kontejneru. Například `std::find`, `std::count`, `std::search`.
* **Modifikující algoritmy:** Tyto algoritmy modifikují prvky v kontejneru. Například `std::copy`, `std::transform`, `std::sort`, `std::remove`.
* **Numerické algoritmy:** Tyto algoritmy provádějí numerické operace s prvky v kontejneru. Například `std::accumulate`, `std::inner_product`, `std::partial_sum`.

### Příklad

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> cisla = {5, 2, 8, 1, 9};

  // Seřazení vektoru
  sort(cisla.begin(), cisla.end());

  // Výpis seřazeného vektoru
  cout << "Seřazený vektor: ";
  for (int cislo : cisla) {
    cout << cislo << " ";
  }
  cout << endl; // Výstup: 1 2 5 8 9

  // Nalezení prvku
  auto it = find(cisla.begin(), cisla.end(), 5);
  if (it != cisla.end()) {
    cout << "Prvek 5 nalezen na pozici " << distance(cisla.begin(), it) << endl;
  }

  return 0;
}
```

V tomto příkladu je použit algoritmus `std::sort` pro seřazení vektoru a algoritmus `std::find` pro nalezení prvku v seřazeném vektoru.

### Cvičení

**Zadání:**

1. **Vytvořte vektor celých čísel.**
2. **Použijte algoritmus `std::generate` k naplňění vektoru náhodnými čísly.**
3. **Použijte algoritmus `std::for_each` k výpisu všech prvků vektoru.**
4. **Použijte algoritmus `std::transform` k vynásobení všech prvků vektoru číslem 2.**
5. **Použijte algoritmus `std::accumulate` k výpočtu součtu všech prvků v vektoru.**
6. **Použijte algoritmus `std::max_element` k nalezení největšího prvku v vektoru.**
7. **Použijte algoritmus `std::remove_if` k odstranění všech sudých čísel z vektoru.**
8. **Vypište upravený vektor.**
