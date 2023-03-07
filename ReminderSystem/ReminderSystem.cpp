// ReminderSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Event.h"
#include "Calendar.h"

int main()
{
    Time t = Time("2023 1 10 20 53");
    std::cout << t << std::endl;

    Event e = Event("Presentation","2023 3 2 14 00","2023 3 2 16 15","S9A/67","Information technology presentation.Complete projects and tasks");
    Calendar c = Calendar("TEST", "events.txt");
    std::cout << c << std::endl;

    c.addEvent(e);

    Event e1 = Event("Launch", "2023 3 2 12 00", "2023 3 2 13 00", "Canteen", "Enjoy your meal.");
    c.addEvent(e1);
    std::cout << c << std::endl;

    std::cout << c.findEvent("Exam") << std::endl;

    std::cout << c.findEventsAfter(Time("2023 3 2 15 40")) << std::endl;
    std::cout << c.findEventsBefore(Time("2023 3 2 8 00")) << std::endl;

}