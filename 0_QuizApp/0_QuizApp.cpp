// 0_QuizApp.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <string>

using namespace std;

struct Question {
    string question;
    string a;
    string b;
    string c;
    char corectAnswer;
};

struct Questionnaire {
    Question* questions;
    int length;
};

Questionnaire buildQuestionnaire(string path);
int runQuestionnaire(Questionnaire);

int main()
{
    cout << "Hello World!\n";


}

Questionnaire buildQuestionnaire(string path)
{
    //from file create questionare
    return Questionnaire();
}

int runQuestionnaire(Questionnaire) {
    //run questionare and return how many point user achived
    return 0;
}
