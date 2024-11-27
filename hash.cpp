#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

const int tableSize = 10;
Node *arr[tableSize] = {nullptr};

int hashFunction(int value)
{
    return value % tableSize;
}

void insertValue(int value)
{
    int index = hashFunction(value);
    Node *newNode = new Node(value);
    newNode->next = arr[index];
    arr[index] = newNode;
}

void displayHashTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << "Bucket " << i << ": ";
        Node *current = arr[i];
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
}

int main()
{
    insertValue(15);
    insertValue(25);
    insertValue(35);
    insertValue(5);
    insertValue(50);

    cout << "Hash table contents:" << endl;
    displayHashTable();

    return 0;
}
