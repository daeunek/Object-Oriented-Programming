#include <iostream>
#include <string>

using namespace std;

class QuizQuestion {
private:
    string question;
    string choices[3];
    char correctAnswer;

public:
    QuizQuestion(string q, string c1, string c2, string c3, char ans)
        : question(q), correctAnswer(ans) {
        choices[0] = c1;
        choices[1] = c2;
        choices[2] = c3;
    }

    void displayQuestion() const {
        cout << question << endl;
        cout << "a. " << choices[0] << endl;
        cout << "b. " << choices[1] << endl;
        cout << "c. " << choices[2] << endl;
    }

    bool checkAnswer(char userAnswer) const {
        return tolower(userAnswer) == correctAnswer;
    }
};

int main() {
    QuizQuestion questions[] = {
        QuizQuestion("What is the capital of France?", "Berlin", "Paris", "London", 'b'),
        QuizQuestion("Which planet is known as the Red Planet?", "Mars", "Jupiter", "Saturn", 'a'),
        QuizQuestion("What is the largest mammal?", "Elephant", "Blue Whale", "Giraffe", 'b'),
        QuizQuestion("Who wrote 'Hamlet'?", "Mark Twain", "Charles Dickens", "William Shakespeare", 'c'),
        QuizQuestion("What is the chemical symbol for water?", "H2O", "CO2", "O2", 'a')
    };

    int score = 0;
    int totalQuestions = sizeof(questions) / sizeof(QuizQuestion);

    cout << "Welcome to the Quiz Game!" << endl;

    int i = 0;
    while (i < totalQuestions) {
        cout << "\nQuestion " << (i + 1) << ":" ;
        questions[i].displayQuestion();

        char userAnswer;
        cout << "Your answer (a, b, or c): ";
        cin >> userAnswer;

        switch (userAnswer) {
            case 'a':
            case 'b':
            case 'c':
                if (questions[i].checkAnswer(userAnswer)) {
                    cout << "Correct!\n";
                    score++;
                } else {
                    cout << "Wrong answer.\n";
                }
                i++;
                break;
            default:
                cout << "Invalid input. Please enter a, b, or c.\n";
                break;
        }
    }

    cout << "\nQuiz completed!\n";
    cout << "Your total score: " << score << " out of " << totalQuestions << endl;

    return 0;
}
