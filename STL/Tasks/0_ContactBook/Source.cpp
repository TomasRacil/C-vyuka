// 0_ContactBook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Contact.h"
#include "ContactBook.h"
#include <queue>

int main()
{
    ContactBook contacts;
    contacts.load("contacts");
    //contacts.print();
    

    contacts.find("ne").print();


    /*std::queue<Contact> call_queue;
    ContactBook temp = contacts.find_by_surname("mc");
    for (Contact con: temp.book) {
        call_queue.push(con);
    }
    ContactBook temp2 = contacts.find_by_forename("j");
    for (Contact con : temp2.book) {
        call_queue.push(con);
    }
        
    while (!call_queue.empty()) {
        std::cout << "Calling: " << call_queue.front() << std::endl;
        call_queue.pop();
    }*/

    contacts.save("contacts");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
