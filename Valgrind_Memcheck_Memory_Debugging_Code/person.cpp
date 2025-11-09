#include "person.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

Person::Person(char *name, Person* father, Person* mother) {
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
    this->father = father;
    this->mother = mother;
    capacity = 1;
    numChildren = 0;
    children = new Person*[capacity];
}

Person::~Person() {
    delete[] children;
    delete[] name;
}

void Person::addChild(Person *newChild) {
    if (numChildren == capacity) expand(&children, &capacity);
    children[numChildren++] = newChild;
}

char* Person::compute_relation(int level) {
    if (level == 0) return std::strcpy(new char[1], "");
    char *temp = std::strcpy(new char[std::strlen("grand ") + 1], "grand ");
    for (int i = 2; i <= level; ++i) {
        char *temp2 = new char[std::strlen("great ") + std::strlen(temp) + 1];
        std::strcat(std::strcpy(temp2, "great "), temp);
        delete[] temp;
        temp = temp2;
    }
    return temp;
}

void Person::printAncestors() {
    cout << std::endl << "Ancestors of " << name << std::endl;
    printLineage('u', 0);
}

void Person::printDescendants() {
    cout << std::endl << "Descendants of " << name << std::endl;
    printLineage('d', 0);
}

void Person::printLineage(char dir, int level) {
    char *relation = compute_relation(level);
    if (dir == 'd') {
        for (int i = 0; i < numChildren; ++i) {
            cout << relation << "child: " << children[i]->getName() << std::endl;
            children[i]->printLineage(dir, level + 1);
        }
    } else {
        if (mother) {
            cout << relation << "mother: " << mother->getName() << std::endl;
            mother->printLineage(dir, level + 1);
        }
        if (father) {
            cout << relation << "father: " << father->getName() << std::endl;
            father->printLineage(dir, level + 1);
        }
    }
    delete[] relation;
}
