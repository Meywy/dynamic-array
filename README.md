# Dynamické pole (C)

Jednoduchý program v jazyce C, který pracuje s dynamickým polem celých čísel.
Pole lze vytvořit, vypsat, přidávat do něj prvky, vkládat prvky na zadaný
index a odebírat prvky. Ovládání probíhá přes textové menu v terminálu.

## Struktura projektu

```
.
├── include/        # hlavičkové soubory
│   ├── array.h
│   └── menu.h
├── src/            # zdrojové soubory
│   ├── main.c
│   ├── array.c
│   └── menu.c
├── Makefile
└── CMakeLists.txt
```

## Požadavky

- Kompilátor jazyka C (např. `gcc`)
- Volitelně `make` pro pohodlné sestavení

## Sestavení pomocí Make

V adresáři projektu spusťte:

```sh
make
```

Tím se vytvoří spustitelný soubor `program`.

Další užitečné příkazy:

```sh
make run     # sestaví a spustí program
make clean   # smaže přeložené soubory a binárku
```

## Sestavení pomocí gcc (bez Make)

Projekt lze přeložit i přímo:

```sh
gcc -Wall -Wextra -Iinclude src/main.c src/array.c src/menu.c -o program
```

## Spuštění

```sh
./program
```

Po spuštění se zobrazí menu:

```
--- Array Menu ---
1. Create array
2. Print array
3. Add element
4. Insert element
5. Remove element
0. Exit
--------------------
```

Zadejte číslo volby a potvrďte klávesou Enter.

## Sestavení pomocí CMake (volitelné)

```sh
cmake -S . -B build
cmake --build build
./build/program
```

## Poznámky

- Počet prvků při vytváření pole musí být mezi 2 a 20.
- Hodnoty prvků se při vytvoření pole vygenerují náhodně (1–99).
- Při ukončení programu se paměť pole automaticky uvolní.
