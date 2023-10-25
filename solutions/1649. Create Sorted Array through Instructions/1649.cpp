class FenwickTree {
 public:
  FenwickTree(int n) : sums(n + 1) {}

  void update(int i, int delta) {
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
  int createSortedArray(vector<int>& instructions) {
    constexpr int kMod = 1'000'000'007;
    const int max = ranges::max(instructions);
    int ans = 0;
    FenwickTree tree(max);

    for (int i = 0; i < instructions.size(); ++i) {
      ans += min(tree.get(instructions[i] - 1), i - tree.get(instructions[i]));
      ans %= kMod;
      tree.update(instructions[i], 1);
    }

    return ans;
  }
};
