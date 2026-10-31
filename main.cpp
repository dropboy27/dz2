#include <iostream>

using namespace std;

typedef struct Node
{
    int t;           // time of event
    int count;       // events in this time
    int h;           // height for avl tree
    int chil_events; // num of events in podderevo
    Node *left;
    Node *right;
} Node;

int get_height(Node *root)
{
    int height;
    if (root == NULL)
    {
        height = 0;
    }
    else
    {
        height = root->h;
    }
    return height;
}

void recalculate_height(Node *root)
{
    if (root != NULL)
    {
        root->h = 1 + max(get_height(root->left), get_height(root->right));
    }
}

Node *insert(Node *root, int time)
{
    if (root->t == time)
    {
        root->count++;
        recalculate_height(root);
        return root;
    }
    if (root->t > time)
    {
        root->left = insert(root->left, time);
        recalculate_height(root->left);
    }
    if (root->t < time)
    {
        root->right = insert(root->right, time);
        recalculate_height(root->right);
    }
    recalculate_height(root);
    return root;
}

Node balancing(Node *root)
