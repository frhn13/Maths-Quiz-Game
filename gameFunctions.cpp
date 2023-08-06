#include <iostream>
#include <cstring>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include "gameFunctions.h"

Questions::Questions(std::string question, int answer, std::vector<int> multipleChoices) {
    this->question = question;
    this->answer = answer;
    this->multipleChoices = multipleChoices;
}

std::string Questions::getQuestion() {
    return question;
}

int Questions::getAnswer() const {
    return answer;
}

std::vector<int> Questions::getChoices() {
    return multipleChoices;
}

Score::Score(std::string username, std::string percentage) {
    this->username = username;
    this->percentage = percentage;
}

Score::Score() {
}

std::string Score::getUsername() {
    return username;
}

std::string Score::getPercentage() {
    return percentage;
}

bool choosingOperators(std::string op, int * no_operators) {
    bool inputValidation;
    bool do_operation;
    std::string input_operator;
    do {
        std::cout << "Do you want the quiz to contain " << op << " questions, answer with Yes or No: ";
        std::cin >> input_operator;
        if (strcasecmp(input_operator.c_str(), "Yes") == 0) {
            do_operation = true;
            inputValidation = true;
            (*no_operators)++;
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

std::vector<Questions> generateQuiz(bool do_addition, bool do_subtraction, bool do_multiplication, bool do_division, int questions) {
    int operation_chosen;
    int choice_chosen;
    int num1;
    int num2;
    int answer;
    int noChoices = 4;
    std::string question_asked;
    std::vector<Questions> quizQuestions;
    srand(time(NULL));
    for (int x=0; x<questions;) {
        operation_chosen = rand() % 4;
        switch(operation_chosen) {
            case 0:
                if (do_addition) {
                    num1 = (rand() % 200) + 1;
                    num2 = (rand() % 200) + 1;
                    answer = num1 + num2;
                    choice_chosen = rand() % 4;
                    std::vector<int> multipleChoices;
                    for (int y=0; y<noChoices; y++) {
                        multipleChoices.push_back((rand() % 400) + 1);
                    }
                    multipleChoices[choice_chosen] = answer;
                    question_asked = "What is " + std::to_string(num1) + " + " + std::to_string(num2) + "? ";
                    Questions question(question_asked, answer, multipleChoices);
                    quizQuestions.push_back(question);
                    x++;
                }
                break;
            case 1:
                if (do_subtraction) {
                    num1 = (rand() % 200) + 1;
                    num2 = (rand() % 200) + 1;
                    answer = num1 - num2;
                    choice_chosen = rand() % 4;
                    std::vector<int> multipleChoices;
                    for (int y=0; y<noChoices; y++) {
                        multipleChoices.push_back((rand() % 400) + 1);
                    }
                    multipleChoices[choice_chosen] = answer;
                    question_asked = "What is " + std::to_string(num1) + " - " + std::to_string(num2) + "? ";
                    Questions question(question_asked, answer, multipleChoices);
                    quizQuestions.push_back(question);
                    x++;
                }
                break;
            case 2:
                if (do_multiplication) {
                    num1 = (rand() % 20) + 1;
                    num2 = (rand() % 20) + 1;
                    answer = num1 * num2;
                    choice_chosen = rand() % 4;
                    std::vector<int> multipleChoices;
                    for (int y=0; y<noChoices; y++) {
                        multipleChoices.push_back((rand() % 400) + 1);
                    }
                    multipleChoices[choice_chosen] = answer;
                    question_asked = "What is " + std::to_string(num1) + " * " + std::to_string(num2) + "?";
                    Questions question(question_asked, answer, multipleChoices);
                    quizQuestions.push_back(question);
                    x++;
                }
                break;
            case 3:
                if (do_division) {
                    do {
                        num1 = (rand() % 200) + 1;
                        num2 = (rand() % 20) + 1;
                    } while (num1 % num2 != 0);
                    answer = num1 / num2;
                    std::vector<int> multipleChoices;
                    choice_chosen = rand() % 4;
                    for (int y=0; y<noChoices; y++) {
                        multipleChoices.push_back((rand() % 100) + 1);
                    }
                    multipleChoices[choice_chosen] = answer;
                    question_asked = "What is " + std::to_string(num1) + " / " + std::to_string(num2) + "? ";
                    Questions question(question_asked, answer, multipleChoices);
                    quizQuestions.push_back(question);
                    x++;
                }
                break;
        }
    }
    return quizQuestions;
}

int playQuiz(std::vector<Questions> quizQuestions, bool isMultipleChoice) {
    int player_answer;
    int score = 0;
     for (int x = 0; x < quizQuestions.size(); x++) {
            std::cout << quizQuestions[x].getQuestion() << '\n';
            if (isMultipleChoice) {
                for (int y = 0; y < quizQuestions[x].getChoices().size(); y++) {
                    std::cout << "Choice " << y + 1 << ": " << quizQuestions[x].getChoices()[y] << "\n";
                }
            }
            std::cin >> player_answer;
            while (std::cin.fail()) {
                std::cout << "Input was invalid, please try again.\n\n";
                std::cout << quizQuestions[x].getQuestion() << "\n";
                if (isMultipleChoice) {
                    for (int y = 0; y < quizQuestions[x].getChoices().size(); y++) {
                        std::cout << "Choice " << y + 1 << ": " << quizQuestions[x].getChoices()[y] << "\n";
                    }
                }
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> player_answer;
            }
            if (player_answer == quizQuestions[x].getAnswer() || (isMultipleChoice && quizQuestions[x].getChoices()[player_answer-1] == quizQuestions[x].getAnswer())) {
                score++;
                std::cout << "Well done!\n";
            } else
                std::cout << "You are wrong, the correct answer was: " << quizQuestions[x].getAnswer() << "\n";
        }
    return score;
}

void saveScore(std::string username, double percentage) {
    std::ofstream username_file;
    std::ofstream scores_file;
    username_file.open("usernames.txt", std::ios::app);
    username_file << username << std::endl;
    username_file.close();
    scores_file.open("scores.txt", std::ios::app);
    scores_file << percentage << std::endl;
    scores_file.close();
}

std::vector<Score> viewScores(bool sort_scores) {
    std::string username_input;
    std::string score_input;
    std::ifstream username_file("usernames.txt");
    std::ifstream scores_file("scores.txt");
    std::vector<std::string> usernames;
    std::vector<std::string> scores;
    std::vector<Score> fullDetails;
    Score temp_score;

    if (username_file.is_open()) {
        while(username_file >> username_input) {
            usernames.push_back(username_input);
        }
    }
    else {
        std::cout << "File empty\n";
    }
    if (scores_file.is_open()) {
        while(scores_file >> score_input) {
            scores.push_back(score_input);
        }
    }
    for (int x=0; x<usernames.size(); x++) {
        Score score = Score(usernames[x], scores[x]);
        fullDetails.push_back(score);
    }
    if (sort_scores) {
        for (int x=0; x<fullDetails.size()-1; x++) {
            for (int y=0; y<fullDetails.size()-1; y++) {
                std::cout << stod(fullDetails[y].getPercentage()) << "\n";
                if (stod(fullDetails[y].getPercentage()) < stod(fullDetails[y+1].getPercentage())) {
                    temp_score = fullDetails[y];
                    fullDetails[y] = fullDetails[y+1];
                    fullDetails[y+1] = temp_score;
                }
            }
        }
    }
    return fullDetails;
}
