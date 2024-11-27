#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    string name;
    Node *left;
    Node *leftcentre;
    Node *rightcentre;
    Node *right;

    Node(string name2)
    {
        name = name2;
        left = NULL;
        leftcentre = NULL;
        rightcentre = NULL;
        right = NULL;
    }
};

Node *root = NULL;

Node *searchNode(string key)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return NULL;
    }

    stack<Node *> myStack;
    myStack.push(root);
    while (!myStack.empty())
    {
        Node *start = myStack.top();
        myStack.pop();
        if (start->name == key)
        {

            cout << "Found\n";
            return start;
        }
        else
        {
            if (start->left != NULL)
            {
                myStack.push(start->left);
            }
            if (start->leftcentre != NULL)
            {
                myStack.push(start->leftcentre);
            }
            if (start->rightcentre != NULL)
            {
                myStack.push(start->rightcentre);
            }
            if (start->right != NULL)
            {
                myStack.push(start->right);
            }
        }
    }
    cout << "Element not found\n";
    return NULL;
}

void addNode(int position, string parent, string name3)
{
    if (root == NULL)
    {
        root = new Node(name3);
        cout << "Element added\n";
    }
    else
    {
        Node *temp = new Node(name3);
        Node *tempParent = searchNode(parent);
        if (tempParent == NULL)
        {
            // cout << "Parent node not found\n";
            delete temp;
            return;
        }
        if (position == 1)
        {
            tempParent->left = temp;
            cout << "Element added\n";
        }
        else if (position == 2)
        {
            tempParent->leftcentre = temp;
            cout << "Element added\n";
        }
        else if (position == 3)
        {
            tempParent->rightcentre = temp;
            cout << "Element added\n";
        }
        else if (position == 4)
        {
            tempParent->right = temp;
            cout << "Element added\n";
        }
        else
        {
            cout << "Entered wrong position\n";
            delete temp;
        }
    }
}

void printTree(Node *temp)
{

    if (temp != NULL)
    {
        cout << temp->name << endl;

        if (temp->left != NULL)
        {
            printTree(temp->left);
        }
        if (temp->leftcentre != NULL)
        {
            printTree(temp->leftcentre);
        }
        if (temp->rightcentre != NULL)
        {
            printTree(temp->rightcentre);
        }
        if (temp->right)
        {
            printTree(temp->right);
        }
    }
}

void Preorder(Node *temp)
{

    if (temp->left != NULL || temp->right != NULL)
    {
        cout << temp->name << endl;
    }
    if (temp->left != NULL)
    {
        Preorder(temp->left);
    }
    if (temp->right != NULL)
    {
        Preorder(temp->right);
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        cout << temp->name << endl;
    }
}

void PostOrder(Node *temp)
{

    if (temp == NULL)
        return;

    PostOrder(temp->left);
    PostOrder(temp->right);
    cout << temp->name << endl;
}
void Inorder(Node *temp)
{

    if (temp == NULL)
        return;
    Inorder(temp->left);
    cout << temp->name << endl;
    Inorder(temp->right);
}

int main()
{
    int helpme = 1;
    int ch, pstn;
    string name;
    string parentname;
    while (true)
    {
        cout << "1. To Add a node in the tree\n";
        cout << "2. To Search a node in the tree\n";
        cout << "3. Print Node Randomly\n";
        cout << "4. Print Node in InOrder\n";
        cout << "5. Print Node in PostOrder\n";
        cout << "6. Print Node in PreOrder\n";
        cout << "7. Exit\n";
        while (!(cin >> ch))
        {
            cin.clear();
            cin.ignore(100, '\n');
            //
            cout << "Wrong choice entered" << endl;
            break;
        }

        switch (ch)
        {
        case 1:
            cout << "Enter The name to be added\n";
            cin >> name;

            if (root == nullptr)
            {
                addNode(pstn, parentname, name);
            }
            else
            {

                cout << "Enter the name of parent node\n";
                cin >> parentname;
                cout << "Enter Position to be added\n";
                if (!(cin >> pstn))
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    // cout << "Wrong position entered" << endl;
                    break;
                }
                addNode(pstn, parentname, name);
            }
            break;
        case 2:
            cout << "Enter the Name to be Searched\n";
            cin >> name;
            searchNode(name);
            break;

        case 3:
            printTree(root);

            break;

        case 7:
            cout << "The Program Ends\n";
            return 0;

        case 4:
            Inorder(root);
            break;
        case 6:
            Preorder(root);
            break;
        case 5:
            PostOrder(root);
            break;

        default:
            cout << "Wrong choice, the program will run again\n";
            break;
        }
    }

    return 0;
}