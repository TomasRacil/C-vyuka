## Šablony tříd v C++

Šablony tříd v C++ umožňují definovat třídy, které pracují s různými datovými typy bez nutnosti psát kód pro každý typ zvlášť. Šablona třídy je v podstatě "vzorec" pro vytvoření konkrétní třídy s daným datovým typem.

### Deklarace šablony třídy

Šablona třídy se deklaruje pomocí klíčového slova `template` následovaného seznamem parametrů šablony v úhlových závorkách (`<>`). Parametry šablony mohou být datové typy (`typename T`) nebo konstanty (`int N`).

```c++
template <typename T, int N>
class Array {
  // Deklarace členů třídy
};
```

### Definice metod šablony třídy

Metody šablony třídy se definují stejně jako metody obyčejných tříd, ale s uvedením parametrů šablony před názvem třídy.

```c++
template <typename T, int N>
void Array<T, N>::metoda() {
  // Definice metody
}
```

### Vytvoření instance šablony třídy

Při vytváření instance šablony třídy je nutné specifikovat datové typy pro parametry šablony.

```c++
Array<int, 10> intArray; // Pole o velikosti 10 pro uložení celých čísel
Array<double, 5> doubleArray; // Pole o velikosti 5 pro uložení desetinných čísel
```

### Příklad

```c++
#include <iostream>

template <typename T>
class Box {
public:
  Box(T value) : data(value) {}

  T getValue() const { return data; }

private:
  T data;
};

int main() {
  Box<int> intBox(10);
  std::cout << "Integer value: " << intBox.getValue() << std::endl;

  Box<double> doubleBox(3.14);
  std::cout << "Double value: " << doubleBox.getValue() << std::endl;

  Box<std::string> stringBox("Hello");
  std::cout << "String value: " << stringBox.getValue() << std::endl;

  return 0;
}
```

V tomto příkladu `Box<T>` je šablona třídy, která může uchovávat hodnotu libovolného typu. V `main` funkci vytváříme instance `Box` pro `int`, `double` a `std::string`.

### Cvičení

**Zadání:**

Vytvořte šablonu třídy `Stack`, která implementuje zásobník (LIFO) pro libovolný datový typ. Třída by měla mít metody `push(T value)` pro přidání prvku na vrchol zásobníku, `pop()` pro odebrání prvku z vrcholu zásobníku a `top()` pro vrácení prvku na vrcholu zásobníku (bez odebrání).

**Tip:**

Pro uložení prvků zásobníku můžete použít `std::vector<T>`.
