class Solution {
 public:
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    const vector<int> maxDimension = *ranges::max_element(
        dimensions, [](const vector<int>& a, const vector<int>& b) {
      return (a[0] * a[0] + a[1] * a[1] == b[0] * b[0] + b[1] * b[1])
                 ? (a[0] * a[1] < b[0] * b[1])
                 : (a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]);
    });
    return maxDimension[0] * maxDimension[1];
  }
};
