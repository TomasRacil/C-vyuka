## Rozdělování kódu do více souborů v C++

Při psaní větších programů v C++ je vhodné rozdělit kód do více souborů. To přináší několik výhod:

* **Přehlednost:** Kód je lépe organizovaný a čitelnější.
* **Údržba:** Snadnější údržba a ladění kódu.
* **Modularita:** Kód je rozdělen na logické celky (moduly), které lze snadno znovu použít v jiných projektech.
* **Kompilace:** Rychlejší kompilace, protože se překládají pouze změněné soubory.

### Typy souborů

V C++ se typicky používají tyto typy souborů:

* **Hlavičkový soubor (.h, .hpp):** Deklarace tříd, funkcí, proměnných a konstant.
* **Zdrojový soubor (.cpp):** Definice funkcí a metod tříd.

### Hlavičkový soubor

Hlavičkový soubor obsahuje deklarace, které informují kompilátor o existenci tříd, funkcí a proměnných. Obsahuje také direktivy preprocesoru, jako je `#include` pro zahrnutí dalších hlavičkových souborů a `#define` pro definici maker.

**Příklad hlavičkového souboru (person.h):**

```c++
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
  Person(std::string jmeno, int vek);
  std::string getJmeno();
  int getVek();

private:
  std::string jmeno;
  int vek;
};

#endif
```

### Zdrojový soubor

Zdrojový soubor obsahuje definice funkcí a metod tříd. Zahrnuje hlavičkové soubory, které deklarují používané třídy a funkce.

**Příklad zdrojového souboru (person.cpp):**

```c++
#include "person.h"

Person::Person(std::string jmeno, int vek) : jmeno(jmeno), vek(vek) {}

std::string Person::getJmeno() {
  return jmeno;
}

int Person::getVek() {
  return vek;
}
```

### Hlídání hlaviček

Direktivy `#ifndef`, `#define` a `#endif` v hlavičkovém souboru slouží k **hlídaní hlaviček**. Zabraňují vícenásobnému zahrnutí stejného hlavičkového souboru, což by mohlo vést k chybám kompilace.

### Kompilace

Při kompilaci se zdrojové soubory a zahrnuté hlavičkové soubory přeloží do objektových souborů (.o, .obj). Tyto objektové soubory se pak spojí (linkují) do spustitelného souboru.

### Příklad použití

**Hlavní program (source.cpp):**

```c++
#include <iostream>
#include "person.h"

int main() {
  Person osoba("Jan", 30);
  std::cout << "Jmeno: " << osoba.getJmeno() << std::endl;
  std::cout << "Vek: " << osoba.getVek() << std::endl;

  return 0;
}
```

**Kompilace (g++):**

```bash
g++ source.cpp person.cpp -o program
```

Tento příkaz zkompiluje soubory `source.cpp` a `person.cpp` a vytvoří spustitelný soubor `program`.

### Závěr

Rozdělení kódu do více souborů je důležitá technika pro psaní větších a komplexnějších programů v C++. Pomáhá udržovat kód organizovaný, čitelný a snadno udržovatelný.


### Cvičení

**Zadání:**

Vytvořte program pro evidenci knih v knihovně. Program by měl umožňovat přidávání, mazání a vyhledávání knih.

1. **Definujte třídu `Kniha` v souboru `kniha.h`:**
   * Atributy: `nazev` (řetězec), `autor` (řetězec), `rokVydani` (celé číslo)
   * Metody: gettery a settery pro všechny atributy, konstruktor

2. **Implementujte metody třídy `Kniha` v souboru `kniha.cpp`**

3. **Vytvořte třídu `Knihovna` v souboru `knihovna.h`:**
   * Atribut: `seznamKnih` (dynamické pole objektů typu `Kniha`)
   * Metody:
     * `pridejKnihu(Kniha kniha)`: Přidá knihu do seznamu.
     * `odeberKnihu(std::string nazev)`: Odebere knihu ze seznamu podle názvu.
     * `najdiKnihu(std::string nazev)`: Vyhledá knihu v seznamu podle názvu a vrátí ji.
     * `vypisKnihy()`: Vypíše všechny knihy v seznamu.

4. **Implementujte metody třídy `Knihovna` v souboru `knihovna.cpp`**

5. **Vytvořte soubor `source.cpp`:**
   * Vytvořte instanci třídy `Knihovna`.
   * Vytvořte menu s možnostmi:
     * Přidat knihu
     * Odebrat knihu
     * Vyhledat knihu
     * Vypiš všechny knihy
     * Konec

6. **Zkompilujte a spusťte program.**

**Bonus:**

* Implementujte ukládání a načítání seznamu knih do/ze souboru.
* Přidejte do třídy `Kniha` atribut `ISBN` a implementujte vyhledávání podle ISBN.
* Vytvořte grafické uživatelské rozhraní (GUI) pro program.