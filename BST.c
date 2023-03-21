#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct tree
{
    int data;
    struct tree * left;
    struct tree * right;
};
typedef struct tree  TREE;

TREE * insert_into_bst(TREE * root, int d)
{
    TREE *newnode;
    newnode = (TREE *)malloc(sizeof(TREE));
    if(newnode == NULL)
    {
        printf("memory allocation failed\n");
        return root;
    }
    newnode->data = d;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL)
    {
        printf("Root created\n");
        //newnode = root;
        return newnode;
    }
    TREE * curr, *parent;
    curr = root;
    parent = NULL;

    while(curr!=NULL)
    {
        parent = curr;
        if((newnode->data) < (curr->data))
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(newnode->data < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    return root;

}

TREE * delete_from_bst(TREE * root, int d)
{
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return root;
    }

    TREE * curr, * parent, *p, *succ;
    curr = root;
    parent = NULL;

    while(curr!=NULL && curr->data!=d)
    {
        parent = curr;
        if(d < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(curr == NULL)
    {
        printf("Data unavailable\n");
        return root;
    }

    if(curr->left == NULL)
        p = curr->right;
    else if(curr->right == NULL)
        p = curr->left;
    else
    {
        succ = curr->right;
        while(succ->left!=NULL)
            succ = succ->left;
        succ->left = curr->left;
        p = curr->right;
    }

    if(parent == NULL)
    {
        free(curr);
        return p;
    }

    if(curr = parent->left)
        parent->left = p;
    else
        parent->right = p;

    free(curr);
    return root;
}

void inorder(TREE * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        //printf("%d ", root->data);
        inorder(root->right);
    }
}

/*void postorder(TREE * root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(TREE * root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);

        preorder(root->left);
        preorder(root->right);
    }
}*/

int count(TREE * root)
{
    if(root==NULL)
        return 0;
    int l= count(root->left);
    int r= count(root->right);
    return l+r+1;
}

void function_1(TREE * root)
{
    printf("In degree of root node: 0\n");
}

void function_2(TREE * root)
{
    printf("Out degree of root node: 2\n");
}

void function_4(TREE * root)
{

    int c= count(root);
    printf("Total number of edges: %d\n", c-1);


}

TREE * function_5(TREE * root, int key)
{
    if(root == NULL)
    {
        printf("Tree empty\n");
        return root;
    }
    else
    {
        if(root->data < key)
            delete_from_bst(root, root->data);
        else
            root = root->left;

    }
}

int function_6(TREE * root, int key)
{


    int count =0;

    while(root!=NULL)
    {

        if(key < root->data)
            count++;
        root = root->right;
    }
    printf("Total no of nodes greater than key: %d\n", count);


}

/*void function_7(TREE * root)
{

}*/
void function_8(TREE * root)
{
    int min;
    min = root->data;
    while(root!=NULL)
    {
        if(root->data < min)
            min = root->data;
        root = root->left;

    }
    printf("Minimum valued node is: %d\n", min);
}

void function_9(TREE * root)
{
    int count = 0;

    while(root!=NULL)
    {
        if(root->left == NULL && root->right == NULL)
            count++;
        root = root->left;
    }
    while(root!=NULL)
    {
        if(root->left == NULL && root->right == NULL)
            count++;
        root = root->right;
    }

    printf("Number of external node: %d\n", count+1);
}

void function_10(TREE * root)
{
    printf("Address of root node: %d\n", &root);
}

void function_11(TREE * root, int key)
{
    int count=0;
    while(root!=NULL && root->data!=key)
    {

        count++;
        root = root->left;
    }
    while(root!=NULL && root->data!=key)
    {

        count++;
        root = root->right;
    }
    printf("Number of comparisions made = %d\n", count);
}

TREE * function_13(TREE * root, int d)
{

}

void function_14(TREE * root)
{
    int count = 0;

    if(root!=NULL)
    {
        function_14(root->left);
        if(root->left == NULL && root->right == NULL)
            count++;
        function_14(root->right);
    }
    printf("Number of leaf node: %d\n", count);
}

void function_15(TREE * root)
{
    int count=0;
    if(root!=NULL)
    {
        function_15(root->left);
        count++;
        function_15(root->right);
    }

    int size;
    size = count*(sizeof(TREE));
    printf("Number of bytes allocated for the tree: %d\n", size);
}

void function_20(TREE * root)
{
    int max = root->data;
    if(root!=NULL)
    {
        inorder(root->left);
        if(root->data > max)
            max = root->data;
        function_20(root->right);

    }
    printf("Maximum valued node is: %d\n", max);
}

void function_22(TREE * root)
{
    int count_l =0, count_r=0;
    if(root!=NULL)
    {
        count_l++;
        function_22(root->left);

    }
    if(root!=NULL)
    {
        count_r++;
        function_22(root->right);
    }
    if(count_l>count_r)
        printf("Max comparisions: %d\n", count_l);
    else
        printf("Max comparision: %d\n", count_r);
}


int main()
{
    TREE * root=NULL;
    int ch;

    while(1)
    {
        printf("\n0- insert into tree\n1-function 1\n2- function 2\n3- function 3\n4- function 4\n5- function 5\n6- function 6\n7- function 7\n8- function 8\n9- function 9\n10- function 10\n11- function 11\n");
        printf("12- function 12\n13- function 13\n14- function 14\n15- function 15\n16- function 16\n 17- function 17\n 18- function 18\n19- function 19\n20- fucntion 20\n21- function 21\n 22- funciton 22");
        scanf("%d", &ch);
        switch(ch)
        {
            case 0: {
                        int data;
                        printf("Enter data to insert\n");
                        scanf("%d", &data);
                        root = insert_into_bst(root, data);
                        break;
                    }

            case 1: {
                        function_1(root);
                        break;
                    }

            case 2: {
                        function_2(root);
                        break;
                    }
            case 4: {function_4(root);
                    break;
            }



            case 5:  {int key;
                     printf("Enter key\n");
                     scanf("%d", &key);
                     root = function_5(root, key);
                     break;}

            case 6: {int k;
                    printf("Enter key\n");
                    scanf("%d", &k);
                    function_6(root, k);
                    printf("%d nodes have greater value than the key\n", count);
                    break;}
            case 8: function_8(root);
                     break;


            case 10: function_10(root);
                      break;
            case 11: {int key;
                     printf("Enter key\n");
                     scanf("%d", &key);
                     function_11(root, key);
                     break;}

            case 14: function_14(root);
                     break;
            case 15: function_15(root);
                     break;


            case 22: function_22(root);
                     break;


        }
    }
    return 0;
}
