class Solution {
 public:
  int numberOfAlternatingGroups(vector<int>& colors) {
    const int n = colors.size();
    int ans = 0;

    for (int i = 0; i < n; ++i)
      if (colors[i] != colors[(i - 1 + n) % n] &&
          colors[i] != colors[(i + 1) % n])
        ++ans;

    return ans;
  }
};
