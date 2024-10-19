#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *next;
};

void append_node(Node **head, int val);
void print_list(Node *head);
void invert_list(Node **head);

int main(void){
    Node *list = NULL;

    append_node(&list, 1);
    append_node(&list, 2);
    append_node(&list, 3);
    append_node(&list, 4);
    append_node(&list, 5);
    print_list(list);
    invert_list(&list);
    print_list(list);

    return 0;
}

void append_node(Node **head, int val){
    Node *new_node = new Node;
    new_node->val = val;
    new_node->next = NULL;

    if (!*head) *head = new_node;
    else{
        Node *curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = new_node;
    }
}

void invert_list(Node **head){
    Node *prev = NULL, *curr = *head, *next = (*head)->next;

    while (curr){
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next) next = next->next;
    }
    *head = prev;
}

void print_list(Node *head){
    if (!head) cout << "Lista je prazna." << endl;
    while (head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}