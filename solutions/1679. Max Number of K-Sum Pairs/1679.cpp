class Solution {
 public:
  int maxOperations(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    for (const auto& [num, freq] : count)
      if (const auto it = count.find(k - num); it != count.end())
        ans += min(freq, it->second);

    return ans / 2;
  }
};
