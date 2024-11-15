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
#TODO
```

### Cvičení

**Zadání:**

1. **Vytvořte `std::map` pro ukládání jmen a věků osob.**
2. **Přidejte do mapy několik záznamů.**
3. **Vypište všechny záznamy v mapě.**
4. **Vyhledejte v mapě věk osoby s daným jménem.**
5. **Odstraňte z mapy záznam s daným jménem.**
