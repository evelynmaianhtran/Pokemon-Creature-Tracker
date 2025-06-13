// Constructor
template <typename T>
BSTree<T>::BSTree() {
    root = nullptr;
    count = 0;
}

// Destructor
template <typename T>
BSTree<T>::~BSTree() {
    clear();
}

// The supplied data is inserted into the binary search tree.
template <typename T>
void BSTree<T>::insert(const T& data) {
    root = insert(data, root);
}

// Remove the item with the specified key from the tree, if it exists. 
template <typename T>
void BSTree<T>::remove(const std::string& key) {
    remove(key, root);
}

// Determine if an item with the specified key exists.
template <typename T>
bool BSTree<T>::contains(const std::string& key) const {
    return contains(key, root);
}

// Clears all nodes from the tree.
template <typename T>
void BSTree<T>::clear() {
    clear(root);
    root = nullptr;
    count = 0;
}

// Return a pointer to the item with the specified key, if it exists. 
template <typename T>
T* BSTree<T>::find(const std::string& key) const {
    BTNode<T>* node = find(key, root);
    if (node)
        return &node->get_data();
    else 
        return nullptr;
}

// Return a reference to the item with the minimum data value. 
// If the tree is empty, an empty_collection_exception is thrown.
template <typename T>
T& BSTree<T>::find_min() const {
    if(empty() || !root) //sanity check!
        throw empty_collection_exception();
    return find_min(root)->get_data();
}

// Return a reference to the item with the maximal data value. 
template <typename T>
T& BSTree<T>::find_max() const {
    if(empty() || !root) //sanity check!
        throw empty_collection_exception();    
    return find_max(root)->get_data();
}

// Return true if the tree is emtpy, false otherwise.
template <typename T>
bool BSTree<T>::empty() const {
    if (count == 0)      return true;
    else                return false;
}

// Return the number of nodes in the tree.
template <typename T>
int BSTree<T>::size() const {
    return count;
}

// Append the value of each node in the tree to the supplied stream using an inorder traversal.
template <typename T>
void BSTree<T>::print_inorder(std::ostream& out) const {
    print_inorder(out, root);
}

// Append the value of each node in the tree to the supplied stream using a preorder traversal. 
template <typename T>
void BSTree<T>::print_preorder(std::ostream& out) const {
    print_preorder(out, root);
}

// Append the value of each node in the tree to the supplied stream using a postorder traversal.
template <typename T>
void BSTree<T>::print_postorder(std::ostream& out) const {
    print_postorder(out, root);
}

// Clears all nodes from the sub-tree rooted at the supplied node.
template <typename T>
void BSTree<T>::clear(BTNode<T>* root) {
    if(root) {
        clear(root->get_left());
        clear(root->get_right());
        delete root;
        count --;
    }
}

// The supplied data is inserted into the sub-tree rooted at the supplied node.
template <typename T>
BTNode<T>* BSTree<T>::insert(const T& data, BTNode<T>* node) {
    if(!node) {
        count++;
        return new BTNode<T>(data);
    } 
    else if (data < node->get_data()) 
        node->set_left(insert(data, node->get_left())); //Recursive call
    else if (data > node->get_data())
        node->set_right(insert(data, node->get_right()));
    else //duplicate, replace data
        node->set_data(data);
    return node;
}

// Remove the item with the specified key from the sub-tree rooted at the supplied node, if it exists. A pointer to the node is returned.
template <typename T>
BTNode<T>* BSTree<T>::remove(const std::string& key, BTNode<T>* node) {
    if(!node) 
        return nullptr;
    else if(key < node->get_data().get_key())
        node->set_left(remove(key, node->get_left()));
    else if(key > node->get_data().get_key())
        node->set_right(remove(key, node->get_right()));
    else {
        // Remove a node with only one child or no child
        if (!node->get_left()) {
            BTNode<T>* temp = node->get_right();
            delete node;
            count--;  // Decrement the count
            return temp;
        } 
        else if (!node->get_right()) {
            BTNode<T>* temp = node->get_left();
            delete node;
            count--;  // Decrement the count
            return temp;
        }
        // Remove a node with 2 children
        BTNode<T>* temp = find_min(node->get_right());   //Get the smallest value in the right sub-tree
        node->set_data(temp->get_data()); // Copy the inorder successor's data to this node
        node->set_right(remove(temp->get_data().get_key(), node->get_right()));// Delete the inorder successor
    }
    return node;
}

// Determine if an item with the specified key exists.
template <typename T>
bool BSTree<T>::contains(const std::string& key, BTNode<T>* node) const {
    if (!node)
        return false;
    if (key == node->get_data().get_key()) 
        return true;
    if (key < node->get_data().get_key()) 
        return contains(key, node->get_left());
    if (key > node->get_data().get_key())
        return contains(key, node->get_right());

    return false; // This line is not strictly necessary but added for clarity.
}

// Return a pointer to the item with the specified key, if it exists. If no such item exists, nullptr is returned.
template <typename T>
BTNode<T>* BSTree<T>::find(const std::string& key, BTNode<T>* node) const {
    if(!node)
        return nullptr;
    if (key == node->get_data().get_key())
        return node;
    if (key < node->get_data().get_key())
        return find(key, node->get_left());
    if (key > node->get_data().get_key())
        return find(key, node->get_right());

    return nullptr;   
}

// Return a pointer to the node containing the item with the minimum data value in the sub-tree rooted at the supplied node. 
template <typename T>
BTNode<T>* BSTree<T>::find_min(BTNode<T>* node) const {
    if(!node->get_left()) //no further child, return
        return node;
    return find_min(node->get_left());
}

// Return a pointer to the node containing the item with the maximum data value in the sub-tree rooted at the supplied node. 
template <typename T>
BTNode<T>* BSTree<T>::find_max(BTNode<T>* node) const {
    if(!node->get_right()) //no further child, return
        return node;
    return find_max(node->get_right());
}

// Append the value of each node in the sub-tree rooted at the supplied node, to the supplied stream, using an inorder traversal. 
template <typename T>
void BSTree<T>::print_inorder(std::ostream& out, BTNode<T>* node) const {
    if(node) {
        print_inorder(out, node->get_left());
        out << node->get_data() << " ";
        print_inorder(out, node->get_right());
    }
}

// Append the value of each node in the sub-tree rooted at the supplied node, to the supplied stream, using a preorder traversal. 
template <typename T>
void BSTree<T>::print_preorder(std::ostream& out, BTNode<T>* node) const {
    if(node) {
        out << node->get_data() << " ";
        print_preorder(out, node->get_left());
        print_preorder(out, node->get_right());
    }
}

// Append the value of each node in the sub-tree rooted at the supplied node, to the supplied stream, using a postorder traversal. 
template <typename T>
void BSTree<T>::print_postorder(std::ostream& out, BTNode<T>* node) const {
    if(node) {
        print_postorder(out, node->get_left());
        print_postorder(out, node->get_right());
        out << node->get_data() << " ";
    }
}

// Append the value of each node in the sub-tree rooted at the supplied node, to the supplied stream. 
template <typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree)
{
    if(tree.empty()) 
        out << "Empty tree" << std::endl;
    else 
        tree.print_inorder(out);
    return out;
}
