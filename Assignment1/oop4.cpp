#include <bits/stdc++.h>
#include <string>
using namespace std;

class Human{
    
    private:
        string *name;
        int *age;

    public:

        static int human_count;

        Human(){
            human_count ++;
        }

        void humanTotal(){

            cout << human_count << " people" <<endl; 
        }
           
};

int Human::human_count = 0;

int main() {

    Human *ashok = new Human();
    ashok->humanTotal();

    Human *Muskan = new Human();
    Muskan->humanTotal();

    return 0; 
}
