SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* fresh = malloc(sizeof(SinglyLinkedListNode));
    fresh->data = data;
    fresh->next = NULL;
    if (position == 0) {
        fresh->next = llist;
        return fresh;
    }
    SinglyLinkedListNode* walk = llist;
    int idx = 0;
    while (walk && idx < position - 1) {
        walk = walk->next;
        idx++;
    }
    if (walk) {
        fresh->next = walk->next;
        walk->next = fresh;
    }
    return llist;
}