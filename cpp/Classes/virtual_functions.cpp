#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    private:
        string name;
        int age;
        
    public:
        virtual void getdata(){}
        virtual void putdata(){}
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
};

class Professor: public Person{
    private:
        int cur_id;
        int publications;
    public:
        static int cur_id_level;
        Professor(){
            Professor::cur_id_level += 1;
            cur_id = Professor::cur_id_level;
        }
        void getdata(){
            string name; int age;
            cin >> name >> age >> publications;
            this->setName(name);
            this->setAge(age);          
        }
        void putdata(){
            cout << this->getName() << " ";
            cout << this->getAge() << " ";
            cout << publications << " " << cur_id << endl;
        }
};

class Student: public Person{
    private:
        int cur_id;
        int marks [6];
    public:
        static int cur_id_level;
        Student(){
            Student::cur_id_level += 1;
            this->cur_id = Student::cur_id_level;
        }
        void getdata(){
            string name; int age;
            cin >> name >> age;
            for (int i=0;i<6;i++){
                cin >> marks[i];
            }
            this->setName(name);
            this->setAge(age);
        }
        void putdata(){
            cout << this->getName() << " ";
            cout << this->getAge() << " ";
            int total = 0;
            for(int i=0;i<6;i++){
                total += marks[i];
            }
            cout << total << " " << cur_id << endl;
        }
};
int Professor::cur_id_level=0;
int Student::cur_id_level=0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}