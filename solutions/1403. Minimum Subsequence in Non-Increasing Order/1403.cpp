class Solution {
 public:
  vector<int> minSubsequence(vector<int>& nums) {
    vector<int> ans;
    priority_queue<int> maxHeap(nums.begin(), nums.end());
    int half = accumulate(nums.begin(), nums.end(), 0) / 2;

    while (half >= 0) {
      ans.push_back(maxHeap.top());
      half -= maxHeap.top(), maxHeap.pop();
    }

    return ans;
  }
};
