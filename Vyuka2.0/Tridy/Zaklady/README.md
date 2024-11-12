## Základy tříd v C++

Třídy jsou základním stavebním kamenem objektově orientovaného programování (OOP) v C++. Umožňují seskupovat data a funkce, které s těmito daty pracují, do jednoho celku.

### Definice třídy

Třída se definuje pomocí klíčového slova `class` následovaného názvem třídy a složenými závorkami. Uvnitř složených závorek se deklarují **členy třídy**, což mohou být **atributy** (data) a **metody** (funkce).

```c++
class NazevTridy {
  // Deklarace atributů a metod
};
```

### Atributy

Atributy reprezentují data, která jsou spojena s třídou. Mohou mít různé datové typy (int, float, bool, string atd.).

```c++
class Person {
public:
  string jmeno;
  int vek;
};
```

### Metody

Metody jsou funkce, které pracují s daty třídy. Mohou měnit hodnoty atributů, provádět výpočty nebo vykonávat jiné akce.

```c++
class Person {
public:
  string jmeno;
  int vek;

  void pozdrav() {
    cout << "Ahoj, jmenuji se " << jmeno << " a je mi " << vek << " let." << endl;
  }
};
```

### Objekty

Objekt je **instance** třídy. Je to konkrétní entita, která má specifické hodnoty atributů.

```c++
Person osoba1;
osoba1.jmeno = "Jan";
osoba1.vek = 30;
osoba1.pozdrav(); // Vypíše "Ahoj, jmenuji se Jan a je mi 30 let."
```

### Zapouzdření

Zapouzdření je jeden z klíčových principů OOP. Znamená to, že data (atributy) jsou skryta uvnitř třídy a přístup k nim je možný pouze prostřednictvím metod. To chrání data před nechtěnou modifikací a umožňuje kontrolovat přístup k nim.

Klíčová slova `public`, `private` a `protected` se používají k řízení přístupu k členům třídy.

* **`public`:** Členy jsou přístupné odkudkoliv.
* **`private`:** Členy jsou přístupné pouze z metod dané třídy.
* **`protected`:** Členy jsou přístupné z metod dané třídy a z metod odvozených tříd (dědičnost).

### Příklad

```c++
#include <iostream>
#include <string>

using namespace std;

class Kruh {
private:
  double polomer;

public:
  // Konstruktor
  Kruh(double r) {
    polomer = r;
  }

  // Metoda pro výpočet obsahu
  double obsah() {
    return 3.14159 * polomer * polomer;
  }

  // Metoda pro výpočet obvodu
  double obvod() {
    return 2 * 3.14159 * polomer;
  }
};

int main() {
  Kruh k1(5);
  cout << "Obsah kruhu: " << k1.obsah() << endl;
  cout << "Obvod kruhu: " << k1.obvod() << endl;

  return 0;
}
```

V tomto příkladu je definována třída `Kruh` s privátním atributem `polomer` a veřejnými metodami `obsah()` a `obvod()`. V `main` funkci se vytvoří instance třídy `Kruh` a volají se její metody pro výpočet obsahu a obvodu.

### Závěr

Třídy jsou základem OOP a umožňují vytvářet komplexní a modulární programy. Důležité je pochopit principy zapouzdření a jak pracovat s atributy a metodami třídy.

### Cvičení

**Zadání:**

Vytvořte třídu `Obdelnik` s následujícími atributy:

* `delka`: Délka obdélníku (celé číslo)
* `sirka`: Šířka obdélníku (celé číslo)

Atributy by měly být privátní.

Dále definujte následující metody:

* **Konstruktor `Obdelnik(int delka, int sirka)`:** Inicializuje nový obdélník s danou délkou a šířkou.
* **`getDelka()`:** Vrací délku obdélníku.
* **`getSirka()`:** Vrací šířku obdélníku.
* **`setDelka(int delka)`:** Nastavuje délku obdélníku.
* **`setSirka(int sirka)`:** Nastavuje šířku obdélníku.
* **`obsah()`:** Vypočítá a vrací obsah obdélníku.
* **`obvod()`:** Vypočítá a vrací obvod obdélníku.

V `main` funkci vytvořte instanci třídy `Obdelnik` a otestujte funkčnost všech metod. Vypište na konzoli délku, šířku, obsah a obvod obdélníku.

**Bonus:**

* Přidejte do třídy `Obdelnik` metodu `jeCtverec()`, která vrací `true`, pokud je obdélník čtverec, a `false` v opačném případě.
* Upravte metody `setDelka()` a `setSirka()` tak, aby nepřijímaly záporné hodnoty. Pokud je zadána záporná hodnota, vypište chybové hlášení a nenastavujte atribut.

