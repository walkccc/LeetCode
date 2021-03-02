class Solution {
 public:
  int totalFruit(vector<int>& tree) {
    int ans = 0;
    unordered_map<int, int> count;

    for (int l = 0, r = 0; r < tree.size(); ++r) {
      ++count[tree[r]];
      while (count.size() > 2) {
        if (--count[tree[l]] == 0)
          count.erase(tree[l]);
        ++l;
      }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
