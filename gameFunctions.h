#ifndef FUNCTION
#define FUNCTION

class Questions {
    private:
        std::string question;
        int answer;
        int multipleChoice[4];
    public:
    Questions(std::string question, int answer, int multipleChoice[4]);
    std::string getQuestion();
    int getAnswer();
    int * getChoices();
};

bool choosingOperators(std::string op);

std::vector<Questions> generateQuiz(bool do_addition, bool do_subtraction, bool do_multiplication, bool do_division, int questions);

#endif