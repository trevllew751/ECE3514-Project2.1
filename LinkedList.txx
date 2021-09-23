#include "LinkedList.hpp"
#include <stdexcept>

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), count(0) {}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &rhs) {
    if (rhs.head == nullptr) {
        head = nullptr;
        count = 0;
    } else {
        head = new Node<T>(rhs.head->getItem(), rhs.head->getNext());
        count = 1;
        Node<T> *curr = head;
        Node<T> *next = rhs.head->getNext();
        while (next != nullptr) {
            curr->setNext(new Node<T>(next->getItem(), next->getNext()));
            count++;
            curr = curr->getNext();
            next = next->getNext();
        }
    }
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList rhs) {
    if (this != &rhs) {
        LinkedList<T> temp(rhs);
        swap(*this, rhs);
        count = rhs.count;
    }
    return *this;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *curr = head;
    while (curr != nullptr) {
        head = head->getNext();
        delete curr;
        curr = head;
    }
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return count == 0;
}

template<typename T>
int LinkedList<T>::getLength() const {
    return count;
}

template<typename T>
bool LinkedList<T>::insert(int newPosition, const T &newEntry) {
    if ((newPosition >= 1) && (newPosition <= this->getLength() + 1)) {
        if (newPosition == 1) {
            Node<T> *temp = head;
            head = new Node<T>(newEntry, temp);
            count++;
            return true;
        }
        int currentPos = 1;
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (currentPos + 1 == newPosition) {
                Node<T> *newNode = new Node<T>(newEntry, curr->getNext());
                curr->setNext(newNode);
                count++;
                return true;
            }
            curr = curr->getNext();
            currentPos++;
        }
    }
    return false;
}

template<typename T>
bool LinkedList<T>::remove(int position) {
    if (isEmpty()) { return false; }
    if ((position >= 1) && (position <= this->getLength() + 1)) {
        if (position == 1) {
            Node<T> *temp = head;
            head = head->getNext();
            count--;
            delete temp;
            return true;
        }
        int currentPos = 1;
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (currentPos + 1 == position) {
                Node<T> *temp = curr->getNext();    // Get pointer to node that needs removal
                curr->setNext(curr->getNext()->getNext());
                delete temp;                        // Free up memory from removed node
                count--;
                return true;
            }
            curr = curr->getNext();
            currentPos++;
        }
    }
    return false;
}

template<typename T>
void LinkedList<T>::clear() {
    Node<T> *curr = head;
    while (curr != nullptr) {
        Node<T> *temp = curr;
        curr = curr->getNext();
        delete temp;
    }
    head = nullptr;
    count = 0;
}

template<typename T>
T LinkedList<T>::getEntry(int position) const {
    if ((position >= 1) && (position <= this->getLength() + 1)) {
        if (position == 1) { return head->getItem(); }
        int currentPos = 1;
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (currentPos + 1 == position) {
                T item = curr->getNext()->getItem();
                return curr->getNext()->getItem();
            }
            currentPos++;
            curr = curr->getNext();
        }
    }
    throw std::logic_error("Index out of bounds.");
}

template<typename T>
T LinkedList<T>::setEntry(int position, const T &newValue) {
    if ((position >= 1) && (position <= this->getLength() + 1)) {
        if (position == 1) {
            T temp = head->getItem();
            head->setItem(newValue);
            return temp;
        }
        int currentPos = 1;
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (currentPos + 1 == position) {
                T temp = curr->getNext()->getItem();
                curr->getNext()->setItem(newValue);
                return temp;
            }
            currentPos++;
            curr = curr->getNext();
        }
    }
    throw std::logic_error("Index out of bounds.");
}

template<typename T>
void LinkedList<T>::swap(LinkedList &lhs, LinkedList &rhs) {
    Node<T> *temp = lhs.head;
    lhs.head = rhs.head;
    rhs.head = temp;
}

template<typename T>
Node<T> *LinkedList<T>::getNodeAt(int position) const {
    if ((position >= 1) && (position <= this->getLength() + 1)) {
        if (position == 1) { return head; }
        int currentPos = 1;
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (currentPos + 1 == position) {
                return curr->getNext();
            }
            currentPos++;
            curr = curr->getNext();
        }
    }
    throw std::logic_error("Index out of bounds.");
}

//template<typename T>
//bool LinkedList<T>::isValidIndex(int index) const {
//    return ((index >= 1) && (index <= this->getLength() + 1));
//}
