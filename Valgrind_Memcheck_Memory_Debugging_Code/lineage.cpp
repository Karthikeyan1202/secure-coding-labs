#include "person.h"
#include "personList.h"

int main() {
    PersonList theList;
    theList.addPerson((char*)"Bob", (char*)"Mark", (char*)"Betty");
    theList.addPerson((char*)"Jim", (char*)"Bob", (char*)"Sally");
    theList.addPerson((char*)"Frank", (char*)"Jim", (char*)"Mary");
    theList.addPerson((char*)"Leonard", (char*)"Jim", (char*)"Mary");
    theList.addPerson((char*)"Kim", (char*)"Leonard", (char*)"Sarah");

    theList.printLineage((char*)"Jim");
    theList.printLineage((char*)"Kim");
    theList.printLineage((char*)"Betty");

    return 0;
}
