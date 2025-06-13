#include "creature_type_stats.h"

// Default Constructor
CreatureTypeStats::CreatureTypeStats() {
    type = " ";
    count = 0;
    total_power = 0;
}

// Constructor
CreatureTypeStats::CreatureTypeStats(const std::string& type) {
    this->type = type;
    count = 0;
    total_power = 0;
}

// Destructor
CreatureTypeStats::~CreatureTypeStats() {}

// Return a reference to the underlying type as the key for the CreatureTypeStats object.
const std::string& CreatureTypeStats::get_key() const {
    return type;
}

// Return a count of the number of creatures with this type.
int CreatureTypeStats::get_count() const {
    return count;
}

// Return the total power of creatures with this type.
int CreatureTypeStats::get_total_power() const {
    return total_power;
}

// Increment the count by 1.
void CreatureTypeStats::increment_count() {
    count++;
}

// Decrement the count by 1.
void CreatureTypeStats::decrement_count() {
    //if(count > 0)
    count--;
}

// Add the supplied power amount to the total power.
void CreatureTypeStats::add_power(int amount) {
    total_power += amount;
}

// Subtract the supplied power amount from the total power.
void CreatureTypeStats::subtract_power(int amount) {
    total_power -= amount;
}

// Stream the value of the CreatureTypeStats
std::ostream& operator << (std::ostream& os, const CreatureTypeStats& c) {
    os << "(" << c.get_key() << ", " << c.get_count() << ", " << c.get_total_power() << ")";
    return os;
}

// Determine if two CreatureTypeStats are equal. Two CreatureTypeStats are considered equal if they have the same type.
bool operator == (const CreatureTypeStats& c1, const CreatureTypeStats& c2) {
    return c1.get_key() == c2.get_key();
}

// Determine if the first CreatureTypeStats is ordered before the second CreatureTypeStats, alphabetically by type. 
bool operator < (const CreatureTypeStats& c1, const CreatureTypeStats& c2) {
    return c1.get_key() < c2.get_key();
}

// Determine if the first CreatureTypeStats is ordered after the second CreatureTypeStats, aplhabetically by type. 
bool operator > (const CreatureTypeStats& c1, const CreatureTypeStats& c2) {
    return c1.get_key() > c2.get_key();
}