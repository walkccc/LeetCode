class Solution {
 public:
  bool canArrange(vector<int>& arr, int k) {
    vector<int> count(k);

    for (int a : arr) {
      a %= k;
      ++count[a < 0 ? a + k : a];
    }

    if (count[0] % 2 != 0)
      return false;

    for (int i = 1; i <= k / 2; ++i)
      if (count[i] != count[k - i])
        return false;

    return true;
  }
};
