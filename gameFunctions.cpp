#include <iostream>
#include <cstring>

bool choosingOperators(std::string op) {
    bool inputValidation;
    bool do_operation;
    std::string input_operator;
    do {
        std::cout << "Do you want the quiz to contain " << op << " questions, answer with Yes or No: ";
        std::cin >> input_operator;
        if (strcasecmp(input_operator.c_str(), "Yes") == 0) {
            do_operation = true;
            inputValidation = true;
        }
        else if (strcasecmp(input_operator.c_str(), "No") == 0) {
            do_operation = false;
            inputValidation = true;
        }
        else {
            inputValidation = false;
            std::cout << "Input is invalid, please try again.\n\n";
        }
        } while (!inputValidation);
    return do_operation;
}