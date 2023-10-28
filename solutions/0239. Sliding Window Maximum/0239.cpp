class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;  // max queue

    for (int i = 0; i < nums.size(); ++i) {
      while (!dq.empty() && dq.back() < nums[i])
        dq.pop_back();
      dq.push_back(nums[i]);
      if (i >= k && nums[i - k] == dq.front())  // out of bound
        dq.pop_front();
      if (i >= k - 1)
        ans.push_back(dq.front());
    }

    return ans;
  }
};
