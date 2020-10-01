class Solution {
 public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    map<int, int> count;
    for (int num : nums) ++count[num];

    for (const auto& [key, _] : count) {
      int value = count[key];
      if (value > 0)
        for (int i = key; i < key + k; ++i) {
          count[i] -= value;
          if (count[i] < 0) return false;
        }
    }

    return true;
  }
};