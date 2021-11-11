#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "Animal.h"

int Animal::nextId = 1001;

Animal::Animal(SpeciesType s, string b, string c, string n, string g, int years, int months)
:name(n), breed(b), colour(c), species(s), gender(g), age((years*12) + months), Identifiable("A", nextId) {}

string Animal::getName() const {return name;}

string Animal::getBreed() const {return breed;}

string Animal::getGender() const {return gender;}

int Animal::getAge() const {return age;}

string Animal::speciesToString() const {
  switch(species) {
    case C_DOG: return "Dog";
    case C_CAT: return "Cat";
    case C_RABBIT: return "Rabbit";
    case C_BIRD: return "Bird";
    case C_OTHER: return "Other";
    default: return "Other";
  }
}

void Animal::print() const {
    cout<<id<<": "<<setw(10)<<left<<name;
    cout<<setw(10)<<left<<speciesToString();
    cout<<setw(30)<<left<<breed<<setw(5)<<left<<gender
        <<setw(4)<<right<<(age/12)<<" years, "<<(age%12)<<" months";
}
