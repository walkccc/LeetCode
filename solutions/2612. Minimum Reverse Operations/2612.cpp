class Solution {
 public:
  vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
    const unordered_set<int> bannedSet{banned.begin(), banned.end()};
    vector<int> ans(n, -1);
    // unseen[i] := the unseen numbers that % 2 == i
    vector<set<int>> unseen(2);

    for (int num = 0; num < n; ++num)
      if (num != p && !bannedSet.count(num))
        unseen[num & 1].insert(num);

    // Perform BFS from `p`.
    queue<int> q{{p}};
    ans[p] = 0;

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      const int lo = max(u - k + 1, k - 1 - u);
      const int hi = min(u + k - 1, n - 1 - (u - (n - k)));
      // Choose the correct set of numbers.
      set<int>& nums = unseen[lo & 1];
      for (auto it = nums.lower_bound(lo); it != nums.end() && *it <= hi;) {
        ans[*it] = ans[u] + 1;
        q.push(*it);
        it = nums.erase(it);
      }
    }

    return ans;
  }
};
