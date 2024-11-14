## Void ukazatele v C++

Void ukazatel (`void*`) je speciální typ ukazatele, který může ukazovat na data libovolného typu. To znamená, že void ukazatel může uchovávat adresu proměnné jakéhokoli datového typu (int, float, char, struktury, atd.).

### Vlastnosti void ukazatelů

* **Univerzálnost:**  Void ukazatele mohou ukazovat na jakýkoli datový typ. 
* **Neznámý typ:**  Void ukazatel "neví", jaký typ dat se nachází na adrese, na kterou ukazuje.
* **Dereference:**  Void ukazatel nelze přímo dereferencovat (pomocí operátoru `*`), protože kompilátor nezná typ dat, na která ukazuje.
* **Typové přetypování:**  Před dereferencí je nutné void ukazatel přetypovat na ukazatel konkrétního datového typu.

### Použití void ukazatelů

Void ukazatele se používají v situacích, kdy je potřeba pracovat s daty, jejichž typ není předem známý. Například:

* **Generické funkce:**  Funkce, které pracují s daty libovolného typu.
* **Dynamická alokace paměti:**  Funkce `malloc()` a `realloc()` vracejí void ukazatel na alokovanou paměť.
* **Callback funkce:**  Funkce, které se předávají jako argumenty jiným funkcím a jejichž typ není předem známý.

### Příklad

```c++
#include <iostream>

void vypisHodnotu(void *ukazatel, char typ) {
  if (typ == 'i') {
    int *intUkazatel = static_cast<int*>(ukazatel);
    std::cout << "Hodnota (int): " << *intUkazatel << std::endl;
  } else if (typ == 'd') {
    double *doubleUkazatel = static_cast<double*>(ukazatel);
    std::cout << "Hodnota (double): " << *doubleUkazatel << std::endl;
  } 
}

int main() {
  int cislo = 10;
  double desetinneCislo = 3.14;

  vypisHodnotu(&cislo, 'i'); // Vypíše "Hodnota (int): 10"
  vypisHodnotu(&desetinneCislo, 'd'); // Vypíše "Hodnota (double): 3.14"

  return 0;
}
```

V tomto příkladu funkce `vypisHodnotu` přijímá void ukazatel a znak specifikující typ dat. Podle typu dat se void ukazatel přetypovává na konkrétní typ a vypisuje se jeho hodnota.

### Cvičení

**Zadání:**

Vytvořte funkci `prohod(void *a, void *b, int velikost)`, která prohodí obsah dvou paměťových bloků dané velikosti. V `main` funkci deklarujte proměnné různých typů (např. int a double), zavolejte funkci `prohod` a vypište hodnoty proměnných před a po prohození. 

**Tip:**
1. [Funkce `memcpy`](https://en.cppreference.com/w/cpp/string/byte/memcpy)
2. Pro prohození obsahu paměťových bloků můžete použít pomocné pole o velikosti `velikost`.
