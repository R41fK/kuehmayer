#include <iostream>

#include "CLI11.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    
    CLI::App app("factoring");

    vector<int> numbers{}; 

    app.add_option("numbers", numbers, "Numbers that are factored")->required();

    CLI11_PARSE(app, argc, argv);

    for (int i : numbers) {
        cout << i << endl;
    }

}
