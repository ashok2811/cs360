#include <bits/stdc++.h>
#include <string>
using namespace std;

class Human{
    public :  // access specifier
        string name;

        void introduce(){

            cout << "Hi, I am " << name <<endl;
        }

        void display(){
            cout << "Hello, I am a Human Being"<<endl;
        }
    
};

int main() {

    Human Ashok;

    Ashok.name = "Ashok";
    Ashok.introduce();

    Human *muskan = new Human(); // returns a pointer , This is stored in heap

    muskan->name = "Muskan";
    muskan->introduce();


    return 0; 
}
