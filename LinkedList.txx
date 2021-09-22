#include "LinkedList.hpp"

template<class T>
LinkedList<T>::LinkedList() : head(nullptr), count(0) {}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &rhs) {
    if (rhs.head == nullptr) {
        head = nullptr;
        count = 0;
    } else {
        head = new Node<T>(rhs.head->getItem());
        Node<T> *curr = head;
        Node<T> *obj = rhs.head;
        while (obj != nullptr) {
            curr->setNext(new Node<T>(obj->getNext()->getItem(), obj->getNext()->getNext()));
            curr = curr->getNext();
            obj = obj->getNext();
        }
    }
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList rhs) {
    if (this == &rhs) {
        return *this;
    }
    LinkedList<T> temp(rhs);
    swap(this, temp);
    delete temp;
    return *this;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T> *curr = head;
    while (curr != nullptr) {
        Node<T> *temp = curr;
        curr = curr->getNext();
        delete temp;
    }
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    return count == 0;
}

template<class T>
int LinkedList<T>::getLength() const {
    return count;
}

template<class T>
bool LinkedList<T>::insert(int newPosition, const T &newEntry) {
    if (isValidIndex(newPosition)) {
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

template<class T>
bool LinkedList<T>::remove(int position) {
    if (isEmpty()) { return false; }
    if (isValidIndex(position)) {
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

template<class T>
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

template<class T>
T LinkedList<T>::getEntry(int position) const {
    if (isValidIndex(position)) {
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
    throw std::out_of_range("Index out of bounds.");
}

template<class T>
T LinkedList<T>::setEntry(int position, const T &newValue) {
    if (isValidIndex(position)) {
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
    throw std::out_of_range("Index out of bounds.");
}

template<class T>
void LinkedList<T>::swap(LinkedList &lhs, LinkedList &rhs) {
    int len = lhs.getLength() > rhs.getLength() ? rhs.getLength() : lhs.getLength();
    Node<T> *lCurr = lhs.head;
    Node<T> *rCurr = rhs.head;
    while (lCurr != nullptr) {
        Node<T> *temp = lCurr;
        lCurr = rCurr;
        rCurr = temp;
        lCurr = lCurr->getNext();
        rCurr = rCurr->getNext();
    }
}

template<class T>
Node<T> *LinkedList<T>::getNodeAt(int position) const {
    if (isValidIndex(position)) {
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
    throw std::out_of_range("Index out of bounds.");
}

template<class T>
bool LinkedList<T>::isValidIndex(int index) const {
    return ((index >= 1) && (index <= getLength() + 1));
}
