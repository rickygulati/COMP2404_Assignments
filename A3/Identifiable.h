#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H

using namespace std;

class Identifiable {
  protected:
    string id; // Unique id inherited by clients and animals

  public:
    Identifiable(string, int&); // ctor
    string getId() const; // Returns the id

};

#endif
