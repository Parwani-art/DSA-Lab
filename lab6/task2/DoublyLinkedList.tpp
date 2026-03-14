// No #include needed here because DoublyLinkedList.h already included <iostream>

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
int DoublyLinkedList<T>::getSize() const {
    return size;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
void DoublyLinkedList<T>::sortedInsert(const T& value) {
    Node* newNode = new Node(value);

    // Case 1: empty list
    if (isEmpty()) {
        head = tail = newNode;
        size++;
        return;
    }

    // Case 2: insert at start (before head)
    if (value < head->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++;
        return;
    }

    // Case 3: insert at end (after tail)
    if (value >= tail->data) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        size++;
        return;
    }

    // Case 4: insert in middle
    Node* current = head;
    while (current != nullptr && current->data <= value) {
        current = current->next;
    }
    // current is first node with data > value, insert before it

    Node* prevNode = current->prev;

    newNode->prev = prevNode;
    newNode->next = current;

    prevNode->next = newNode;
    current->prev = newNode;

    size++;
}

template <typename T>
bool DoublyLinkedList<T>::deleteValue(const T& value) {
    if (isEmpty()) return false;

    // Find node
    Node* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    // Not found
    if (current == nullptr) return false;

    // Case 1: only one node
    if (head == tail) {
        delete current;
        head = tail = nullptr;
        size = 0;
        return true;
    }

    // Case 2: delete at start
    if (current == head) {
        head = head->next;
        head->prev = nullptr;
        delete current;
        size--;
        return true;
    }

    // Case 3: delete at end
    if (current == tail) {
        tail = tail->prev;
        tail->next = nullptr;
        delete current;
        size--;
        return true;
    }

    // Case 4: delete in middle
    Node* prevNode = current->prev;
    Node* nextNode = current->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete current;
    size--;
    return true;
}

template <typename T>
int DoublyLinkedList<T>::search(const T& key) const {
    Node* current = head;
    int pos = 1;

    while (current != nullptr) {
        if (current->data == key) return pos;
        current = current->next;
        pos++;
    }
    return -1;
}

template <typename T>
void DoublyLinkedList<T>::displayForward() const {
    if (isEmpty()) {
        std::cout << "List is empty\n";
        return;
    }

    Node* current = head;
    std::cout << "NULL <-> ";
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}

template <typename T>
void DoublyLinkedList<T>::displayBackward() const {
    if (isEmpty()) {
        std::cout << "List is empty\n";
        return;
    }

    Node* current = tail;
    std::cout << "NULL <-> ";
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->prev;
    }
    std::cout << "NULL\n";
}