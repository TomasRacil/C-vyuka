// ExerciseCompanion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Exercise.h"
#include "Training.h"
#include "TrainingDiary.h"

int main()
{
    Rep r1 = Rep("12 x 100 kg");
    std::cout << r1 << std::endl;
    Exercise e1 = Exercise("Benchpress");
    e1.addRep(r1);
    std::cout << e1 << std::endl;
    Training t1 = Training(
        "3.1.2023\n"
        "Bench press(3)\n"
        "12 x 60 kg\n"
        "10 x 70 kg\n"
        "6 x 85 kg\n"
        "Cable crossover(2)\n"
        "12 x 40 kg\n"
        "12 x 35 kg\n");
    std::cout << t1 << std::endl;
    TrainingDiary d = TrainingDiary("diary.txt");
    d.addTraining(t1);
    std::cout << d << std::endl;
    d.printPersonalBest();
}

