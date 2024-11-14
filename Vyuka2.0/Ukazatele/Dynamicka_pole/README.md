## Dynamická pole v C++

Dynamická pole umožňují alokovat paměť pro pole za běhu programu. To je užitečné, když neznáte velikost pole předem, nebo když potřebujete měnit velikost pole během programu.

### Alokace paměti

Pro alokaci paměti pro dynamické pole se používá operátor `new[]`:

```c++
int *pole = new int[velikost]; // Alokace paměti pro pole o velikosti "velikost"
```

### Uvolnění paměti

Po skončení práce s dynamickým polem je nutné uvolnit alokovanou paměť pomocí operátoru `delete[]`:

```c++
delete[] pole;
```

### Přístup k prvkům pole

K prvkům dynamického pole se přistupuje stejně jako k prvkům statického pole, pomocí indexů:

```c++
pole[0] = 10;
pole[1] = 20;
```

### Změna velikosti pole

Změna velikosti dynamického pole je složitější než u statických polí. Je nutné alokovat novou paměť pro pole o nové velikosti, zkopírovat data ze starého pole do nového a uvolnit paměť starého pole.

### Vícerozměrná dynamická pole

Vícerozměrná dynamická pole se alokují pomocí vnořených volání `new[]`. Například pro alokaci matice 3x3:

```c++
int **matice = new int*[3]; // Alokace pole ukazatelů na řádky
for (int i = 0; i < 3; i++) {
  matice[i] = new int[3]; // Alokace paměti pro každý řádek
}
```

Uvolnění paměti se provádí v opačném pořadí:

```c++
for (int i = 0; i < 3; i++) {
  delete[] matice[i]; // Uvolnění paměti pro každý řádek
}
delete[] matice; // Uvolnění pole ukazatelů
```

### Příklad

```c++
#include <iostream>

int main() {
  int velikost;
  std::cout << "Zadejte velikost pole: ";
  std::cin >> velikost;

  int *pole = new int[velikost];

  for (int i = 0; i < velikost; i++) {
    pole[i] = i * 10;
  }

  for (int i = 0; i < velikost; i++) {
    std::cout << pole[i] << " ";
  }
  std::cout << std::endl;

  delete[] pole;

  return 0;
}
```

### Cvičení

**Zadání:**

Vytvořte funkci `vytvorMatici(int radky, int sloupce)`, která dynamicky alokuje paměť pro matici daných rozměrů a vrátí ukazatel na tuto matici. V `main` funkci zavolejte `vytvorMatici`, naplňte matici hodnotami a vypište ji na konzoli.
