## Kontejnery v STL v C++

Standard Template Library (STL) v C++ nabízí širokou škálu kontejnerů, což jsou datové struktury pro ukládání a organizaci dat. Kontejnery STL jsou efektivní, flexibilní a snadno použitelné.

### Typy kontejnerů

STL nabízí různé typy kontejnerů, které se liší svými vlastnostmi a způsobem ukládání dat:

**Sekvenční kontejnery:**

* **`std::vector`:** Dynamické pole, umožňuje rychlý přístup k prvkům pomocí indexu.
* **`std::list`:** Dvoustranně vázaný seznam, efektivní pro vkládání a mazání prvků kdekoliv v seznamu.
* **`std::deque`:** Obousměrná fronta, kombinuje vlastnosti vektoru a listu.

**Asociativní kontejnery:**

* **`std::set`:** Množina, ukládá unikátní prvky seřazené podle hodnoty.
* **`std::map`:** Slovník, ukládá páry klíč-hodnota, kde klíče jsou unikátní a seřazené.
* **`std::multiset`:** Množina, která povoluje duplicitní prvky.
* **`std::multimap`:** Slovník, který povoluje duplicitní klíče.

**Kontejnery adaptérů:**

* **`std::stack`:** Zásobník (LIFO), umožňuje přidávat a odebírat prvky pouze z vrcholu.
* **`std::queue`:** Fronta (FIFO), umožňuje přidávat prvky na konec a odebírat je ze začátku.
* **`std::priority_queue`:** Prioritní fronta, prvky jsou řazeny podle priority.

### Vytvoření kontejneru

Kontejnery se vytvářejí s uvedením typu dat, která budou ukládat:

```c++
#include <vector>
#include <set>

std::vector<int> cisla; // Vektor pro ukládání celých čísel
std::set<std::string> jmena; // Množina pro ukládání řetězců
```

### Operace s kontejnery

Kontejnery STL nabízí mnoho metod pro práci s daty:

* **`push_back()`:** Přidá prvek na konec (pro sekvenční kontejnery).
* **`insert()`:** Vloží prvek na danou pozici.
* **`erase()`:** Smaže prvek.
* **`size()`:** Vrací počet prvků v kontejneru.
* **`empty()`:** Vrací `true`, pokud je kontejner prázdný.
* **`clear()`:** Smaže všechny prvky v kontejneru.

### Příklad

```c++
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

int main() {
  // Sekvenční kontejnery

  // Vektor
  vector<int> cisla = {1, 5, 2, 4, 3};
  cout << "Vektor: ";
  for (int cislo : cisla) {
    cout << cislo << " ";
  }
  cout << endl; // Výstup: 1 5 2 4 3

  // List
  list<string> jmena = {"Anna", "Petr", "Jan"};
  cout << "List: ";
  for (string jmeno : jmena) {
    cout << jmeno << " ";
  }
  cout << endl; // Výstup: Anna Petr Jan

  // Deque
  deque<double> teploty = {25.5, 24.8, 26.1};
  cout << "Deque: ";
  for (double teplota : teploty) {
    cout << teplota << " ";
  }
  cout << endl; // Výstup: 25.5 24.8 26.1


  // Asociativní kontejnery

  // Set
  set<char> znaky = {'a', 'c', 'b', 'a'};
  cout << "Set: ";
  for (char znak : znaky) {
    cout << znak << " ";
  }
  cout << endl; // Výstup: a b c

  // Map
  map<string, int> vek = {{"Anna", 25}, {"Petr", 30}};
  cout << "Map: ";
  for (auto const& [klic, hodnota] : vek) {
    cout << klic << ":" << hodnota << " ";
  }
  cout << endl; // Výstup: Anna:25 Petr:30


  // Kontejnery adaptérů

  // Stack
  stack<int> zasobnik;
  zasobnik.push(1);
  zasobnik.push(2);
  zasobnik.push(3);
  cout << "Zasobnik: ";
  while (!zasobnik.empty()) {
    cout << zasobnik.top() << " ";
    zasobnik.pop();
  }
  cout << endl; // Výstup: 3 2 1

  // Queue
  queue<int> fronta;
  fronta.push(1);
  fronta.push(2);
  fronta.push(3);
  cout << "Fronta: ";
  while (!fronta.empty()) {
    cout << fronta.front() << " ";
    fronta.pop();
  }
  cout << endl; // Výstup: 1 2 3

  return 0;
}
```

### Cvičení

**Zadání:**

1. **Vytvořte `std::map` pro ukládání jmen a věků osob.**
2. **Přidejte do mapy několik záznamů.**
3. **Vypište všechny záznamy v mapě.**
4. **Vyhledejte v mapě věk osoby s daným jménem.**
5. **Odstraňte z mapy záznam s daným jménem.**
