class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode beforeHead(0);
    ListNode afterHead(0);
    ListNode* before = &beforeHead;
    ListNode* after = &afterHead;

    for (; head; head = head->next)
      if (head->val < x) {
        before->next = head;
        before = head;
      } else {
        after->next = head;
        after = head;
      }

    after->next = nullptr;
    before->next = afterHead.next;

    return beforeHead.next;
  };
};
