#include "creature_tracker.h"
// Constructor
CreatureTracker::CreatureTracker() : ht_stats(101) {}

// Destructor
CreatureTracker::~CreatureTracker() {
    clear();
}

// Add a new Creature with the supplied information to the CreatureTracker.
void CreatureTracker::add_creature(const std::string& name, const std::string& type, int power) {
    Creature creature(name, type, power);   // Create a new creature with supplied data
    tree_creatures.insert(creature);       
    // Check if the type of the creature already exists in the hash table.   
    if (ht_stats.contains(type)) {
        // If it exists, get the current stats then increment_count and add_power
        CreatureTypeStats* stats = ht_stats.get(type);
        stats->increment_count();
        stats->add_power(power);
    } else {
        // If it does not exist, create a new CreatureTypeStats object for that type, then increment_count and add_power
        CreatureTypeStats stats(type);   
        stats.increment_count();
        stats.add_power(power);
        ht_stats.insert(stats);  // Insert it into the hash table.
    }
}

// Remove the information for the Creature with the supplied name from the CreatureTracker.
void CreatureTracker::remove_creature(const std::string& name) {
    Creature* creature = get_creature(name);
    // If the supplied name exist, remove it
    if(creature) {
        std::string type = creature->get_type();
        int power = creature->get_power();
        tree_creatures.remove(creature->get_key());
        // Update the hash table with the new stats
        if(ht_stats.contains(type)) {
            CreatureTypeStats* stats = ht_stats.get(type);
            stats->decrement_count();
            stats->subtract_power(power);
            // If no more creatures of this type remain, remove the stats entry
            if (stats->get_count() == 0) {
                ht_stats.remove(type);
            }
        }            
    }
}

// Check if a Creature with the supplied name exists.
bool CreatureTracker::creature_exists(const std::string& name) {
    return tree_creatures.contains(name);
}

// Get a pointer to the Creature with the supplied name, or nullptr if it does not exist.
Creature* CreatureTracker::get_creature(const std::string& name) {
        return tree_creatures.find(name);
}

// Return a count of the number of creatures with the supplied type.
int CreatureTracker::type_count(const std::string& type) {
    if (ht_stats.contains(type)) 
        return ht_stats.get(type)->get_count();
    return 0;
}

// Return the total power of the creatures with the supplied type.
int CreatureTracker::type_power(const std::string& type) {
    if (ht_stats.contains(type)) 
        return ht_stats.get(type)->get_total_power();
    return 0;
}

// Get a pointer to the CreatureTypeStats with the supplied type  
CreatureTypeStats* CreatureTracker::get_stats(const std::string& type) {
    if (ht_stats.contains(type)) 
        return ht_stats.get(type);
    else {
        // Insert a new CreatureTypeStats with the type and return it
        CreatureTypeStats new_stats(type);
        ht_stats.insert(new_stats);
        return ht_stats.get(type);
    }
}

//  Clears all Creatures and CreatureTypeStats' from the CreatureTracker.
void CreatureTracker::clear() {
    tree_creatures.clear();     // Clear all nodes from the BST
    ht_stats.clear();           // Clear all entries from the hash table
}

// Append both the creature tree and the type stats hash table to the stream.
void CreatureTracker::print(std::ostream& os) const {
    os<< "Creatures: " << std::endl;
    tree_creatures.print_inorder(os);
    os << "\nType stats: " << std::endl;
    ht_stats.print(os);
}

// Append both the creature tree and the type stats hash table to the stream.
std::ostream& operator<<(std::ostream& out, const CreatureTracker& tracker) {
    tracker.print(out);
    return out;
}
