class Solution {
 public:
  vector<int> secondGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size(), -1);
    // decreasing stack that stores indices that met the first greater num
    stack<int> prevStack;
    // decreasing stack that stores indices
    stack<int> currStack;

    for (int i = 0; i < nums.size(); ++i) {
      // Indices in `prevStack` meet the second greater num.
      while (!prevStack.empty() && nums[prevStack.top()] < nums[i])
        ans[prevStack.top()] = nums[i], prevStack.pop();
      // Push indices that meet the first greater num from `currStack` to
      // `prevStack`. We need a temp array to make indices in `prevStack`
      // increasing.
      stack<int> decreasingIndices;
      while (!currStack.empty() && nums[currStack.top()] < nums[i])
        decreasingIndices.push(currStack.top()), currStack.pop();
      while (!decreasingIndices.empty())
        prevStack.push(decreasingIndices.top()), decreasingIndices.pop();
      currStack.push(i);
    }

    return ans;
  }
};
