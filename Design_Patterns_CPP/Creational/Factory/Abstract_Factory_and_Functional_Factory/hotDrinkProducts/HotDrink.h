#ifndef ABSTRACT_FACTORY_HOTDRINK_H
#define ABSTRACT_FACTORY_HOTDRINK_H


class HotDrink {
public:
    virtual ~HotDrink() = default;
    virtual HotDrink& prepare() = 0;
};


#endif //ABSTRACT_FACTORY_HOTDRINK_H
