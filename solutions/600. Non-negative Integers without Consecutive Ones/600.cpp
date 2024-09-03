class Solution {
 public:
  int findIntegers(int num) {
    string bits;
    for (; num; num >>= 1)
      bits += to_string(num & 1);

    const int n = bits.length();
    vector<int> zero(n, 1);
    vector<int> one(n, 1);

    for (int i = 1; i < n; ++i) {
      zero[i] = zero[i - 1] + one[i - 1];
      one[i] = zero[i - 1];
    }

    int ans = zero[n - 1] + one[n - 1];

    for (int i = n - 2; i >= 0; --i) {
      // The numbers > num and <= 2^n - 1 are invalid.
      if (bits[i] == '1' && bits[i + 1] == '1')
        break;
      if (bits[i] == '0' && bits[i + 1] == '0')
        ans -= one[i];
    }

    return ans;
  }
};
