#ifndef __CONTACT_H__
#define __CONTACT_H__
#include <string>

using namespace std;

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
	char name[64];
    Date dob; 
    char email[64];
    char phone[14];
} Person;

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
};

#endif
