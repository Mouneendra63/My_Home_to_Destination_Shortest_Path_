#include <iostream>
using namespace std;

// Define the Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Define the LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Method to append a new node to the linked list
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Method to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int arr[] = {2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    LinkedList list;
    for (int i = 0; i < n; ++i) {
        list.append(arr[i]);
    }

    list.display();  // Output: 2 3 4 5

    return 0;
}
