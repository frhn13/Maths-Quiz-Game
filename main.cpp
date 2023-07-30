#include <iostream>
#include <cstring>

int main() {
    int questions;
    std::string input_operator;
    bool do_addition;
    bool do_subtraction;
    bool do_multiplication;
    bool do_division;
    bool inputValidation = false;
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
        do {
            std::cout << "Do you want the quiz to contain addition questions, answer with Yes or No: ";
            std::cin >> input_operator;
            if (strcasecmp(input_operator.c_str(), "Yes") == 0) {
                do_addition = true;
                inputValidation = true;
            }
            else if (strcasecmp(input_operator.c_str(), "No") == 0) {
                do_addition = false;
                inputValidation = true;
            }
            else {
                inputValidation = false;
                std::cout << "Input is invalid, please try again.\n\n";
            }
        } while (!inputValidation);
        do {
            std::cout << "Do you want the quiz to contain subtraction questions, answer with Yes or No: ";
            std::cin >> input_operator;
            if (strcasecmp(input_operator.c_str(), "Yes") == 0) {
                do_subtraction = true;
                inputValidation = true;
            }
            else if (strcasecmp(input_operator.c_str(), "No") == 0) {
                do_subtraction = false;
                inputValidation = true;
            }
            else {
                inputValidation = false;
                std::cout << "Input is invalid, please try again.\n\n";
            }
        } while (!inputValidation);

        do {
            std::cout << "Do you want the quiz to contain multiplication questions, answer with Yes or No: ";
            std::cin >> input_operator;
            if (strcasecmp(input_operator.c_str(), "Yes") == 0) {
                do_multiplication = true;
                inputValidation = true;
            }
            else if (strcasecmp(input_operator.c_str(), "No") == 0) {
                do_multiplication = false;
                inputValidation = true;
            }
            else {
                inputValidation = false;
                std::cout << "Input is invalid, please try again.\n\n";
            }
        } while (!inputValidation);

        do {
            std::cout << "Do you want the quiz to contain division questions, answer with Yes or No: ";
            std::cin >> input_operator;
            if (strcasecmp(input_operator.c_str(), "Yes") == 0) {
                do_division = true;
                inputValidation = true;
            }
            else if (strcasecmp(input_operator.c_str(), "No") == 0) {
                do_division = false;
                inputValidation = true;
            }
            else {
                inputValidation = false;
                std::cout << "Input is invalid, please try again.\n\n";
            }
        } while (!inputValidation);
    }
    return 0;
}