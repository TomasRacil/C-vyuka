# Třídicí algoritmy

Tento dokument shrnuje základní pojmy týkající se třídění dat a popisuje principy vybraných třídicích algoritmů.

## Základní pojmy

* **Třídění:** Proces uspořádání prvků v určitém pořadí (např. vzestupně, sestupně) podle daného kritéria.
* **Setříděná posloupnost:** Posloupnost prvků, které jsou uspořádány podle daného kritéria.

### Stabilita třídění

Stabilita třídicího algoritmu určuje, jak se algoritmus chová k prvkům se stejným klíčem (hodnotou, podle které se třídí). 

* **Stabilní algoritmus:** Zachovává původní relativní pořadí stejných prvků. 
    * **Příklad:** Máme seznam studentů seřazený podle jména. Pokud je seřadíme stabilním algoritmem podle věku, studenti se stejným věkem zůstanou seřazeni podle abecedy.
* **Nestabilní algoritmus:** Nemusí zachovat původní pořadí stejných prvků. 
    * **Příklad:** Při použití nestabilního algoritmu na stejném seznamu studentů by se studenti se stejným věkem mohli objevit v libovolném pořadí.

> **Proč je stabilita důležitá?**
>
> Stabilita je důležitá v situacích, kdy data již byla setříděna podle jednoho kritéria a chceme je setřídit podle dalšího kritéria, aniž bychom narušili původní pořadí.


### Složitost algoritmu

Složitost algoritmu vyjadřuje jeho efektivitu. Měří se z hlediska:

* **Časové složitosti:** Udává, jak dlouho algoritmus trvá v závislosti na velikosti vstupních dat (např. počet prvků v poli). 
* **Prostorové složitosti:** Udává, kolik paměti algoritmus spotřebuje v závislosti na velikosti vstupních dat.

#### Notace "velké O"

Složitost se obvykle vyjadřuje pomocí notace "velké O", která popisuje horní hranici růstu funkce. Například:

* **O(1):** Konstantní složitost - čas/paměť se nemění s velikostí dat.
* **O(n):** Lineární složitost - čas/paměť roste lineárně s velikostí dat.
* **O(n^2):** Kvadratická složitost - čas/paměť roste s druhou mocninou velikosti dat.
* **O(log n):** Logaritmická složitost - čas/paměť roste logaritmicky s velikostí dat.
* **O(n log n):**  Lineárně-logaritmická složitost - kombinace lineární a logaritmické složitosti.

**Příklad:**

Selection sort má časovou složitost O(n^2). To znamená, že pokud zdvojnásobíme počet prvků v poli, čas potřebný k setřídění se zvětší zhruba čtyřikrát.

> **Proč je složitost důležitá?**
> 
> Složitost algoritmu je klíčová pro jeho efektivitu, zejména při práci s velkými datovými sadami. Algoritmus s nižší složitostí bude pracovat rychleji a spotřebuje méně paměti.

## Třídicí algoritmy

### Selection sort (třídění výběrem)

**Princip:**

1. Algoritmus prochází nesetříděnou část pole a hledá v ní nejmenší prvek.
2. Nalezený nejmenší prvek prohodí s prvním prvkem nesetříděné části.
3. Tím se první prvek stává součástí setříděné části pole.
4. Algoritmus se opakuje pro zbytek nesetříděné části, dokud není celé pole setříděné.

**Ilustrace:**

![alt selection sort ilustration](https://tutorialhorizon.com/static/media/algorithms/2019/01/Selection-Sort-Gif.gif)

**Vlastnosti:**

* Jednoduchá implementace.
* Neefektivní pro velké datové sady (časová složitost O(n^2)).
* Nestabilní třídění (může změnit pořadí stejných prvků).

### Bubble sort (bublinkové třídění)

**Princip:**

1. Algoritmus prochází pole a porovnává sousední prvky.
2. Pokud jsou sousední prvky v nesprávném pořadí, prohodí je.
3. Tímto způsobem se "bublají" větší prvky směrem ke konci pole.
4. Algoritmus opakuje procházení pole, dokud nejsou všechny prvky na svém místě.

**Ilustrace:**

![alt bubble sort ilustration](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)

**Vlastnosti:**

* Jednoduchá implementace.
* Neefektivní pro velké datové sady (časová složitost O(n^2)).
* Stabilní třídění (zachovává pořadí stejných prvků).
* Lze optimalizovat: Pokud v průběhu procházení nedojde k žádné výměně, pole je již setříděné a algoritmus se může zastavit.

### Insertion sort (třídění vkládáním)

**Princip:**

1. Algoritmus postupně prochází prvky v nesetříděné části pole.
2. Pro každý prvek hledá správné místo v již setříděné části pole a vloží ho tam.
3. Vkládání se provádí posouváním prvků v setříděné části, aby se uvolnilo místo pro vkládaný prvek.

**Ilustrace:**

![alt insertion sort ilustration](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

**Vlastnosti:**

* Efektivní pro malé datové sady a téměř setříděná data (v nejlepším případě O(n)).
* Neefektivní pro velké nesetříděné datové sady (časová složitost O(n^2)).
* Stabilní třídění (zachovává pořadí stejných prvků).


### Merge sort (třídění slučováním)

**Princip:**

1. **Rozděl:** Pole se rekurzivně rozděluje na menší podpole, dokud nezískáme podpole o jednom prvku (triviálně setříděné).
2. **Sjednoť:** Setříděná podpole se slučují do větších setříděných polí. Slučování probíhá tak, že se porovnávají prvky z obou polí a menší z nich se vloží do výsledného pole.

**Ilustrace:**

![alt merge sort ilustration](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)

**Vlastnosti:**

* Efektivní pro velké datové sady (časová složitost O(n log n) v všech případech).
* Stabilní třídění (zachovává pořadí stejných prvků).
* Vyšší prostorová složitost (potřebuje pomocnou paměť pro slučování).
* Vhodný pro třídění dat na externích úložištích (např. pevný disk).

### Quick sort (rychlé třídění)

**Princip:**

1. **Vyber pivot:** Z pole se vybere prvek, tzv. pivot.
2. **Rozděl:** Pole se rozdělí na dvě části: prvky menší než pivot a prvky větší než pivot.
3. **Zpracuj rekurzivně:** Obě části se rekurzivně třídí stejným způsobem.

**Ilustrace:**

![alt quicksort (hoare) ilustration](https://upload.wikimedia.org/wikipedia/commons/9/9c/Quicksort-example.gif)

**Vlastnosti:**

* Obecně velmi efektivní pro velké datové sady (průměrná časová složitost O(n log n)).
* Nestabilní třídění (může změnit pořadí stejných prvků).
* V nejhorším případě (špatně zvolený pivot) může