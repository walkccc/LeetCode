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
  string minInteger(string num, int k) {
    const int n = num.length();
    string ans;
    FenwickTree tree(n);
    vector<bool> used(n);
    vector<queue<int>> numToIndices(10);

    for (int i = 0; i < n; ++i)
      numToIndices[num[i] - '0'].push(i);

    while (k > 0 && ans.length() < n)
      for (int d = 0; d < 10; ++d) {
        if (numToIndices[d].empty())
          continue;
        const int i = numToIndices[d].front();
        const int cost = i - tree.get(i);  // Note the offset 1 in FenwickTree.
        if (cost > k)
          continue;
        k -= cost;
        ans += '0' + d;
        used[i] = true;
        tree.update(i + 1, 1);
        numToIndices[d].pop();
        break;  // Scan from 0 -> 9 again.
      }

    for (int i = 0; i < n; ++i)
      if (!used[i])
        ans += num[i];

    return ans;
  }
};
