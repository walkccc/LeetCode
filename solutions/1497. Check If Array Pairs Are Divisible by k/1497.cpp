class Solution {
 public:
  bool canArrange(vector<int>& arr, int k) {
    vector<int> bucket(k);

    for (const int a : arr) {
      int i = a % k;
      if (i < 0)
        i += k;
      ++bucket[i];
    }

    for (int i = 0; i < k; ++i)
      if (i == 0) {
        if (bucket[i] % 2 != 0)
          return false;
      } else if ((bucket[i] + bucket[k - i]) % 2 != 0) {
        return false;
      }

    return true;
  }
};
