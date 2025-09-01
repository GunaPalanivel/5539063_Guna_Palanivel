struct node *lca( struct node *root, int v1, int v2 ) {
    if (root == NULL) {
        return NULL;
    }
    
    int smaller_val = (v1 < v2) ? v1 : v2;
    int bigger_val = (v1 > v2) ? v1 : v2;
    
    if (root->data < smaller_val) {
        return lca(root->right, v1, v2);
    }
    
    if (root->data > bigger_val) {
        return lca(root->left, v1, v2);
    }
    
    return root;
}
