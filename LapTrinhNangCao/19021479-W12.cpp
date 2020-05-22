#include <bits/stdc++.h>
using namespace std;

struct Node {
    int element;
    Node *next;
    Node *prev;

    Node(int e = NULL, Node *n = NULL, Node *p = NULL) {
        element = e;
        next = n;
        prev = p;
    }
};

struct Doubly_Linked_List {
    Node *head;
    Node *tail;

    Doubly_Linked_List() {
        head = NULL;
        tail = NULL;
    }
    ~Doubly_Linked_List() {
        for (Node *p = head; p != NULL; p = p->next)
            delete p;
    }
    void print() {
        for (Node *p = head; p != NULL; p = p->next)
            cout << p->element << " ";
        cout << endl;
    }
    void addFirst(int element) {
        Node *newNode = new Node(element, head, NULL);
        if (head == NULL)
            tail = newNode;
        else
            head->prev = newNode;
        head = newNode;
    }
    void addAfter(Node *node, int element) {
        Node *newNode = new Node(element, node->next, node);
        node->next = newNode;
        if (node->next == NULL)
            tail = newNode;
    }
    void addBefore(Node *node, int element) {
        Node *newNode = new Node(element, node, node->prev);
        node->prev = newNode;
        if (node->prev == NULL)
            head = newNode;
    }
    void addLast(int element) {
        Node *newNode = new Node(element, NULL, tail);
        if (tail == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }
    int removeNode(Node *node) {
        if (node == NULL) return NULL;
        int e = node->element;
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
        return e;
    }
    int removeFirst() {
        return removeNode(head);
    }
    int removeLast() {
        return removeNode(tail);
    }
    Node *findNode(int element) {
        for (Node *p = head; p != NULL; p = p->next)
            if (p->element == element)
                return p;
        return NULL;
    }
    void removeOnce(int element) {
        removeNode(findNode(element));
    }
    void removeAll(int element) {
        Node *delNode;
        do {
            delNode = findNode(element);
            removeNode(delNode);
        } while (delNode);
    }
};

int main() {
    system("cls");
    Doubly_Linked_List list;
    int n, tmp;
    cout << "TAO DANH SACH LIEN KET DOI\nKieu du lieu: int\nDanh sach ham: Constructor, Destructor, print, addFirst, addAfter, addBefore, addLast, removeNode, removeFirst, removeLast, findNode, removeOnce, removeAll\n\nNhap so nut: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap nut " << i << ": ";
        cin >> tmp;
        list.addLast(tmp);
    }
    cout << "Danh sach da nhap la:\n";
    list.print();

    cout << "Them nut vao dau danh sach\nNhap du lieu: ";
    cin >> tmp;
    list.addFirst(tmp);
    cout << "Danh sach sau khi them nut:\n";
    list.print();

    cout << "Xoa nut dau danh sach\nNut dau danh sach: " << list.removeFirst() << endl;
    cout << "Danh sach sau khi xoa nut:\n";
    list.print();

    cout << "Them nut vao cuoi danh sach\nNhap du lieu: ";
    cin >> tmp;
    list.addLast(tmp);
    cout << "Danh sach sau khi them nut:\n";
    list.print();

    cout << "Xoa nut cuoi danh sach\nNut cuoi danh sach: " << list.removeLast() << endl;
    cout << "Danh sach sau khi xoa nut:\n";
    list.print();

    cout << "Xoa nut dau tien chua du lieu nhap vao\nNhap du lieu nut muon xoa: ";
    cin >> tmp;
    list.removeOnce(tmp);
    cout << "Danh sach sau khi xoa nut:\n";
    list.print();

    cout << "Xoa tat ca nut chua du lieu nhap vao\nNhap du lieu nut muon xoa: ";
    cin >> tmp;
    list.removeAll(tmp);
    cout << "Danh sach sau khi xoa nut:\n";
    list.print();
    return 0;
}