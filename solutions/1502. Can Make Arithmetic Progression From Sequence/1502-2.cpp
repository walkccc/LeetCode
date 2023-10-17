class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    const int n = arr.size();
    const int max = ranges::max(arr);
    const int min = ranges::min(arr);
    const int range = max - min;
    if (range % (n - 1) != 0)
      return false;
    const int diff = range / (n - 1);
    if (diff == 0)
      return true;

    for (int i = 0; i < n;) {
      const int gap = arr[i] - min;
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
