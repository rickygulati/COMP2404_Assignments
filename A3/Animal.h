#ifndef ANIMAL_H
#define ANIMAL_H

#include "Identifiable.h"
#include "defs.h"

class Animal: public Identifiable {
  private:
    static int nextId; // Integer part of animal id
    string name; // Animal's name
    string breed; // Animal breed
    string gender; // Animal gender
    string colour; // Animal colour
    SpeciesType species; // Animal species
    int age; // Animal age in months

  public:
    Animal(SpeciesType, string, string, string, string, int = 0, int = 0); // ctor
    string getName() const; // Returns animal name
    string getBreed() const; // Returns animal breed
    string getGender() const; // Returns animal gender
    int getAge() const; // Returns animal age
    string speciesToString() const; // Returns animal species corresponding to SpeciesType definition
    void print() const; // Prints animal's info
};

#endif
