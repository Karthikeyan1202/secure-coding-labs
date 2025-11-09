#include "personList.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

void expand(Person ***t, int *MAX) {
    Person **temp = new Person*[2 * *MAX];
    std::memcpy(temp, *t, *MAX * sizeof(**t));
    delete[] *t;
    *MAX *= 2;
    *t = temp;
}

PersonList::PersonList() {
    capacity = 2;
    numPeople = 0;
    theList = new Person*[capacity];
}

PersonList::~PersonList() {
    for (int i = 0; i < numPeople; ++i) delete theList[i];
    delete[] theList;
}

void PersonList::addPerson(char* child_name, char* father_name, char* mother_name) {
    Person *father = nullptr;
    Person *mother = nullptr;
    for (int i = 0; i < numPeople; ++i) {
        if (!std::strcmp(theList[i]->getName(), child_name)) {
            cout << "ERROR: " << child_name << " already has parents!!!" << endl;
            return;
        } else if (!std::strcmp(theList[i]->getName(), father_name)) {
            father = theList[i];
        } else if (!std::strcmp(theList[i]->getName(), mother_name)) {
            mother = theList[i];
        }
    }
    if (father == nullptr) { father = new Person(father_name, nullptr, nullptr); insertIntoList(father); }
    if (mother == nullptr) { mother = new Person(mother_name, nullptr, nullptr); insertIntoList(mother); }
    Person *newChild = new Person(child_name, father, mother);
    insertIntoList(newChild);
    father->addChild(newChild);
    mother->addChild(newChild);
}

void PersonList::insertIntoList(Person *newPerson) {
    if (numPeople == capacity) expand(&theList, &capacity);
    theList[numPeople++] = newPerson;
}

void PersonList::printLineage(char* person_name) {
    for (int i = 0; i < numPeople; ++i) {
        if (!std::strcmp(theList[i]->getName(), person_name)) {
            theList[i]->printAncestors();
            theList[i]->printDescendants();
            return;
        }
    }
    cout << std::endl << person_name << " is not in the list!" << std::endl;
}
