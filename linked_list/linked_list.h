#include <iostream>

template <class T>
struct Node
{
	 T data;
	 Node* next;
};

template <class T>
class linked_list
{
public:
	linked_list();
	linked_list(const linked_list& otherList);
	~linked_list();

	linked_list& operator=(const linked_list & otherList);

	void printList();
	int getSize();
	void push_back(T val);
	void pop_front();
	void insert(T val);
	Node<T>* getHead();
private:
	Node<T>* head;
	Node<T>* tail;
};

template <class T>
linked_list<T>::linked_list(): head(NULL), tail(NULL) {
    
}

template <class T>
linked_list<T>::linked_list(const linked_list& otherList){
	const Node<T>* curr = otherList.getHead();

	// no current head make a new one pointing to the otherlist's head
	if(!head && curr){
		head = new Node<T>();
		tail = new Node<T>();
		tail = head;
		tail->next = NULL;
		curr = curr->next;
	}

	// keep making newNodes until the next pointer becomes null;
	while(curr){
		Node<T>* newNode = new Node<T>();
		newNode->data = curr->data;
		tail->next = newNode;
		tail = newNode;
		curr = curr->next;
	}
}


template<class T>
linked_list<T>::~linked_list<T>(){
    Node<T>* curr = head;
    while (head != NULL) {
        head = head->next;
        delete curr;
        curr = head;
    }
}


/*
* assignment operator that makes the lhs headPointer reference the
* head pointer of the rhs.
*/
template<class T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T> &rhs){
    // delete the old list first to prevent memory leaks
    Node<T>* curr = head;
    while(curr){
        Node<T>* itemToDelete = curr;
        curr = curr->next;
        delete itemToDelete;
    }
    
    // now make the head point to the other list head
    head = rhs.getHead();
    return this;
}

template<class T>
void linked_list<T>::printList(){
    Node<T>* curr = head;
    while(curr){
        std::cout << curr->data;
        if(curr->next){
            std::cout << ",";
        }
        curr = curr->next;
    }
    std::cout <<std::endl;
    return;
}

template<class T>
void linked_list<T>::push_back(T val){
    Node<T>* newItem = new Node<T>();
    newItem->data = val;
    // first make a head and tail if none exist
    if(!head){
        head = newItem;
        tail = head;
        return;
    }
    
    tail->next = newItem;
    tail = newItem;
    return;
}

template<class T>
void linked_list<T>::pop_front(){
    if(!head){
        return;
    }
    Node<T>* curr = head->next;
    delete head;
    head = curr;
    
    return;
}

template<class T>
Node<T>* linked_list<T>::getHead(){
	return head;
}