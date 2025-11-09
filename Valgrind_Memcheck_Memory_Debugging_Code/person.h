#ifndef PERSON_H
#define PERSON_H

class Person {
public:
    Person(char *name, Person* father, Person* mother);
    ~Person();
    const char* getName() const { return name; }
    void addChild(Person *newChild);
    void printAncestors();
    void printDescendants();
    void printLineage(char dir, int level);
    char* compute_relation(int level);

private:
    char *name;
    Person *father;
    Person *mother;
    int capacity;
    int numChildren;
    Person **children;
};

void expand(Person ***t, int *MAX);

#endif // PERSON_H
