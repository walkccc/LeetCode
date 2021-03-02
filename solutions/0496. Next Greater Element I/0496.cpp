class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> numToNextGreater;
    stack<int> stack;  // decreasing stack

    for (const int num : nums2) {
      while (!stack.empty() && stack.top() < num)
        numToNextGreater[stack.top()] = num, stack.pop();
      stack.push(num);
    }

    for (const int num : nums1)
      if (numToNextGreater.count(num))
        ans.push_back(numToNextGreater[num]);
      else
        ans.push_back(-1);

    return ans;
  }
};
