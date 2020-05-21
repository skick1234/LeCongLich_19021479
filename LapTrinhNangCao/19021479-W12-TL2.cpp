#include <bits/stdc++.h>
using namespace std;

struct Node {
    char c;
    Node *next;
    Node *prev;

    Node(char ch = NULL, Node *n = NULL) {
        c = ch;
        next = n;
        prev = NULL;
    }
};
struct DLinkedList {
    Node *head;
    Node *tail;

    DLinkedList() {
        head = NULL;
        tail = NULL;
    }
    void print() {
        for (Node *p = head; p != NULL; p = p->next) {
            cout << p->c;
        }
        cout << endl;
    }
    void addFirst(char c) {
        Node *newNode;
        newNode = new Node();
        newNode->c = c;
        newNode->prev = NULL;
        newNode->next = head;

        if (head == NULL)
            tail = newNode;
        else
            head->prev = newNode;
        head = newNode;
    }
    void addAfter(Node *node, char c) {
        Node *newNode;
        newNode = new Node();
        newNode->c = c;
        newNode->prev = node;
        newNode->next = node->next;
        node->next = newNode;
        if (node->next == NULL)
            tail = newNode;
    }
    void addBefore(Node *node, char c) {
        Node *newNode;
        newNode = new Node();
        newNode->c = c;
        newNode->next = node;
        newNode->prev = node->prev;
        node->prev = newNode;
        if (node->prev == NULL)
            head = newNode;
    }
    void addLast(char c) {
        Node *newNode;
        newNode = new Node();
        newNode->c = c;
        newNode->prev = tail;
        newNode->next = NULL;
        if (tail == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }
    void deleteNode(Node *node) {
        if (node->prev == NULL) {
            head = node->next;
            head->prev = NULL;
        } else if (node->next == NULL) {
            tail = node->prev;
            tail->next = NULL;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
    }
};

int main() {
    system("cls");
    DLinkedList stringlist;
    string str;
    cout << "Nhap xau ki tu: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
        stringlist.addLast(str[i]);
    Node *check = stringlist.head;
    while (check != NULL && check->next != NULL) {
        if (check->next->c == check->c) {
            Node *tmp = check->next->next;
            stringlist.deleteNode(check->next);
            stringlist.deleteNode(check);
            stringlist.print();
            check = tmp;
        } else {
            check = check->next;
        }
    }
    cout << "Xau sau khi loc: ";
    stringlist.print();
    return 0;
}