class Solution {
 public:
  int threeSumMulti(vector<int>& A, int target) {
    constexpr int kMod = 1'000'000'007;
    int ans = 0;
    unordered_map<int, long> count;

    for (const int a : A)
      ++count[a];

    for (const auto& [i, x] : count)
      for (const auto& [j, y] : count) {
        int k = target - i - j;
        if (!count.count(k))
          continue;
        if (i == j && j == k)
          ans = (ans + x * (x - 1) * (x - 2) / 6) % kMod;
        else if (i == j && j != k)
          ans = (ans + x * (x - 1) / 2 * count[k]) % kMod;
        else if (i < j && j < k)
          ans = (ans + x * y * count[k]) % kMod;
      }

    return ans;
  }
};
