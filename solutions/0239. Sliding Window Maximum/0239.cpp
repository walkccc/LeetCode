class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> q;  // max queue

    for (int i = 0; i < nums.size(); ++i) {
      while (!q.empty() && q.back() < nums[i])
        q.pop_back();
      q.push_back(nums[i]);
      if (i >= k && nums[i - k] == q.front())  // out of bound
        q.pop_front();
      if (i >= k - 1)
        ans.push_back(q.front());
    }

    return ans;
  }
};
