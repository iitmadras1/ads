#include <iostream>
using namespace std;
class Node
{

public:
    int data;
    Node *left;
    Node *right;
    bool thread;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
        thread = false;
    }
};
Node *root;
void insertNode(Node *&root, int value)
{

    if (root == nullptr)
    {
        root = new Node(value);
    }
    else
    {

        Node *newNode = new Node(value);

        Node *crnt;
        Node *prnt;
        crnt = root;
        while (crnt != nullptr)
        {
            prnt = crnt;
            if (value < crnt->data)
            {
                if (crnt->left == nullptr)
                {
                    break;
                }
                else
                {
                    crnt = crnt->left;
                }
            }
            else if (value > crnt->data)
            {
                if (crnt->right == nullptr || crnt->thread)
                {
                    break;
                }
                else
                {
                    crnt = crnt->right;
                }
            }
        }
        if (value < prnt->data)
        {
            prnt->left = newNode;
            newNode->right = prnt;
            newNode->thread = true;
        }
        else if (value > prnt->data)
        {
            if (prnt->thread)
            {
                newNode->right = prnt->right;
                prnt->thread = false;
                newNode->thread = true;
            }
            prnt->right = newNode;
        }
    }
}
void inOrder(Node *temp)
{

    if (root = nullptr)
    {
        cout << "Empty tree\n";
        return;
    }

    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        if (temp->thread)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->right;
            while (temp != nullptr && temp->left != nullptr)
            {
                temp = temp->left;
            }
        }
    }
}

int main()
{
    insertNode(root, 10);
    insertNode(root, 58);
    insertNode(root, 21);
    insertNode(root, 471);
    insertNode(root, 69);
    insertNode(root, 5878);
    insertNode(root, 1);
    insertNode(root, 100);
    inOrder(root);
    return 0;
}
