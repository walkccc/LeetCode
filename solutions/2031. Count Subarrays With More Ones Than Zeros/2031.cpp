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
  int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    int ans = 0;
    int prefix = 0;
    // Map [-n, n] to [1, 2 * n + 1].
    FenwickTree tree(2 * n + 1);
    tree.add(remap(0, n), 1);

    for (const int num : nums) {
      prefix += num == 0 ? -1 : 1;
      // If prefix[j] > prefix[i], where 0 <= i < j < |prefix|, that means that
      // there are more ones than zeros in nums[i + 1, j].
      ans += tree.get(remap(prefix - 1, n));
      ans %= kMod;
      tree.add(remap(prefix, n), 1);
    }

    return ans;
  }

 private:
  int remap(int i, int n) {
    return i + n + 1;
  }
};
