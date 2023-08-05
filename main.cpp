#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include "gameFunctions.h"

int main() {
    int questions;
    int score = 0;
    std::string username;
    std::string quiz_type;
    bool isMultipleChoice;
    bool do_addition;
    bool do_subtraction;
    bool do_multiplication;
    bool do_division;
    bool play_again = true;
    std::string play_again_str;
    int player_answer;
    std::cout <<"===============================\n";
    std::cout << "Welcome to this Maths game\n";
    std::cout << "===============================\n";
    do {
        std::cout << "Enter your username: ";
        std::getline(std::cin >> std::ws, username);
        score = 0;
        std::cout << "How many questions do you want to answer: ";
        std::cin >> questions;
        while (std::cin.fail()) {
            std::cout << "Input was invalid, please try again.\n\n";
            std::cout << "How many questions do you want to answer: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> questions;
        }
        if (questions > 50 || questions == 0)
            questions > 50 ? std::cout << "You can't have more than 50 questions\n\n" : std::cout << "You need more then 0 questions.\n\n";
        else {
            do {
                std::cout << "Do you want the quiz to be multiple choice? Answer with Yes or No: ";
                std::cin >> quiz_type;
                if (strcasecmp(quiz_type.c_str(), "Yes") == 0)
                    isMultipleChoice = true;
                else if (strcasecmp(quiz_type.c_str(), "No") == 0)
                    isMultipleChoice = false;
                else
                    std::cout << "Input is invalid.\n\n";
            } while (strcasecmp(quiz_type.c_str(), "No") != 0 and strcasecmp(quiz_type.c_str(), "Yes") != 0);
            do_addition = choosingOperators("addition");
            do_subtraction = choosingOperators("subtraction");
            do_multiplication = choosingOperators("multiplication");
            do_division = choosingOperators("division");
        }
        std::vector<Questions> quizQuestions = generateQuiz(do_addition, do_subtraction, do_multiplication, do_division,
                                                            questions);
        for (int x = 0; x < quizQuestions.size(); x++) {
            std::cout << quizQuestions[x].getQuestion() << '\n';
            if (isMultipleChoice) {
                for (int y = 0; y < quizQuestions[x].getChoices().size(); y++) {
                    std::cout << "Choice " << y + 1 << ": " << quizQuestions[x].getChoices()[y] << "\n";
                }
                std::cout << "Answer with the number itself, not 1, 2, 3 or 4." << std::endl;
            }
            std::cin >> player_answer;
            while (std::cin.fail()) {
                std::cout << "Input was invalid, please try again.\n\n";
                std::cout << quizQuestions[x].getQuestion() << "\n";
                if (isMultipleChoice) {
                    for (int y = 0; y < quizQuestions[x].getChoices().size(); y++) {
                        std::cout << "Choice " << y + 1 << ": " << quizQuestions[x].getChoices()[y] << "\n";
                    }
                    std::cout << "Answer with the number itself, not 1, 2, 3 or 4." << std::endl;
                }
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> player_answer;
            }
            if (player_answer == quizQuestions[x].getAnswer()) {
                score++;
                std::cout << "Well done!\n";
            } else
                std::cout << "You are wrong, the correct answer was: " << quizQuestions[x].getAnswer() << "\n";
        }
        std::cout << "Final Score: " << score << "/" << questions << "\n";
        saveScore(username, (score / (double) questions) * 100);
        std::cout << "Do you want to play again?, Answer with Yes or No: ";
        std::cin >> play_again_str;
        if (strcasecmp(play_again_str.c_str(), "No") == 0)
            play_again = false;
    } while (play_again);
    std::cout << "Bye!";
    return 0;
}