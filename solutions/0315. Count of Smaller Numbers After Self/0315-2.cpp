class FenwickTree {
 public:
  FenwickTree(int n) : sums(n + 1) {}

  void update(int i, int delta) {
    while (i < sums.size()) {
      sums[i] += delta;
      i += i & -i;
    }
  }

  int get(int i) {
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= i & -i;
    }
    return sum;
  }

 private:
  vector<int> sums;
};

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> ans;
    set<int> sorted(begin(nums), end(nums));
    FenwickTree tree(sorted.size());
    unordered_map<int, int> ranks;  // {num: rank}

    int rank = 0;
    for (const int num : sorted)
      ranks[num] = ++rank;

    reverse(begin(nums), end(nums));

    for (const int num : nums) {
      ans.push_back(tree.get(ranks[num] - 1));
      tree.update(ranks[num], 1);
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};
