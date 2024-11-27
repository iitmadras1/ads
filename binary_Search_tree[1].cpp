#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createnode(int data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->left = newnode->right = nullptr;
    return newnode;
}
node *insertnode(node *root, int data)
{
    if (root == NULL)
    {
        root = createnode(data);
        return root;
    }
    if (data <= root->data)
    {
        root->left = insertnode(root->left, data);
    }
    else
    {
        root->right = insertnode(root->right, data);
    }
    return root;
}

node *deletenode(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data < root->data)
    {
        root->left = deletenode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deletenode(root->right, data);
    }
    else
    {
        // case 1:No child
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        // case 2: one child in left
        else if (root->left != NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        // case 3:one child in right
        else if (root->right != NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        // case 4: two child
        else if (root->left != NULL && root->right != NULL)
        {
            node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }
    return root;
}

void DFS(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        stack<node *> s;
        s.push(root);
        while (!s.empty())
        {
            node *current = s.top();
            s.pop();
            cout << current->data << " ";
            if (current->right)
            {
                s.push(current->right);
            }
            if (current->left)
            {
                s.push(current->left);
            }
        }
    }
}
void BFS(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }
}

void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        stack<node *> s;
        s.push(root);
        node *lastvisited = nullptr;
        node *current;

        while (!s.empty())
        {
            current = s.top();
            s.pop();
            if (current->left != nullptr && current->left != lastvisited && current->right != lastvisited)
            {
                s.push(current);
                s.push(current->left);
            }
            else if (current->right != nullptr && current->right != lastvisited)
            {
                s.push(current);
                s.push(current->right);
            }
            else
            {
                cout << current->data << " ";
            }
            lastvisited = current;
        }
    }
}
void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        stack<node *> s;
        s.push(root);
        node *lastvisited = nullptr;
        node *current;
        while (!s.empty())
        {
            current = s.top();
            s.pop();
            if (current->left != nullptr && current->left != lastvisited && current->right != lastvisited)
            {
                s.push(current);
                s.push(current->left);
            }
            else if (current->right != nullptr && current->right != lastvisited)
            {
                cout << current->data << " ";
                s.push(current);
                s.push(current->right);
            }
            else if (current->right == nullptr)
            {
                cout << current->data << " ";
            }
            lastvisited = current;
        }
    }
}

void preorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        preorder(root->data)
    }
}

int main()
{
    node *root = nullptr;
    int flag = 0;
    int node_value;
    cout << "Enter the value for the root node: ";
    cin >> node_value;
    root = insertnode(root, node_value);

    while (flag != 1)
    {
        cout << "Enter the node value: ";
        cin >> node_value;
        root = insertnode(root, node_value);
        cout << "To continue press 0 , To finish press 1 :- ";
        cin >> flag;
    }
    cout << "Your post order : ";
    postorder(root);
    cout << endl;

    cout << "Your Inorder : ";
    inorder(root);
    cout << endl;

    cout << "Your Preorder : ";
    preorder(root);
    cout << endl;

    cout << "Your DFS : ";
    DFS(root);
    cout << endl;

    cout << "Your BFS : ";
    BFS(root);
    cout << endl;
    int delval;
    cout << "delte the any value from bst: ";
    cin >> delval;
    root = deletenode(root, delval);
    cout << "Your BFS : ";
    BFS(root);
    cout << endl;
    cout << "Your Inorder : ";
    inorder(root);
    cout << endl;

    return 0;
}