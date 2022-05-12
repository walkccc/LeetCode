class Solution {
 public:
  int minIncrementForUnique(vector<int>& A) {
    int ans = 0;
    int minAvailable = 0;

    sort(begin(A), end(A));

    for (int a : A) {
      ans += max(minAvailable - a, 0);
      minAvailable = max(minAvailable, a) + 1;
    }

    return ans;
  }
};
