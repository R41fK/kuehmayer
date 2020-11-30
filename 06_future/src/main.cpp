#include <iostream>
#include <future>

#include "CLI11.hpp"
#include "calc_factors.h"

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

void output(vector<InfInt>& numbers, vector<future<vector<InfInt>>>& factors){
    for (unsigned int i=0; i < numbers.size(); i++) {
        cout << numbers[i] << ": ";
        for (InfInt factor : factors[i].get()) {
            cout << factor << " ";
        }
        cout << endl;
    }
}


int main(int argc, char* argv[]) {
    
    CLI::App app("factoring");

    vector<string> strings_of_numbers{}; 

    app.add_option("numbers", strings_of_numbers, "Numbers that are factored")->required()->check(validation);

    bool is_async{false};

    app.add_flag("-a, --async", is_async, "async");

    CLI11_PARSE(app, argc, argv);

    vector<InfInt> numbers{};

    for (string str : strings_of_numbers) {
        numbers.push_back(str);
    }
    
    vector<future<vector<InfInt>>> factors{};

    for (InfInt number : numbers) {
        factors.push_back(async(get_factors, number));
    }

    thread t{output, ref(numbers), ref(factors)};

    t.join();
}
