#include "TrainingDiary.h"

TrainingDiary::TrainingDiary(std::string path)
{
    this->path = path;
    std::ifstream file;
    file.open(path);
    std::string line;
    std::getline(file, line);
    owner = line;
    while (std::getline(file, line,'#')) {
        if (line != "") {
            trainings.push_back(Training(line));
        }
    }
    std::sort(this->trainings.begin(), this->trainings.end());
}

void TrainingDiary::printPersonalBest()
{
    std::map<std::string, int> out;
    for (Training t : trainings) {
        auto bests = t.getBestExercise();
        for (auto e : bests) {
            if (out.find(std::get<0>(e)) == out.end()) out[std::get<0>(e)] = std::get<1>(e);
            else {
                if (out[std::get<0>(e)] < std::get<1>(e)) out[std::get<0>(e)] = std::get<1>(e);
            }
        }
    }
    std::cout << "Personal best: " << std::endl;
    for (auto e : out) {
        std::cout << std::get<0>(e) << ":" << std::get<1>(e) << std::endl;
    }
}

void TrainingDiary::addTraining(Training training)
{
    trainings.push_back(training);
    std::sort(this->trainings.begin(), this->trainings.end());
}

TrainingDiary::~TrainingDiary()
{
    std::ofstream file;
    file.open(this->path);
    std::stringstream out;
    out << *this;
    file.write(out.str().c_str(), out.str().size());
}

std::ostream& operator<<(std::ostream& out, const TrainingDiary& obj)
{
    // TODO: insert return statement here
    out << obj.owner << std::endl;
    for (Training t : obj.trainings) {
        out << "#"<<std::endl << t ;
    }
    return out;
}
