class Solution {
 public:
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ans;
    stack<int> stack;

    for (; head; head = head->next) {
      while (!stack.empty() && head->val > ans[stack.top()]) {
        int index = stack.top();
        stack.pop();
        ans[index] = head->val;
      }
      stack.push(ans.size());
      ans.push_back(head->val);
    }

    for (; !stack.empty(); stack.pop())
      ans[stack.top()] = 0;

    return ans;
  }
};
