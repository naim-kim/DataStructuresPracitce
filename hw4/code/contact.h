//22000056 김나임
#ifndef CONTACT_H
#define CONTACT_H
#include <string>

using namespace std;

typedef struct {
    int year;
    int month;
    int day;
} Date;

struct Person {
    string name;
    Date dob;
    string email;
    string phone;
};

class Contact {
  private:
    Person* persons;
    int total_num;

    // no access to these functions from clients
    Person str2person(char*); 
    Date str2date(char*);
    char* trim(char*);
    
  public:
    Contact(int size){ 
        total_num = 0;
        persons = new Person[size];
    }
    ~Contact() {delete persons;} 
    
    void load(string);
    void print();
    Person str2person(string line);
};

#endif
