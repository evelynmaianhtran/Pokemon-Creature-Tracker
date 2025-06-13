// Constructor
template <typename T>
HashTable<T>::HashTable(int table_capacity) {
    this->capacity = table_capacity;
    table.resize(capacity);
    count = 0;
}

// Detructor
template <typename T>
HashTable<T>::~HashTable() {
    clear();
}

// Insert an element to the hash table
template <typename T>
void HashTable<T>::insert(const T& data) {
    int location = hash_function(data.get_key());
    table[location].push_back(data); 
    count++;
}

// Remove the item with the specified key from the has table if it exists
template <typename T>
void HashTable<T>::remove(const std::string& key) {
    int index = hash_function(key);
    if (list_remove(table[index], key)) {
        count--;
    }
}

// Return a pointer to the item with the specified key, if it exists
template <typename T>
T* HashTable<T>::get(const std::string& key) {
    int location = hash_function(key);
    return list_find(table[location], key);
}

//  Determine if an item with the specified key exists.
template <typename T>
bool HashTable<T>::contains(const std::string& key) {
    int location = hash_function(key);
    return list_contains(table[location], key);
}

// Clears all items from the hash table.
template <typename T>
void HashTable<T>::clear() {
    for(int i = 0 ; i < capacity; i++) {
        table[i].clear();
    }
    count = 0;
}

// Check if hash table is emtpty
template <typename T>
bool HashTable<T>::empty() const {
    return count == 0;
}

// Return the number of items in the hash table.
template <typename T>
int HashTable<T>::size() const {
    return count;
}

// Append the value of each cell in the hash table to the supplied stream. 
template <typename T>
void HashTable<T>::print(std::ostream& os) const {
    for (int i = 0; i < capacity; i++) {
        os << i << ": ";
        list_print(os, table[i]);
        os << std::endl;
    }  
}

// Overloading operator << for easy printing
template <typename T>
std::ostream& operator<<(std::ostream& out, const HashTable<T>& table) {
    table.print(out);
    return out;
}
