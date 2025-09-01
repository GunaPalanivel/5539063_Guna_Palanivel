void noPrefix(int words_count, char** words) {
    struct TrieNode {
        struct TrieNode* kids[26];
        int word_ends_here;
    };
    
    struct TrieNode* make_node() {
        struct TrieNode* fresh_node = malloc(sizeof(struct TrieNode));
        fresh_node->word_ends_here = 0;
        for(int i = 0; i < 26; i++) {
            fresh_node->kids[i] = NULL;
        }
        return fresh_node;
    }
    
    struct TrieNode* root_node = make_node();
    
    for(int word_idx = 0; word_idx < words_count; word_idx++) {
        char* current_word = words[word_idx];
        struct TrieNode* crawler = root_node;
        int bad_situation = 0;
        
        int word_len = strlen(current_word);
        
        for(int char_pos = 0; char_pos < word_len; char_pos++) {
            int letter_num = current_word[char_pos] - 'a';
            
            if(crawler->kids[letter_num] == NULL) {
                crawler->kids[letter_num] = make_node();
            } else {
                if(crawler->kids[letter_num]->word_ends_here == 1) {
                    bad_situation = 1;
                    break;
                }
            }
            
            crawler = crawler->kids[letter_num];
        }
        
        if(bad_situation) {
            printf("BAD SET\n");
            printf("%s\n", current_word);
            return;
        }
        
        if(crawler->word_ends_here == 1) {
            printf("BAD SET\n");
            printf("%s\n", current_word);
            return;
        }
        
        for(int check_kids = 0; check_kids < 26; check_kids++) {
            if(crawler->kids[check_kids] != NULL) {
                printf("BAD SET\n");
                printf("%s\n", current_word);
                return;
            }
        }
        
        crawler->word_ends_here = 1;
    }
    
    printf("GOOD SET\n");
}
