class Solution {
 public:
  int numComponents(ListNode* head, vector<int>& nums) {
    int ans = 0;
    unordered_set<int> setNums{nums.begin(), nums.end()};

    for (; head; head = head->next)
      if (setNums.contains(head->val) &&
          (!head->next || !setNums.contains(head->next->val)))
        ++ans;

    return ans;
  }
};
