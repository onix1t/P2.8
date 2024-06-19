#include <iostream>

using namespace std;

// Определение структуры узла списка
struct Node {
    int data;
    Node* next;
    
    Node(int data) : data(data), next(nullptr) {}
};

// Функция для добавления нового узла за каждым вхождением элемента E
void addAfter(Node*& head, int E, int L) {
    Node* current = head;
    
    while (current != nullptr) {
        if (current->data == E) {
            Node* newNode = new Node(L);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next; // Перемещение на следующий узел после нового
        } else {
            current = current->next;
        }
    }
}

// Функция для печати списка
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    cout << "Практика 8 | Вариант 7\r\n\r\n";
    
    // Создание начального списка 1 -> 2 -> 3 -> 4 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    cout << "Оригинальный лист: ";
    printList(head);
    
    // Добавление элемента 5 за каждым вхождением элемента 2
    addAfter(head, 2, 5);
    
    cout << "Изменённый лист: ";
    printList(head);
    
    // Освобождение памяти (необходимо для избегания утечек памяти)
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
