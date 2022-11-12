#include <stdio.h>

typedef struct node Tree_Node;
struct node
{
    int root;
    Tree_Node *left_node;
    Tree_Node *right_node;
};

void in_order(Tree_Node *root);
Tree_Node *create_tree_node(int item);
void add_left_node(Tree_Node *root, Tree_Node *child);
void add_right_node(Tree_Node *root, Tree_Node *child);
Tree_Node *create_tree();

int main(void)
{
    Tree_Node *root;

    root = create_tree();
    printf("Root data: %d\n", root->root);

    in_order(root);

    return 0;
}

// In order traversal
void in_order(Tree_Node *root)
{
    if(root->left_node != NULL)
        in_order(root->left_node);

    printf("%d ", root->root);

    if(root->right_node != NULL)
        in_order(root->right_node);
}

// Create Tree node
Tree_Node *create_tree_node(int item)
{
    Tree_Node *new_node = (Tree_Node *)malloc(sizeof(Tree_Node));

    if(new_node == NULL)
    {
        printf("Error! Could not create a new node.\n");
        exit(1);
    }

    new_node->root = item;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
}

// add left node
void add_left_node(Tree_Node *root, Tree_Node *child)
{
    root->left_node = child;
}

// add right node
void add_right_node(Tree_Node *root, Tree_Node *child)
{
    root->right_node = child;
}

// Create Tree;
Tree_Node *create_tree()
{
    Tree_Node *five = create_tree_node(5);
    Tree_Node *nine = create_tree_node(9);
    Tree_Node *three = create_tree_node(3);
    add_left_node(five, nine);
    add_right_node(five, three);

    Tree_Node *four = create_tree_node(4);
    Tree_Node *eight = create_tree_node(8);
    add_left_node(nine, four);
    add_right_node(nine, eight);

    Tree_Node *two = create_tree_node(2);
    Tree_Node *one = create_tree_node(1);
    add_left_node(four, two);
    add_right_node(four, one);

    Tree_Node *five_sec = create_tree_node(5);
    add_right_node(three, five_sec);

    Tree_Node *six = create_tree_node(6);
    Tree_Node *seven = create_tree_node(7);
    add_left_node(five_sec, six);
    add_right_node(five_sec, seven);

    return five;
}
