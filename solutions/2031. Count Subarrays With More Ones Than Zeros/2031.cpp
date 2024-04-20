class FenwickTree {
 public:
  FenwickTree(int n) : n(n), sums(2 * n + 1) {}

  void update(int i, int delta) {
    i += n + 1;  // re-mapping
    while (i < sums.size()) {
      sums[i] += delta;
      i += i & -i;
    }
  }

  int get(int i) {
    i += n + 1;  // re-mapping
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= i & -i;
    }
    return sum;
  }

 private:
  const int n;
  vector<int> sums;
};

class Solution {
 public:
  int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    int ans = 0;
    int prefix = 0;
    FenwickTree tree(nums.size());
    tree.update(0, 1);

    for (const int num : nums) {
      prefix += num == 0 ? -1 : 1;
      ans += tree.get(prefix - 1);
      ans %= kMod;
      tree.update(prefix, 1);
    }

    return ans;
  }
};
