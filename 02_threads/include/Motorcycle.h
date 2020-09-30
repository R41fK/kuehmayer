#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <string>

class Motorcycle{
    std::string brand_and_model;
    double totale_time{0};

    public:
        Motorcycle(std::string brand_and_model);
        void operator()(int rounds);
        double get_total_time();

};

#endif //MOTORCYCLE_H