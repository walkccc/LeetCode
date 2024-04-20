class Solution {
 public:
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    vector<ListNode*> ans(k);
    const int length = getLength(root);
    const int subLength = length / k;
    int remainder = length % k;

    ListNode* prev = nullptr;
    ListNode* head = root;

    for (int i = 0; i < k; ++i, --remainder) {
      ans[i] = head;
      for (int j = 0; j < subLength + (remainder > 0); ++j) {
        prev = head;
        head = head->next;
      }
      if (prev != nullptr)
        prev->next = nullptr;
    }

    return ans;
  }

 private:
  int getLength(ListNode* root) {
    int length = 0;
    for (ListNode* curr = root; curr; curr = curr->next)
      ++length;
    return length;
  }
};
