#include <bits/stdc++.h>
#include <string>
using namespace std;

class Human{
    private : // acces specifier
        int age;

    public :  // access specifier
        string name = "No Name";

        void introduce();

        void  displayAge(){
            cout << age -2 << endl;

        }
        void setAge(int value){
            age = value;

        }


    
};

void Human :: introduce(){
    cout <<"Hi, I am " << Human :: name <<endl;
}


int main() {

    
    Human *muskan = new Human(); // returns a pointer , This is stored in heap

    muskan->name = "Muskan";
    muskan->introduce();
    
    muskan->setAge(19);

    cout << muskan->name << "'s age is ";
    muskan->displayAge();

    return 0; 
}
