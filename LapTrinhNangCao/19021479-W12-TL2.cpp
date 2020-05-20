#include <bits/stdc++.h>

using namespace std;
struct Node {
    char *element;
    Node *next;

    Node(char *e = NULL, Node *n = NULL) {
        element = e;
        next = n;
    }
};

struct SLinkedList {
    Node *head;
    long size;

    SLinkedList() {
        head = NULL;
        size = 0;
    }
    long length() {
        return size;
    }
    void print() {
        for (Node *p = head; p != NULL; p = p->next) {
            cout << p->element << ".";
        }
    }
    bool isEmpty() {
        return head == NULL;
    }
    void insertAfter(Node *node, char *element) {
        Node *newNode = new Node(element, node->next);
        node->next = newNode;
        size++;
    }
    void addFirst(char *s) {
        head = new Node(s, head);
        size++;
    }
    char *removeFirst() {
        Node *oldhead = head;
        char *old_element = oldhead->element;
        head = head->next;
        delete oldhead;
        size--;
        return old_element;
    }
    void removeNode(Node *node) {
        if (node == head) {
            this->removeFirst();
        } else {
            
        }
    }
};

int main() {
    return 0;
}