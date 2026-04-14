#include <stdio.h> 
#include <stdlib.h> 
// Structure for BST Node [cite: 60] 
typedef struct TreeNode { 
int val; 
struct TreeNode* left; 
struct TreeNode* right; 
} TreeNode; 
// Function to create a new node [cite: 65] 
TreeNode* newNode(int val) { 
TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); 
node->val = val; 
node->left = node->right = NULL; 
return node; 
} 
// Function to insert nodes in BST [cite: 71] 
TreeNode* insert(TreeNode* root, int val) { 
if (root == NULL) return newNode(val); 
if (val < root->val) 
root->left = insert(root->left, val); 
else // Element greater than or equal to root go to the right [cite: 56] 
root->right = insert(root->right, val); 
return root; 
} 
// Function to find numbers in range [cite: 79] 
void rangeInBST(TreeNode* root, int low, int high) { 
if (root == NULL) return; 
if (root->val > low) 
rangeInBST(root->left, low, high); 
if (root->val >= low && root->val <= high) 
printf("%d ", root->val); // Printing elements in range [cite: 84] 
if (root->val < high) 
rangeInBST(root->right, low, high); 
} 
int main() { 
TreeNode* root = NULL; 
int n, val, low, high; 
// --- Riddhi's Details --- 
printf("Name: Riddhi Thorat\nPRN: 25070521246\nSec: E(E1)\n"); 
printf("---------------------------\n"); 
printf("Enter number of nodes in BST: "); 
scanf("%d", &n); 
printf("Enter %d node values:\n", n); 
for (int i = 0; i < n; i++) { 
scanf("%d", &val); 
root = insert(root, val); 
} 
printf("Enter range (low high): "); 
scanf("%d %d", &low, &high); 
printf("Nodes in range [%d, %d]: ", low, high); 
rangeInBST(root, low, high); 
printf("\n"); 
return 0; 
} 