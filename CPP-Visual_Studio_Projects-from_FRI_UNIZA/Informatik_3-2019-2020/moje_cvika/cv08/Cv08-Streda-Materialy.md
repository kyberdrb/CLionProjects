- Cvicenie 8
    - References
        - https://www.learncpp.com/cpp-tutorial/611-references/
    - Exceptions
        - Exceptions enable us to decouple the occurence of a fail state from the handling of the failure.
        - Learn Advanced C++ Programming: https://www.youtube.com/playlist?list=PLw_k9CF7hBpJKHeOFXOHOyy_KuR06aLqt
            - Videos `002` bis `005`
        - Exception-Safe Function Calls: https://herbsutter.com/gotw/_102/
    - **Prednaska 7 - Objektovo-orientovany vstup/vystup - Prudy (streams)**
        - konverzia medzi formatmi, napr. pri nacitavani zo input streamu (subor, konzola) sa nacitava vstup ako `std::string` a stream ho konvertuje podla toho, do akej premennej sa priraduje, napr. na `int`
    - Containers
        - `std::vector`
            - C++ equivalent of an `ArrayList` in Java
            - `ArrayList` vs `std::vector` method names
                - add: push_back / emplace_back / insert
                - remove: erase
                - get: at / `operator[]`
                - isEmpty: empty
                - size: size
            - Learn Advanced C++ Programming: https://www.youtube.com/playlist?list=PLw_k9CF7hBpJKHeOFXOHOyy_KuR06aLqt
                - Videos `011` bis `013`
            - For each loops: https://www.learncpp.com/cpp-tutorial/6-12a-for-each-loops/
            - upravit projekt z piateho tyzdna - trojuholniky
                - pridat trojuholniky do udajovej struktury `std::vector`
                - vypisat vsetky trojuholniky vo vektore
                - pre dynamicky alokovane objekty pouzit genericky typ `std::vector<Triangle*>`. Do vektora ich pridame metodou `emplace_back(new Triangle...)`.
                - Po vypisani vsetkych dynamicky vytvorenych trojuholnikov dealokovat z vektora vsetky instancie a nastavit ich na `nullptr`. Potom odstranit vsetky prvky z vektora
                - vytvorit novy dynamicky alokovany trojuholnik ako `std::unique_ptr`
        - `std::list`
            - C++ equivalent of an LinkedList in Java
    - Templates / Template Meta-Programming
        - function templates
        - class templates
            - Learn Advanced C++ Programming: https://www.youtube.com/playlist?list=PLw_k9CF7hBpJKHeOFXOHOyy_KuR06aLqt
                - RingBuffer: Videos `029` - `032`

    - Composition, Aggregation, Association
        - learncpp.com : Chapter 10
    - Inheritance and Polymorphism
        - learncpp.com : Chapter 11 (except 11.5), Chapter 12