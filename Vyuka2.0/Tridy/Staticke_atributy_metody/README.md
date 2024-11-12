## Statické atributy a metody v C++

V objektově orientovaném programování v C++ rozlišujeme dva základní typy členů třídy:

* **Nestatické členy:** Patří k jednotlivým **instancím** (objektům) třídy. Každá instance má vlastní kopii nestatických atributů a může volat nestatické metody.
* **Statické členy:** Patří **třídě jako celku**, nikoliv jednotlivým instancím. Existuje pouze jedna kopie statického atributu, která je sdílena všemi instancemi třídy. Statické metody se volají na třídě, nikoliv na instanci.

### Deklarace a definice

Statické členy se deklarují uvnitř třídy s klíčovým slovem `static`:

```c++
class Trida {
public:
  static int statickyAtribut;
  static void statickaMetoda();
};
```

Statické atributy je nutné **definovat** (alokovat paměť) i mimo třídu:

```c++
int Trida::statickyAtribut = 0; // Inicializace statického atributu
```

### Přístup ke statickým členům

K statickým členům se přistupuje pomocí **operátoru rozsahu (`::`)**:

```c++
Trida::statickyAtribut = 10;
Trida::statickaMetoda();
```

### Užití statických členů

Statické členy se používají v různých situacích:

* **Počítadlo instancí:** Statický atribut může uchovávat počet vytvořených instancí třídy.
* **Globální konfigurační parametry:** Statické atributy mohou uchovávat nastavení, které je společné pro celou aplikaci.
* **Pomocné funkce:** Statické metody mohou sloužit jako pomocné funkce, které nesouvisí s konkrétní instancí třídy.
* **Factory metody:** Statické metody mohou vytvářet instance třídy.

### Omezení statických metod

Statické metody **nemohou přistupovat k nestatickým členům** třídy, protože nemají k dispozici instanci.

### Příklad

```c++
#include <iostream>

class Pocitadlo {
public:
  Pocitadlo() { pocet_instanci++; }
  ~Pocitadlo() { pocet_instanci--; }

  static int getPocetInstanci() { return pocet_instanci; }

private:
  static int pocet_instanci;
};

int Pocitadlo::pocet_instanci = 0; 

int main() {
  Pocitadlo p1;
  std::cout << "Pocet instanci: " << Pocitadlo::getPocetInstanci() << std::endl; // Vypíše 1

  Pocitadlo p2;
  std::cout << "Pocet instanci: " << Pocitadlo::getPocetInstanci() << std::endl; // Vypíše 2

  return 0;
}
```

V tomto příkladu statický atribut `pocet_instanci` uchovává počet vytvořených instancí třídy `Pocitadlo`. Statická metoda `getPocetInstanci()` vrací hodnotu tohoto atributu.

## Cvičení

**Zadání:**

Vytvořte třídu `Matematika` se statickými metodami pro základní matematické operace:

* `scitani(int a, int b)`: Vrací součet čísel `a` a `b`.
* `odcitani(int a, int b)`: Vrací rozdíl čísel `a` a `b`.
* `nasobeni(int a, int b)`: Vrací součin čísel `a` a `b`.
* `deleni(int a, int b)`: Vrací podíl čísel `a` a `b`. Pokud je `b` rovno nule, vraťte 0 a vypište chybové hlášení.

V `main` funkci otestujte funkčnost těchto metod s různými vstupními hodnotami.

**Poznámka:** Statické členy by se měly používat s rozvahou. Nadměrné používání statických členů může vést k méně přehlednému a hůře udržovatelnému kódu.
