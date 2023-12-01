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
  vector<int> processQueries(vector<int>& queries, int m) {
    vector<int> ans;
    // Map [-m, m] to [0, 2 * m].
    FenwickTree tree(2 * m + 1);
    unordered_map<int, int> numToIndex;

    for (int num = 1; num <= m; ++num) {
      numToIndex[num] = num + m;
      tree.update(num + m, 1);
    }

    int nextEmptyIndex = m;  // Map 0 to m.

    for (const int query : queries) {
      const int index = numToIndex[query];
      ans.push_back(tree.get(index - 1));
      // Move the `query` from the `index` to the `nextEmptyIndex`.
      tree.update(index, -1);
      tree.update(nextEmptyIndex, 1);
      numToIndex[query] = nextEmptyIndex--;
    }

    return ans;
  }
};
