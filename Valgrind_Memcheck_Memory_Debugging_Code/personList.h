#ifndef PERSONLIST_H
#define PERSONLIST_H

#include "person.h"

class PersonList {
public:
    PersonList();
    ~PersonList();
    void addPerson(char* child_name, char* father_name, char* mother_name);
    void insertIntoList(Person *newPerson);
    void printLineage(char* person_name);

private:
    Person **theList;
    int capacity;
    int numPeople;
};

#endif // PERSONLIST_H
