class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    const int maxLeft = left.empty() ? 0 : ranges::max(left);
    const int minRight = right.empty() ? n : ranges::min(right);
    return max(maxLeft, n - minRight);
  }
};
