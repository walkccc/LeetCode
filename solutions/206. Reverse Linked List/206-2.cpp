class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;

    while (head != nullptr) {
      ListNode* next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }

    return prev;
  }
};
