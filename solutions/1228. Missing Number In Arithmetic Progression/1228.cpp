class Solution {
 public:
  int missingNumber(vector<int>& arr) {
    const int n = arr.size();
    const int delta = (arr.back() - arr.front()) / n;
    int l = 0;
    int r = n - 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (arr[m] == arr[0] + m * delta)
        l = m + 1;
      else
        r = m;
    }

    return arr[0] + l * delta;
  }
};
