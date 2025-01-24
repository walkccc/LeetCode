class Solution {
 public:
  int countPairs(vector<int>& deliciousness) {
    constexpr int kMod = 1'000'000'007;
    constexpr int kMaxBit = 20 + 1;
    const int kMaxPower = pow(2, kMaxBit);
    int ans = 0;
    unordered_map<int, int> count;

    for (const int d : deliciousness) {
      for (int power = 1; power <= kMaxPower; power *= 2)
        if (const auto it = count.find(power - d); it != count.cend()) {
          ans += it->second;
          ans %= kMod;
        }
      ++count[d];
    }

    return ans;
  }
};
