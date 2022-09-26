class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    const int maxLeft = left.empty() ? 0 : *max_element(begin(left), end(left));
    const int minRight = right.empty() ? n : *min_element(begin(right), end(right));
    return max(maxLeft, n - minRight);
  }
};
