class Solution {
 public:
  bool containsPattern(vector<int>& arr, int m, int k) {
    int count = 0;
    for (int i = m; i < arr.size(); ++i) {
      count = arr[i] == arr[i - m] ? count + 1 : 0;
      if (count == m * k - m)
        return true;
    }
    return false;
  }
};
