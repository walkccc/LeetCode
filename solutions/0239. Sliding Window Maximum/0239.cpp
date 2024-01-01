class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> maxQ;

    for (int i = 0; i < nums.size(); ++i) {
      while (!maxQ.empty() && maxQ.back() < nums[i])
        maxQ.pop_back();
      maxQ.push_back(nums[i]);
      if (i >= k && nums[i - k] == maxQ.front())  // out-of-bounds
        maxQ.pop_front();
      if (i >= k - 1)
        ans.push_back(maxQ.front());
    }

    return ans;
  }
};
