// 8SmartPointers.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <memory>

using namespace std;

class PtrCls {
private:
    int step;

public:
    PtrCls(int step) {
        this->step = step;
        cout <<step<< ". constructor of PtrCls invoked" << endl;
    }
    ~PtrCls() {
        cout << this->step << ". destructor of PtrCls invoked" << endl;
    }
};

int main()
{
    unique_ptr<int>uniquePtr1 = make_unique<int>(25);
    cout << "1. uniquePtr1:\n" << uniquePtr1 << endl << *uniquePtr1 << endl;

    //unique_ptr<int>uniquePtr2 = uniquePtr1;
    unique_ptr<int>uniquePtr2 = move(uniquePtr1);
    cout << "2. uniquePtr2:\n" << uniquePtr2 << endl << *uniquePtr2 << endl;
    //cout << "2. uniquePtr1:\n" <<  uniquePtr1 << endl << *uniquePtr1 << endl;

    //{
    unique_ptr<PtrCls>uniqueClassPtr = make_unique<PtrCls>(3);
    //}
    //{
    shared_ptr<PtrCls>sharedClassPtr1 = make_shared<PtrCls>(4);
    cout << "4. sharedClassPtr1 count: " << sharedClassPtr1.use_count() << endl;
    //{
    shared_ptr<PtrCls>sharedClassPtr2 = sharedClassPtr1;
    cout << "4. sharedClassPtr1 count: " << sharedClassPtr1.use_count() << endl;
    //}
    cout << "5. sharedClassPtr1 count: " << sharedClassPtr1.use_count() << endl;
    //}

    //weak vs shared pointer weak will not keep object alive while shared will

    weak_ptr<int>weakPtr1;
    {
        shared_ptr<int>sharedPtr = make_shared<int>(25);
        weakPtr1 = sharedPtr;
        cout << *weakPtr1.lock()<< endl;
    }
    //objet to which pointer pointed was erased so next line will raise error
    //cout << *weakPtr1.lock() <<endl;

    return 0;
}