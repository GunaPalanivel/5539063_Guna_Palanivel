SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    SinglyLinkedListNode dummy;
    SinglyLinkedListNode* tail = &dummy;
    dummy.next = NULL;
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if (head1) tail->next = head1;
    else tail->next = head2;
    return dummy.next;
}
