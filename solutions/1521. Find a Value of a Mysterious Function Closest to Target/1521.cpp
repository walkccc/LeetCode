class Solution {
 public:
  int closestToTarget(vector<int>& arr, int target) {
    int ans = INT_MAX;
    // s(j) := arr[i] & arr[i + 1] & ... & arr[j] for all 0 <= i <= j (fixed)
    unordered_set<int> s;

    for (const int a : arr) {
      unordered_set<int> s2{a};
      for (const int b : s)
        s2.insert(a & b);
      for (const int c : s = s2)
        ans = min(ans, abs(c - target));
    }

    return ans;
  }
};

