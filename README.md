# C-Project-Maker

CPM je jednoduchý program sloužící k tvorbě C/C++ projektů.

## Co to umí?

Mezi využití CPM patří:

- Vytvoření nové složky, zkopírování složky z extrahovaného archivu a nahrazení Kačera Donalda za vaše jméno
- Vytvoření Makefile

## Proč? 

Chtěl jsem zautomatizovat přejmenování souborů a vytvoření Makefajlu.

## Instalace

### Dependence

Pro instalaci a provoz programu je nutné mít nainstalované:

- Kompilátor C++ (např. gcc: https://gcc.gnu.org/install/)

Doporučuji mít nainstalované:

- Make (asi https://gnuwin32.sourceforge.net/packages/make.htm)

### Instalace na Linux

1. Na Releases github stránce si stáhněte nejnovější verzi CPM (https://github.com/lpachta/C-Project-Maker/releases)((je to zip)).
2. Extrahujte zip

    `unzip <název zipu>`

3. Zkompilujte program
    - Pokud máte Make: 

    `make`

    - Jinak:

    `g++ main.cpp cpm.cpp -o cpm`

4. Vytvořený binární soubor (cpm) přesuňte do složky s binárky.

    `sudo cp <cesta k cpm> /usr/bin`

### Instalace na Windows

### Instalace na MacOS

## Plány do budoucna 

V budoucích verzích bych rád přidal tyto funkce: 

- Přejmenování složky
- Zadávání parametrů argumenty
- Projekt template 
- Config
