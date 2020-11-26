#include <iostream>

#include "CLI11.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "InfInt.h"
#pragma GCC diagnostic pop

using namespace std;



string validation(const string& str){
    size_t found{str.find_first_not_of("0123456789")};

    if (found <= str.length()) {
        return str + " is not a Integer";
    }
    return "";
}


int main(int argc, char* argv[]) {
    
    CLI::App app("factoring");

    vector<string> numbers{}; 

    app.add_option("numbers", numbers, "Numbers that are factored")->required()->check(validation);

    CLI11_PARSE(app, argc, argv);

    vector<InfInt> factoring{};

    for (string str : numbers) {
        factoring.push_back(str);
        cout << factoring.back() << endl;
    }
    
    
}
