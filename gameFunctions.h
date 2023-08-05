#ifndef FUNCTION
#define FUNCTION

class Questions {
    private:
        std::string question;
        int answer;
        std::vector<int> multipleChoices;
    public:
    Questions(std::string question, int answer, std::vector<int> multipleChoices);
    std::string getQuestion();
    int getAnswer() const;
    std::vector<int> getChoices();
};

bool choosingOperators(std::string op);

std::vector<Questions> generateQuiz(bool do_addition, bool do_subtraction, bool do_multiplication, bool do_division, int questions);
void saveScore(std::string username, double percentage);

#endif