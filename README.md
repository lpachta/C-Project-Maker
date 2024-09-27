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

1. Na Releases github stránce si stáhněte nejnovější verzi CPM ( https://github.com/lpachta/C-Project-Maker/releases )((je to zip)).
2. Extrahujte zip

        unzip <název zipu>

3. Zkompilujte program
    - Pokud máte Make: 
    
            make

    - Jinak pomocí g++:

            g++ main.cpp cpm.cpp -o cpm

4. Vytvořený binární soubor (cpm) přesuňte do složky s binárkami.

        sudo cp <cesta k cpm> /usr/bin

### Instalace na Windows 

1. Na Releases github stránce si stáhněte nejnovější verzi CPM ( https://github.com/lpachta/C-Project-Maker/releases )((je to zip)).
2. Extrahujte zip
3. Zkompilujte program
- Pokud máte Make: 

        make

- Jinak pomocí g++:

        g++ main.cpp cpm.cpp -o cpm

4. Vytvořený binární soubor (cpm) přesuňte do složky s binárkami, nebo vytvořte alias.

### Instalace na MacOS

asi jak na linuxu...? idk

## Použití

Program se dá volat POUZE s argumenty a to v tomto tvaru:

    cpm {argument}

Mezi validní argumenty patří:

- {-h} // Help
- {-z} // Ze složky extrahovaného zipu inicializuje projekt: Změní název složky, přejmenuje soubory pomocí vyhledej a nahraď a vytvoří Makefile
- {-d} // Vytvoří novou složku.
- {-c} // ZKOPÍRUJ soubory ze složky do jiné (Pokud složka neexistuje, vytvoří ji.)
- {-r} // Vyhledej a nahraď v názvech souborů projektu.
- {-m} // Vytvoř Makefile.

!! MUSÍTE BÝT V RODIČOVSKÉ SLOŽCE SLOŽKY, SE KTEROU PRACUJETE !! 

Použití mimo terminál není podporován.

## Plány do budoucna 

V budoucích verzích bych rád přidal tyto funkce: 

- Přejmenování složky
- Zadávání parametrů argumenty
- Projekt template 
- Config

Kdyby jste chtěli přidat nějakou funkci, nebojte se Vidličkovat tento repozitář ;-)

Pokud najdete nějakou chybu, nebojte se otevřít Problém ;-)
