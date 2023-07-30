#include <iostream>
#include <cstring>
#include "gameFunctions.h"

int main() {
    int questions;
    bool do_addition;
    bool do_subtraction;
    bool do_multiplication;
    bool do_division;
    std::cout <<"===============================\n";
    std::cout << "Welcome to this Maths game\n";
    std::cout << "==============================\n";
    std::cout << "How many questions do you want to answer: ";
    std::cin >> questions;
    while (std::cin.fail()) {
        std::cout << "Input was invalid, please try again.\n\n";
        std::cout << "How many questions do you want to answer: ";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> questions;
    }
    if (questions > 50 || questions == 0)
        questions > 50 ? std::cout << "You can't have more than 50 questions\n\n" : std::cout << "You need more then 0 questions.\n\n";
    else {
        do_addition = choosingOperators("addition");
        do_subtraction = choosingOperators("subtraction");
        do_multiplication = choosingOperators("multiplication");
        do_division = choosingOperators("division");
    }
    return 0;
}