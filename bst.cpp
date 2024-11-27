#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};
Node *root = nullptr;
void addNode(int value)
{

    if (root == nullptr)
    {
        root = new Node(value);
    }
    else
    {
        Node *temp = root;
        while (true)
        {
            if (value < temp->data)
            {

                if (temp->left == nullptr)
                {
                    temp->left = new Node(value);
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            if (value > temp->data)
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(value);
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                cout << "Value already exists\n";
            }
        }
    }
}

void inorder(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }
    inorder(temp->left);
    cout << temp->data << endl;
    inorder(temp->right);
}

int main(int argc, char const *argv[])
{
    addNode(10);
    addNode(7);
    addNode(2);
    addNode(0);
    addNode(30);
    addNode(35);
    addNode(9);
    addNode(40);
    inorder(root);
    return 0;
}
