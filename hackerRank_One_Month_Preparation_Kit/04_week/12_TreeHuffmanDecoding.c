struct node {
    int freq;
    char data;
    struct node* left;
    struct node* right;
};

void decode_huff(struct node* root, char* s) {
    struct node* current_spot = root;
    int str_len = strlen(s);
    
    for (int pos = 0; pos < str_len; pos++) {
        char bit = s[pos];
        
        if (bit == '0') {
            current_spot = current_spot->left;
        } else {
            current_spot = current_spot->right;
        }
        
        if (current_spot->left == NULL && current_spot->right == NULL) {
            printf("%c", current_spot->data);
            current_spot = root;
        }
    }
}

int main() {
    return 0;
}