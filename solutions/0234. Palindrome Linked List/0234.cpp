class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    if (fast)
      slow = slow->next;
    slow = reverseList(slow);

    while (slow) {
      if (slow->val != head->val)
        return false;
      slow = slow->next;
      head = head->next;
    }

    return true;
  }

 private:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;

    while (head) {
      ListNode* next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }

    return prev;
  }
};
