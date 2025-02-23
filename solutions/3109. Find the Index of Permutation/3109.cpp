class FenwickTree {
 public:
  FenwickTree(int n) : sums(n + 1) {}

  void add(int i, int delta) {
    while (i < sums.size()) {
      sums[i] += delta;
      i += lowbit(i);
    }
  }

  int get(int i) const {
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= lowbit(i);
    }
    return sum;
  }

 private:
  vector<int> sums;

  static inline int lowbit(int i) {
    return i & -i;
  }
};

class Solution {
 public:
  int getPermutationIndex(vector<int>& perm) {
    constexpr int kMod = 1'000'000'007;
    const int n = perm.size();
    int ans = 0;
    FenwickTree tree(n);
    vector<int> fact(n + 1, 1);  // fact[i] := i!

    for (int i = 2; i <= n; ++i)
      fact[i] = (fact[i - 1] * static_cast<long>(i)) % kMod;

    for (int i = 0; i < n; ++i) {
      const int num = perm[i];
      // the number of unused numbers less than `num`
      const int unusedNums = num - 1 - tree.get(num - 1);
      const int suffixLength = fact[n - 1 - i];
      ans = (ans + unusedNums * static_cast<long>(suffixLength)) % kMod;
      tree.add(num, 1);
    }

    return ans;
  }
};
