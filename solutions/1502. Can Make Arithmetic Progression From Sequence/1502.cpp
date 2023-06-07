class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    const int n = arr.size();
    const int max = *max_element(begin(arr), end(arr));
    const int min = *min_element(begin(arr), end(arr));
    const int range = max - min;
    if (range % (n - 1) != 0)
      return false;
    const int diff = range / (n - 1);
    if (diff == 0)
      return true;

    unordered_set<int> seen;

    for (const int a : arr) {
      if ((a - min) % diff != 0)
        return false;
      if (!seen.insert(a).second)
        return false;
    }

    return true;
  }
};
