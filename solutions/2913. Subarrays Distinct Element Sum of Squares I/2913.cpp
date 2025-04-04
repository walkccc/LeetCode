class SegmentTree {
 public:
  SegmentTree(int n, int kMod)
      : n(n), kMod(kMod), lazy(4 * n), sums(4 * n), squaredSums(4 * n) {}

  void updateRange(int l, int r) {
    return updateRange(/*i=*/0, /*start=*/0, /*end=*/n - 1, l, r);
  }

  void propagate(int i, int l, int r) {
    const int gap = r - l + 1;
    // (a + L)^2 + (b + L)^2 + (c + L)^2, where L = lazy[i]
    // a^2 + b^2 + c^2 + 2 * L (a + b + c) + L^2 * gap, where gap = 3
    squaredSums[i] += 2 * lazy[i] * sums[i] + lazy[i] * lazy[i] * gap;
    squaredSums[i] %= kMod;
    sums[i] += lazy[i] * gap;
    sums[i] %= kMod;
    if (l < r) {
      lazy[i * 2 + 1] += lazy[i];
      lazy[i * 2 + 2] += lazy[i];
    }
    lazy[i] = 0;
  }

  int getTreeSquaredSums() {
    return squaredSums[0];
  }

 private:
  const int kMod;
  const int n;
  vector<long> lazy;
  vector<long> sums;
  vector<long> squaredSums;

  void updateRange(int i, int start, int end, int l, int r) {
    if (lazy[i] > 0)
      propagate(i, start, end);
    if (end < l || start > r)
      return;
    if (start >= l && end <= r) {
      lazy[i] = 1;
      propagate(i, start, end);
      return;
    }
    const int mid = (start + end) / 2;
    updateRange(i * 2 + 1, start, mid, l, r);
    updateRange(i * 2 + 2, mid + 1, end, l, r);
    sums[i] = (sums[i * 2 + 1] + sums[i * 2 + 2]) % kMod;
    squaredSums[i] = (squaredSums[i * 2 + 1] + squaredSums[i * 2 + 2]) % kMod;
  }
};

class Solution {
 public:
  int sumCounts(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    int ans = 0;
    unordered_map<int, int> lastSeen;
    SegmentTree tree(n, kMod);

    for (int r = 0; r < n; ++r) {
      const int l = lastSeen.contains(nums[r]) ? lastSeen[nums[r]] + 1 : 0;
      tree.updateRange(l, r);
      lastSeen[nums[r]] = r;
      ans = (ans + tree.getTreeSquaredSums()) % kMod;
    }

    return ans;
  }
};
