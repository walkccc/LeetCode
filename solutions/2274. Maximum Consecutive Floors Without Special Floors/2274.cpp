class Solution {
 public:
  int maxConsecutive(int bottom, int top, vector<int>& special) {
    int ans = 0;

    ranges::sort(special);

    for (int i = 1; i < special.size(); ++i)
      ans = max(ans, special[i] - special[i - 1] - 1);

    return max({ans, special.front() - bottom, top - special.back()});
  }
};
