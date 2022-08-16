class Solution {
 public:
  int smallestRangeI(vector<int>& A, int K) {
    int max = *max_element(begin(A), end(A));
    int min = *min_element(begin(A), end(A));

    return std::max(0, max - min - 2 * K);
  }
};
