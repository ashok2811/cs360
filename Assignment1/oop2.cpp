#include <bits/stdc++.h>
#include <string>
using namespace std;

class Human{
    
    private:
        //string name;
        int age;

    public:
        string name;
        Human(){
            name = "No Name";
            age = 0;
            cout << "Constructor Call"<<endl;
        }

        Human(string iname){
            name = iname;
            age = 0;
            cout << "Constructor Call with name"<<endl;

        }

        Human(int a){
            name = "No Name";
            age = a;
            cout << "Constructor Call with age" <<endl;

        }

        Human(string iname, int a ){
            name = iname;
            age = a;
            cout << "Constructor Call with name and age" <<endl;

        }

        void display(){
            cout << name << endl << age <<endl;
        }
   

    
};

int main() {

    Human *ashok = new Human("Ashok", 23);
    ashok->display();

    delete ashok;
    return 0; 
}
