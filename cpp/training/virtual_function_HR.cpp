// #include <stdio.h>
// #include <string>
#include <iostream>
#define size 6

using namespace std;

int nbStudents = 0;
int nbProfessors = 0;

class Person {
    public :
    string name;
    int age;
    int type;
    void getdata () {
        if (type == 1) {
            Student stud;
        }
        else {
            Professor prof;
        }
    }
};

class Student : public Person {
    public:
    int marks[size];
    int curId = nbStudents;
    void getdata () {
        cin >> name >> age;
        for (int i=0; i<size; i++) {
            cin >> marks[i];
        }
    }
    void putdata() {
        int sum = 0;
        for (int i=0; i<size; i++) {
            sum += marks[i];
        }
        cout << name << " " << age << " " << sum << \
        " " << curId << endl;
    }
};

class Professor : public Person {
    public:
    int publications;
    int curId = nbProfessors;
    void getdata () {
        cin >> name >> age >> publications;
        // scanf("%s %d %d", &name, &age, &publications);
    }
    void putdata () {
        // for (char e: name) {
            // printf("%c", e);
        // }
        // printf(" %d %d %d\n", name, age, publications, curId);
        cout << name << " " << age << " " << \
        publications << " " << curId << endl;
    }
};

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