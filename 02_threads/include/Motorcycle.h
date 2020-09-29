#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <string>

class Motorcycle{
    std::string brand_and_model;

    public:
        Motorcycle(std::string brand_and_model);
        void operator()();

};

#endif //MOTORCYCLE_H