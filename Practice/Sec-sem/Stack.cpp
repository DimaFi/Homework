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

class Stack {

private:
    Node* head;

public:

    Stack() {
        head = nullptr;
    }

    void push(string word) {
        Node* newNode = new Node(word);
        newNode->next = head;
        head = newNode;
    }

    void countAndRemove() {
        if (isEmpty()) {
            return;
        }

        string lastWord = pop();
        Stack tempStack;
        tempStack.push(lastWord);
        cout << lastWord << endl;

        while (!isEmpty()) {
            string currentWord = peek();
            if (currentWord == lastWord) {
                pop();
            }
            else {
                tempStack.push(pop());
            }
        }

        while (!tempStack.isEmpty()) {
            push(tempStack.pop());
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    string pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }

        Node* temp = head;
        string poppedValue = head->data;
        head = head->next;
        delete temp;
        return poppedValue;
    }

    string peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return head->data;
    }

    void printStack() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {

    Stack simply_list;

    simply_list.push("apple");
    simply_list.push("banana");
    simply_list.push("apple");
    simply_list.push("cherry");
    simply_list.push("date");
    simply_list.push("date");
    simply_list.push("date");



    cout << "simply_list_1: " << endl;
    simply_list.printStack();

    cout << "------------" << endl;

    simply_list.countAndRemove();

    cout << "------------" << endl;

    cout << "New_list: " << endl;
    simply_list.printStack();

}
