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
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> ans(nums.size());
    unordered_map<int, int> ranks;
    getRanks(nums, ranks);
    FenwickTree tree(ranks.size());

    for (int i = nums.size() - 1; i >= 0; --i) {
      const int num = nums[i];
      ans[i] = tree.get(ranks[num] - 1);
      tree.update(ranks[num], 1);
    }

    return ans;
  }

 private:
  void getRanks(const vector<int>& nums, unordered_map<int, int>& ranks) {
    set<int> sorted(nums.begin(), nums.end());
    int rank = 0;
    for (const int num : sorted)
      ranks[num] = ++rank;
  }
};
