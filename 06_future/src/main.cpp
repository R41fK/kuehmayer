#include <iostream>

#include "CLI11.hpp"

using namespace std;



string validation(const string& str){
    try{
        stoi(str);
    } catch (const invalid_argument & e) {
        return str + " is not a Number";
    } catch (const std::out_of_range & e) {
        return str + " is to big for Int";
    }
    return "";
}


int main(int argc, char* argv[]) {
    
    CLI::App app("factoring");

    vector<string> numbers{}; 

    app.add_option("numbers", numbers, "Numbers that are factored")->required()->check(validation);

    CLI11_PARSE(app, argc, argv);

}
