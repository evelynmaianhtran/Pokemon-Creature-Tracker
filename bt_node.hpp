// Default constructor
template <typename T>
BTNode<T>::BTNode() {
    data = T();
    left = nullptr;
    right = nullptr;
}

// Constructor that hold data
template <typename T>
BTNode<T>::BTNode(const T& new_data) {
    data = new_data;
    left = nullptr;
    right = nullptr;
}

// Destructor
template <typename T>
BTNode<T>::~BTNode() {}

// Set data variable to the supplied value
template <typename T>
void BTNode<T>::set_data(const T& new_data) {
    data = new_data;
}

// Set left child to the supplied node
template <typename T>
void BTNode<T>::set_left(BTNode<T>* new_left) {
    left = new_left;
}

// Set right child to the supplied node
template <typename T>
void BTNode<T>::set_right(BTNode<T>* new_right) {
    right = new_right;
}

// Return a reference to the data item
template <typename T>
T& BTNode<T>::get_data() {
    return data;
}

// Return the value of the left child
template <typename T>
BTNode<T>* BTNode<T>::get_left() const {
    return left;
}

//Return the value of the right child
template <typename T>
BTNode<T>* BTNode<T>::get_right() const {
    return right;
}

// Overload the << operator for easy printing
template <typename T>
std::ostream& operator<<(std::ostream& out, const BTNode<T>& node) {
    out << node.get_data();
    return out;
}