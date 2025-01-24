class Solution {
 public:
  vector<int> secondGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size(), -1);
    // a decreasing stack that stores indices that met the first greater number
    stack<int> prevStack;
    // a decreasing stack that stores indices
    stack<int> currStack;

    for (int i = 0; i < nums.size(); ++i) {
      // Indices in `prevStack` meet the second greater number.
      while (!prevStack.empty() && nums[prevStack.top()] < nums[i])
        ans[prevStack.top()] = nums[i], prevStack.pop();
      // Push indices that meet the first greater number from `currStack` to
      // `prevStack`. We need a temporary array to make the indices in the
      // `prevStack` increasing.
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
