class Solution {
 public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    const int n = colors.size();
    int ans = 0;
    int alternating = 1;

    for (int i = 0; i < n + k - 2; ++i) {
      alternating =
          colors[i % n] == colors[(i - 1 + n) % n] ? 1 : alternating + 1;
      if (alternating >= k)
        ++ans;
    }

    return ans;
  }
};
