#include <bits/stdc++.h>
#include <string>
using namespace std;

class Human{
    
    private:
        string *name;
        int *age;

    public:
        
        Human(string iname , int iage ){
            name = new string;
            age = new int;
            *name = iname;
            *age = iage;
       }

       
       ~Human(){

           delete name;
           delete age;
           cout << "All memories released"<<endl;
       }

        void display(){
            cout <<"Hi, I am " << *name << " and I am " << *age <<
            " years old"<<endl;
        }
   

    
};

int main() {

    Human *ashok = new Human("Ashok", 23);
    ashok->display();

    delete ashok;
    return 0; 
}

