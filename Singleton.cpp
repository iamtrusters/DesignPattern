/*
-Enforces one and only one object of a Singleton class
-Has the Singleton object globally accessible
*/

#include <iostream>

using namespace std;

class Singleton {
private:
    static Singleton* instance; //static instance pointer
    static const int value1 = 10; //static const is allowed to define inside, used as a compile-time constant
    static const int value2 = 20; //static const is allowed to define inside
    Singleton(){}  //private constructor to prevent direct instantiation
public:
    //initialized by default and don't need extra handling
    static Singleton* getInstance(){
        if(instance == nullptr){
            instance = new Singleton();
        }

        return instance;
    }

    const void showMessage(){
        std::cout << "Singleton Instance Address: "<<this<<std::endl;
    }
};

//Define static instance, static class data members belong to the class, not instances of the class
//must be declared inside, must be defined outside
Singleton* Singleton::instance = nullptr;
const int Singleton::value2; //defined outside class if its address is taken
int main(){
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();
    Singleton* s2 = Singleton::getInstance();
    s2->showMessage();
}
