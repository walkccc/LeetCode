class Solution {
 public:
  int pairSum(ListNode* head) {
    int ans = 0;
    ListNode* slow = head;
    ListNode* fast = head;

    // `slow` points to the start of the second half.
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // `tail` points to the end of the reversed second half.
    ListNode* tail = reverseList(slow);

    while (tail != nullptr) {
      ans = max(ans, head->val + tail->val);
      head = head->next;
      tail = tail->next;
    }

    return ans;
  }

 private:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
      auto next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};
