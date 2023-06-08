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

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(string word) {
        Node* newNode = new Node(word);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    string dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }

        Node* temp = head;
        string dequeuedValue = head->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return dequeuedValue;
    }

    string peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void printQueue() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void removeAndCount() {

        string lastWord = tail->data;
        Queue tempQueue;
        
        cout << lastWord << endl;

        while (!isEmpty()) {
            string currentWord = peek();
            if (currentWord == lastWord) {
                dequeue();
            }
            else {
                tempQueue.enqueue(dequeue());
            }
        }

        while (!tempQueue.isEmpty()) {
            enqueue(tempQueue.dequeue());
        }

        enqueue(lastWord);
    }
};

int main() {
    Queue queue;

    queue.enqueue("apple");
    queue.enqueue("banana");
    queue.enqueue("apple");
    queue.enqueue("cherry");
    queue.enqueue("date");
    queue.enqueue("date");
    queue.enqueue("date");

    cout << "Queue: ";
    queue.printQueue();

    queue.removeAndCount();

    cout << "New Queue: ";
    queue.printQueue();

    return 0;
}
