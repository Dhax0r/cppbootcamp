#include <iostream>

typedef struct Node
{
        int data;
        struct Node *next = nullptr;
}Node_t;

void add(Node_t *&, const int &);
void remove(Node_t *&);
void print(Node_t *);

int main() {

    Node_t *my_linked_list = nullptr;
    
    
    add(my_linked_list, 5);
    add(my_linked_list, 6);
    add(my_linked_list, 7);
    print(my_linked_list);
    remove(my_linked_list);
    print(my_linked_list);



    return 0;
}


void add(Node_t *&LinkedList, const int &value) {
    if (LinkedList == nullptr) {
        std::cout << "LinkedList is nullptr" << std::endl;
        LinkedList = new Node_t;
        LinkedList->data = value;
    } else {
        Node_t *next_node, *tmp; 
        next_node = new Node_t;
        next_node->data = value;
        tmp = LinkedList;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = next_node;
    }
}

void remove(Node_t *&LinkedList) {
    Node_t *new_head = LinkedList->next;
    delete LinkedList;
    LinkedList = new_head;

}

void print(Node_t *LinkedList) {
    if (LinkedList == nullptr) {
        return;
    }
    do {
        std::cout << LinkedList->data << std::endl;
    } while ((LinkedList = LinkedList->next) != nullptr);
}