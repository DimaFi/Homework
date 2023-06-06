#include <iostream>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};

class SimplyLinkedList {

private:
    Node* head;

public:

    SimplyLinkedList() {
        head = nullptr;
    }

    void addWord(string word) {
        Node* newNode = new Node(word);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int countAndRemove() {
        if (head == nullptr) {
            return 0;
        }

        string lastWord = head->data;
        Node* current = head->next;
        int count = 0;

        while (current) {
            if (current->data == lastWord) {
                count++;
                current = current->next;
            }
            else {
                break;
            }
        }

        if (count > 0) {
            head = current;
        }

        Node* previous = current;
        current = current->next;

        while (current) {
            if (current->data == lastWord) {
                count++;
                previous->next = current->next;
                current = current->next;
            }
            else {
                previous = current;
                current = current->next;
            }
        }

        return count;
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {

    SimplyLinkedList simply_list;

    simply_list.addWord("apple");
    simply_list.addWord("banana");
    simply_list.addWord("apple");
    simply_list.addWord("cherry");
    simply_list.addWord("apple");
    simply_list.addWord("date");
    simply_list.addWord("date");
    simply_list.addWord("date");

    cout << "simply_list_1: " << endl;
    simply_list.printList();

    int count = simply_list.countAndRemove();
    cout << "Count del: " << count << endl;

    cout << "New_list: " << endl;
    simply_list.printList();

}
