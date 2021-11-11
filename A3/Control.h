#ifndef CONTROL_H
#define CONTROL_H

#include "Shelter.h"
#include "View.h"

class Control
{
  public:
    Control(); // ctor
    ~Control(); // dtor
    void launch(); // Calls the shelter initializing function and interacts with user

  private:
    Shelter* shelter; // Pointer to a Shelter object
    View view; // View object
    void initShelter(); // Calls the animals' and clients' initializing functions
    void initAnimals(); // Populates the animals in the Shelter
    void initClients(); // Populates the clients in the Shelter
};

#endif
