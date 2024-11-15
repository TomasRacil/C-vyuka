## Iterátory v STL v C++

Iterátory v STL (Standard Template Library) jsou objekty, které umožňují procházet prvky v kontejnerech (např. `vector`, `list`, `set`, `map`). Chovají se podobně jako ukazatele, ale poskytují abstraktní rozhraní pro přístup k prvkům bez ohledu na konkrétní typ kontejneru.

### Vlastnosti iterátorů

* **Přístup k prvkům:** Iterátory umožňují číst a modifikovat prvky kontejneru.
* **Procházení:** Iterátory lze posouvat dopředu a dozadu v kontejneru (v závislosti na typu iterátoru).
* **Nezávislost na kontejneru:**  Stejné algoritmy lze použít s různými kontejnery díky iterátorům.

### Typy iterátorů

* **Input iterator:** Pouze pro čtení prvků, posun pouze dopředu.
* **Output iterator:** Pouze pro zápis prvků, posun pouze dopředu.
* **Forward iterator:** Pro čtení a zápis, posun pouze dopředu.
* **Bidirectional iterator:** Pro čtení a zápis, posun dopředu i dozadu.
* **Random access iterator:** Pro čtení a zápis, libovolný přístup k prvkům (jako u pole).

### Získání iterátoru

* **`begin()`:** Vrací iterátor na první prvek kontejneru.
* **`end()`:** Vrací iterátor za poslední prvek kontejneru.

### Operace s iterátory

* **`*iterator`:** Dereference - vrací hodnotu prvku, na který iterátor ukazuje.
* **`iterator++`:** Posune iterátor na další prvek.
* **`iterator--`:** Posune iterátor na předchozí prvek (pouze pro bidirectional a random access iterátory).
* **`iterator + n`:** Posune iterátor o n prvků dopředu (pouze pro random access iterátory).
* **`iterator - n`:** Posune iterátor o n prvků dozadu (pouze pro random access iterátory).

### Příklad

```c++
#include <iostream>
#include <vector>

int main() {
  std::vector<int> cisla = {10, 20, 30, 40, 50};

  // Vypíšeme prvky vektoru pomocí iterátoru
  for (std::vector<int>::iterator it = cisla.begin(); it != cisla.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}
```

**Výstup:**

```
10 20 30 40 50 
```

V tomto příkladu:

* `std::vector<int>::iterator it` deklaruje iterátor pro vektor celých čísel.
* Cyklus `for` prochází vektor od začátku (`cisla.begin()`) do konce (`cisla.end()`).
* `*it` vrací hodnotu prvku, na který iterátor `it` ukazuje.

### Cvičení

**Zadání:**

1. **Vytvořte vektor `std::vector<std::string>` s několika řetězci.**
2. **Vypište všechny řetězce ve vektoru pomocí iterátoru.**
3. **Pomocí iterátoru najděte a vypište první řetězec, který má délku větší než 5 znaků.**
4. **Pomocí iterátoru odstraňte ze vektoru všechny řetězce, které obsahují písmeno 'a'.**
