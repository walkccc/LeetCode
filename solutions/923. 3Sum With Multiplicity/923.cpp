class Solution {
 public:
  int threeSumMulti(vector<int>& arr, int target) {
    constexpr int kMod = 1'000'000'007;
    int ans = 0;
    unordered_map<int, int> count;

    for (const int a : arr)
      ++count[a];

    for (const auto& [i, x] : count)
      for (const auto& [j, y] : count) {
        const int k = target - i - j;
        const auto it = count.find(k);
        if (it == count.cend())
          continue;
        if (i == j && j == k)
          ans = (ans + static_cast<long>(x) * (x - 1) * (x - 2) / 6) % kMod;
        else if (i == j && j != k)
          ans = (ans + static_cast<long>(x) * (x - 1) / 2 * it->second) % kMod;
        else if (i < j && j < k)
          ans = (ans + static_cast<long>(x) * y * it->second) % kMod;
      }

    return ans;
  }
};
