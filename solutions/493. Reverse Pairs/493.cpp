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
  int reversePairs(vector<int>& nums) {
    int ans = 0;
    const unordered_map<long, int> ranks = getRanks(nums);
    FenwickTree tree(ranks.size());

    for (int i = nums.size() - 1; i >= 0; --i) {
      const long num = nums[i];
      ans += tree.get(ranks.at(num) - 1);
      tree.add(ranks.at(num * 2), 1);
    }

    return ans;
  }

 private:
  unordered_map<long, int> getRanks(const vector<int>& nums) {
    unordered_map<long, int> ranks;
    set<long> sorted(nums.begin(), nums.end());
    for (const long num : nums)
      sorted.insert(num * 2);
    int rank = 0;
    for (const long num : sorted)
      ranks[num] = ++rank;
    return ranks;
  }
};
