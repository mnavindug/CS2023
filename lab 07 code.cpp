#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    
  if (root != NULL) {
      
    traverseInOrder(root->left); 
    cout << root->key << " "; 
    traverseInOrder(root->right); 
    
  }
  
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    
  if (node == NULL) {
  
    node = new struct node;
    node->key = key;
    node->left = node->right = NULL;
    
  }
  else if (key < node->key) { 
      
    node->left = insertNode(node->left, key);
    
  }
  else if (key > node->key) {
      
    node->right = insertNode(node->right, key);
  }
  
  return node;
}

// Defining a function to find the minimum key 
struct node *find_minimum(struct node *node) {
  if (node == NULL) { 
      
    return NULL;
    
  }
  else if (node->left == NULL) { 
      
    return node;
    
  }
  else { 
      
    return find_minimum(node->left);
    
  }
  
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) { 
    return NULL;
  }
  else if (key < root->key) { 
      
    root->left = deleteNode(root->left, key);
    
  }
  else if (key > root->key) { 
      
    root->right = deleteNode(root->right, key);
    
  }
  else { 
      
    if (root->left == NULL && root->right == NULL) { 
        
      delete root;
      root = NULL; 
      
    }
    else if (root->left == NULL) { 
        
      struct node *newnode = root; 
      root = root->right; 
      delete newnode; 
      
    }
    else if (root->right == NULL) { 
        
      struct node *newnode = root; 
      root = root->left;
      delete newnode; 
      
    }
    else { 
      struct node *newnode = find_minimum(root->right); 
      root->key = newnode->key;
      root->right = deleteNode(root->right, newnode->key); 
      
    }
    
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
