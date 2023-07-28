class Solution {
 public:
  bool checkArray(vector<int>& nums, int k) {
    if (k == 1)
      return true;

    int needDecrease = 0;
    // Store nums[i - k + 1..i] with decreasing nums[i - k + 1].
    deque<int> q;

    for (int i = 0; i < nums.size(); ++i) {
      if (i >= k) {
        needDecrease -= q.front();
        q.pop_front();
      }
      if (nums[i] < needDecrease)
        return false;
      const int decreasedNum = nums[i] - needDecrease;
      q.push_back(decreasedNum);
      needDecrease += decreasedNum;
    }

    return q.back() == 0;
  }
};
