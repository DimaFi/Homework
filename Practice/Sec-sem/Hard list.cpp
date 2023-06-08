#include <iostream>

using namespace std;

class Node {
public:
    string data;
    Node* prev;
    Node* next;

    Node(string value) {
        data = value;
        prev = nullptr;
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

    void addWordPos(string word, int position) {
    Node* newNode = new Node(word);

    if (position == 0) {
        if (head != nullptr) {
            head->prev = newNode;
        }
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        int currentPosition = 0;

        while (current && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        } else {
            addWord(word);
        }
    }
}

    bool removeWord(string word) {
    if (head == nullptr) {
        return false;
    }

    if (head->data == word) {
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next) {
        if (current->next->data == word) {
            Node* temp = current->next;
            current->next = current->next->next;
            if (current->next) {
                current->next->prev = current;
            }
            delete temp;
            return true;
        }
        current = current->next;
    }

    return false;
}

    void addWord(string word) {
      Node* newNode = new Node(word);

      if (head == nullptr) {
          head = newNode;
      } else {
          Node* current = head;
          while (current->next) {
              current = current->next;
          }
          current->next = newNode;
          newNode->prev = current; 
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

    cout << "simply_list_2: " << endl;
    simply_list.printList();

    simply_list.addWordPos("apple", 7);
    simply_list.removeWord("date");


    cout << "simply_list_1: " << endl;
    simply_list.printList();

    int count = simply_list.countAndRemove();
    cout << "Count del: " << count << endl;

    cout << "New_list: " << endl;
    simply_list.printList();

}
