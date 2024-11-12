// 0_QuizApp.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

Questionnaire * buildQuestionnaire(string path);
int runQuestionnaire(Questionnaire * quiz);
void reallocate(Question** old_arr, int old_size, int new_size);
void delQuestions(Questionnaire* quiz);

int main()
{
    string path;
    cout << "Zadej cestu k souboru s otazkami (název souboru): ";
    cin >> path;
    Questionnaire * quiz = buildQuestionnaire(path);
    cout<< "Tve skore je: " << runQuestionnaire(quiz);
    delQuestions(quiz);
    delete quiz;
}

Questionnaire * buildQuestionnaire(string path)
{
    
    ifstream file;
    string line;
    Questionnaire* quiz = new Questionnaire{ new Question[1],0 }; // inicializace struktury velikost pole pro otazky pouze 1 zvetsime realokaci

    file.open(path);

    while (getline(file, line)) {
        if (quiz->length!=0) {
            //realokace prostoru pro otazky jen ukazka obecně  nevhodné
            reallocate(&quiz->questions, quiz->length, quiz->length + 1);
        }
        //parsování jednotlivých řádků
        stringstream ss(line);
        getline(ss, quiz->questions[quiz->length].question, ';');
        getline(ss, quiz->questions[quiz->length].a, ';');
        getline(ss, quiz->questions[quiz->length].b, ';');
        getline(ss, quiz->questions[quiz->length].c, ';');
        ss >> quiz->questions[quiz->length].corectAnswer;
        quiz->length++;
    }

    file.close();

    return quiz;

}

int runQuestionnaire(Questionnaire * quiz) {
    int score = 0;
    char ans;
    for (int i = 0; i < quiz->length; i++) {
        cout << quiz->questions[i].question << endl;
        cout << "a: " << quiz->questions[i].a << endl;
        cout << "b: " << quiz->questions[i].b << endl;
        cout << "c: " << quiz->questions[i].c << endl;
        cin >> ans;
        if (ans == quiz->questions[i].corectAnswer) {
            score++;
            cout << "Spravna odpoved" << endl << endl;
        }
        else {
            cout << "Spatna odpoved" << endl << endl;
        }
    }
    return score;
}

void reallocate(Question** old_arr, int old_size, int new_size)
{
    //funkce umožnujě realokovat pole a tím ho rozšířit 

    Question* new_arr = new Question[new_size]; //nove pole otazek s nove definovanou velikosti

    copy(*old_arr, *old_arr + old_size, &new_arr[0]); //překopirovani honot ze starého pole do noveho

    delete[] * old_arr; //smazani stareho pole
    *old_arr = new_arr; //přepaní pointeru stareho pole na nove pole
}

void delQuestions(Questionnaire* quiz) {
    //funkce vyčití alokovnou paměť přiřazenou dynamicky vytvořeným polím
    delete[] quiz->questions;
    quiz->questions = nullptr;
}