class Solution {
 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least
     one node. */
  Solution(ListNode* head) : head(head) {}

  /** Returns a random node's value. */
  int getRandom() {
    int res = -1;
    int i = 1;

    for (ListNode* curr = head; curr; curr = curr->next, ++i)
      if (rand() % i == 0)
        res = curr->val;

    return res;
  }

 private:
  ListNode* head;
};
