SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* before = NULL;
    SinglyLinkedListNode* now = llist;
    while (now) {
        SinglyLinkedListNode* after = now->next;
        now->next = before;
        before = now;
        now = after;
    }
    return before;
}
