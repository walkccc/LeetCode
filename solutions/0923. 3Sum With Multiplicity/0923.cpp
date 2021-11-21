class Solution {
 public:
  int threeSumMulti(vector<int>& A, int target) {
    const int kMod = 1e9 + 7;

    long ans = 0;

    unordered_map<int, long> count;
    for (int a : A)
      ++count[a];

    for (const auto& [i, x] : count)
      for (const auto& [j, y] : count) {
        int k = target - i - j;
        if (!count.count(k))
          continue;
        if (i == j && j == k)
          ans += x * (x - 1) * (x - 2) / 6;
        else if (i == j && j != k)
          ans += x * (x - 1) / 2 * count[k];
        else if (i < j && j < k)
          ans += x * y * count[k];
      }

    return ans % kMod;
  }
};
