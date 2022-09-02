# Cv05

- Definovat funkciu, ktora zisti, ci sa zo zadanych dlzok stran da skonstruovat trojuholnik (dalej len _funkcia pre trojuholnik_).
- Vo funkcii `main` odskusat funkciu pre trojuholnik s pevne zadanymi argumentami. Odskusanie moze byt napr. vypisom na konzolu:
    - `0` pre neskonstruovatelny trojuholnik,
    - `1` pre skonstruovatelny.

---

- Vytvorit triedu `Trojuholnik`.
    - kazdej strane patri samostatny atribut
    - Konstruktor pre kazdu stranu pomocou inicializacneho zoznamu. Kazdy argument ma predvolenu hodnotu nastavenu na `1`, `1`, `sqrt(2)`, t. j. pravouhly trojuholnik s odvesnami jednotkovej dlzky.
- V `main.cpp` pridat funkciu pre trojuholnik s rovnakym nazvom tak, aby funkcia prijala jeden vstupny argument: referenciu na konstantny trojuholnik (Overloading).
- Vo funkcii `main` vytvorit instanciu trojuholnika na halde. Vytvorit trojuholnik bez argumentov v konstruktore a so vsetkymi troma argumentami. Odskusat funkciu pre trojuholnik. Pamatat na dealokaciu instancie, bude cez operator `delete`, alebo cez `std::unique_ptr`.

---

- **Presunut** funkciu pre trojuholnik do triedy Trojuholnik. Funkcia v triede Trojuholnik bude bezparametricka.
- V `main.cpp` **odstranit** obidve funkcie pre trojuholnik.
- Vo funkcii `main` zavolat funkciu pre trojuholnik z instancie.

---

- V triede trojuholnik definovat funkciu na vypis stran trojuholnika.
- V `main.cpp` zavolat tuto funkciu pri vypise trojuholnika spolu s vypisom, ci sa trojuholnik da skonstruovat.

---

- Definovat kopirovaci konstruktor pre trojuholnik
- Vo funkcii `main` vytvorit dalsi trojuholnik podla uz existujuceho na stacku a na halde (Inicializacia pri kopirovani - Copy Initialization).

        Triangle t4(2, 3, 4);
        Triangle t5 = t4;

        Triangle* t6 = new Triangle(4, 5, 6);
        Triangle* t7 = new Triangle(*t6);

---

- Definovat kopirovaci operator priradenia pre trojuholnik. Pamatajte na kontrolu samopriradenia (self assignment).
- Vo funkcii `main` najprv vytvorit dalsi trojuholnik. Potom priradit do noveho trojuholnika uz existujuci.

        Triangle t8(2, 3, 4);
        Triangle t9(5, 6, 7);
        t9 = t8;

        Triangle* t10 = new Triangle(4, 5, 6);
        Triangle* t11 = new Triangle(7, 8, 9);
        *t10 = *t11;

---

- Pretazit vystupny operator t. j. _stream insertion operator_ ako `friend` funkciu. 
    Umozni priame vypisanie instancie do streamu (prudu), napr. prikazom `std::cout << instancia;`.
    Operator vypise strany trojuholnika spolu s informaciou, ci je skonstruovatelny. Kazda informacia je jednoznacne oddelena.

---

- Zmenit jeden atribut v trojuholniku na smernik na ciselny typ. Alokovat tento atribut v dynamickej pamati v konstruktore a inicializovat ho.

## Zdroje

- Predvolene hodnoty argumentov
    - https://en.cppreference.com/w/cpp/language/default_arguments
- Overloading the `<<` operator: https://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
- Copy Constructor:
    - https://www.udemy.com/course/free-learn-c-tutorial-beginners/learn/lecture/1747870#overview
    - https://stackoverflow.com/questions/15055926/copy-constructor-with-heap-pointers
- Copy assignment operator
    - Self assignment check in assignment operator: https://www.geeksforgeeks.org/g-fact-38/

### Teoria

- Implicitne clenske funkcie - automaticky generovane funkcie pre kazdu triedu:
    - https://stackoverflow.com/questions/14868154/implicit-member-functions-of-a-class-in-c
    - http://www.cplusplus.com/doc/tutorial/classes2/