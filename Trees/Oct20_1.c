#include<stdio.h>
#include<stdlib.h>

/* A Binary Tree node */
struct TNode
{
	int data;
	struct TNode* left;
	struct TNode* right;
};

struct TNode* newNode(int data);

/* A function to constructs Balanced Binary Search Tree from a sorted array */
struct TNode* sortedArrayToBST(int arr[], int p, int q)
{
	if (p > q) return NULL;
	int mid = (p + q)/2;
	struct TNode *head = newNode(arr[mid]);
	head->left = sortedArrayToBST(arr, p, mid-1);
	head->right = sortedArrayToBST(arr, mid+1, q);
	return head;
}
struct TNode* newNode(int data)
{
	struct TNode* node = (struct TNode*)
						malloc(sizeof(struct TNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* Function to print preorder traversal of BST */
void preOrder(struct TNode* node)
{
	if (node == NULL) return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

/* Driver program */
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	/* Convert List to BST */
	struct TNode *root = sortedArrayToBST(arr, 0, n-1);
	printf("n PreOrder Traversal of constructed BST ");
	preOrder(root);

	return 0;
}
