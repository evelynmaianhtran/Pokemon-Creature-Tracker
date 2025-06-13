#include "creature.h"

// Default Constructor
Creature::Creature() {
    this->name = " ";
    this->type = " ";
    this->power = 0;
}

// Contructor
Creature::Creature(const std::string& name, const std::string& type, int power) {
    this->name = name;
    this->type = type;
    this->power = power;
}
// Detructor
Creature::~Creature() {

}

// Return a reference to the underlying name as the key for the Creature object.
const std::string& Creature::get_key() const {
    return name;
}

// Return a reference to the type of the Creature object.
const std::string& Creature::get_type() const {
    return type;
}

// Return the power rating of the Creature object.
int Creature::get_power() const {
    return power;
}

// Overload the << operator for output
std::ostream& operator << (std::ostream& os, const Creature& c) {
    os << "("<< c.get_key() << ", " << c.get_type() << ", "<< c.get_power() << ")";
    return os;
}

// Determine if two creatures are equal. Two creatures are considered equal if they have the same name.
bool operator == (const Creature& c1, const Creature& c2) {
    return c1.get_key() == c2.get_key();                         
}

// Determine if the first Creature is ordered before the second Creature, alphabetically by name. 
bool operator < (const Creature& c1, const Creature& c2) {
    return c1.get_key() < c2.get_key();
}

// Determine if the first Creature is ordered after the second Creature, aplhabetically by name. 
bool operator > (const Creature& c1, const Creature& c2) {
    return c1.get_key() > c2.get_key();
}
