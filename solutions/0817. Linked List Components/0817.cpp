class Solution {
 public:
  int numComponents(ListNode* head, vector<int>& G) {
    int ans = 0;
    unordered_set<int> setG{begin(G), end(G)};

    for (; head; head = head->next)
      if (setG.count(head->val) &&
          (!head->next || !setG.count(head->next->val)))
        ++ans;

    return ans;
  }
};
