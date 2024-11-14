## Memory leaks a ukazatele v C++

Memory leak (únik paměti) nastává, když program alokuje paměť, ale po skončení práce s ní ji neuvolní. To může vést k postupnému vyčerpání dostupné paměti a nakonec k pádu programu nebo celého systému. Ukazatele v C++ hrají v problematice memory leaks klíčovou roli, protože umožňují přímou manipulaci s pamětí.

### Jak vznikají memory leaks s ukazateli?

* **Dynamická alokace:**  Při dynamické alokaci paměti pomocí `new` je nutné po skončení práce s pamětí explicitně volat `delete` pro její uvolnění. Pokud se `delete` nezavolá, paměť zůstane alokovaná, i když se k ní už nelze dostat.
* **Ztráta ukazatele:**  Pokud ukazatel, který ukazuje na dynamicky alokovanou paměť, přestane ukazovat na tuto paměť (např. se přepíše jinou hodnotou), paměť se stane nedostupnou, ale zůstane alokovaná.

### Příklad memory leak

```c++
#include <iostream>

void funkce() {
  int *ukazatel = new int(10);
  // ... kód, který pracuje s ukazatelem ...
  // chybí delete ukazatel; 
} // ukazatel zaniká na konci funkce, ale paměť zůstává alokovaná

int main() {
  funkce();
  // ... zbytek programu ...
  return 0;
}
```

V tomto příkladu se v  funkci `funkce()` alokuje paměť pro integer, ale neuvolní se. Po skončení funkce `funkce()` se ukazatel `ukazatel` zničí, ale paměť, na kterou ukazoval, zůstává alokovaná a stává se nedostupnou.

### Prevence memory leaks

* **Používejte chytré ukazatele:**  Chytré ukazatele (`std::unique_ptr`, `std::shared_ptr`) automaticky spravují paměť a zabraňují memory leaks.
* **Vždy uvolňujte paměť:**  Po skončení práce s dynamicky alokovanou pamětí vždy zavolejte `delete` (nebo `delete[]` pro pole).
* **Dávejte pozor na ztrátu ukazatelů:**  Ujistěte se, že ukazatele na dynamicky alokovanou paměť zůstávají platné a neukazují na jinou paměť.

### Detekce memory leaks

* **Valgrind:**  Valgrind je nástroj pro detekci memory leaks a dalších chyb v C/C++ programech.
* **Ladící nástroje:**  Mnoho IDE (integrovaných vývojových prostředí) má vestavěné nástroje pro detekci memory leaks.

### Cvičení

**Zadání:**

1. **Napište program, který alokuje paměť pro dynamické pole integerů.**
2. **Naplňte pole hodnotami.**
3. **Záměrně vynechejte uvolnění paměti pomocí `delete[]`.**
4. **Spusťte program s Valgrindem a ověřte, že Valgrind detekuje memory leak.** 
```shell
g++ -g source.cpp  -o source && valgrind --leak-check=yes ./source
``` 
5. **Opravte program přidáním `delete[]` a ověřte, že Valgrind už nehlásí memory leak.**
