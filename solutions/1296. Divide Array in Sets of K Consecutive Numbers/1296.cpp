class Solution {
 public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    map<int, int> count;

    for (const int num : nums)
      ++count[num];

    for (const auto& [start, _] : count) {
      const int value = count[start];
      if (value > 0)
        for (int i = start; i < start + k; ++i) {
          count[i] -= value;
          if (count[i] < 0)
            return false;
        }
    }

    return true;
  }
};
