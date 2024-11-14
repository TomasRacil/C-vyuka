## Chytré ukazatele v C++

Chytré ukazatele jsou speciální typy ukazatelů, které automaticky spravují paměť. To znamená, že se nemusíte starat o ruční uvolňování paměti pomocí `delete`, čímž se snižuje riziko chyb a program je bezpečnější.

### Typy chytrých ukazatelů

V C++ existuje několik typů chytrých ukazatelů:

* **`std::unique_ptr`:** Uchovává výhradní vlastnictví paměti. Když `unique_ptr` zanikne, automaticky uvolní paměť.
* **`std::shared_ptr`:** Umožňuje sdílené vlastnictví paměti. Paměť se uvolní, až když zaniknou všechny `shared_ptr` ukazující na ni.

### Deklarace a použití

Chytré ukazatele se deklarují s uvedením typu dat, na která ukazují.

```c++
#include <memory>

std::unique_ptr<int> uniquePtr(new int(10)); 
std::shared_ptr<int> sharedPtr1(new int(5));
std::shared_ptr<int> sharedPtr2 = sharedPtr1; // Sdílené vlastnictví
```

### Metody chytrých ukazatelů

* **`get()`:** Vrací surový ukazatel na paměť.
* **`reset()`:** Uvolní paměť a nastaví ukazatel na `nullptr`.

### Příklad

```c++
#include <iostream>
#include <memory>

void vypisHodnotu(std::unique_ptr<int> ptr) {
  std::cout << "Hodnota: " << *ptr << std::endl;
}

int main() {
  std::unique_ptr<int> uniquePtr(new int(10));
  vypisHodnotu(std::move(uniquePtr)); 

  std::shared_ptr<int> sharedPtr1(new int(5));
  std::shared_ptr<int> sharedPtr2 = sharedPtr1;
  std::cout << "Hodnota 1: " << *sharedPtr1 << std::endl;
  std::cout << "Hodnota 2: " << *sharedPtr2 << std::endl;

  return 0;
}
```

**Výstup:**

```
Hodnota: 10
Hodnota 1: 5
Hodnota 2: 5
```

V tomto příkladu `uniquePtr` vlastní paměť pro integer s hodnotou 10. Funkce `vypisHodnotu` přebírá vlastnictví této paměti a vypisuje hodnotu. Po skončení funkce `vypisHodnotu` se paměť automaticky uvolní.

`sharedPtr1` a `sharedPtr2` sdílí paměť pro integer s hodnotou 5. Oba ukazatele ukazují na stejnou paměťovou lokaci.

### Cvičení

**Zadání:**

Vytvořte funkci `alokujPole`, která dynamicky alokuje pole integerů o dané velikosti a vrací `std::unique_ptr<int[]>` ukazující na toto pole. V `main` funkci zavolejte `alokujPole`, naplňte pole hodnotami a vypište je na konzoli.
