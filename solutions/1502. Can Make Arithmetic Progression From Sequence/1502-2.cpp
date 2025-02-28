class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    const int n = arr.size();
    const int mx = ranges::max(arr);
    const int mn = ranges::min(arr);
    const int range = mx - mn;
    if (range % (n - 1) != 0)
      return false;
    const int diff = range / (n - 1);
    if (diff == 0)
      return true;

    for (int i = 0; i < n;) {
      const int gap = arr[i] - mn;
      if (gap % diff != 0)
        return false;
      if (gap == i * diff) {
        ++i;
      } else {
        const int rightIndex = gap / diff;
        swap(arr[i], arr[rightIndex]);
      }
    }

    return true;
  }
};
