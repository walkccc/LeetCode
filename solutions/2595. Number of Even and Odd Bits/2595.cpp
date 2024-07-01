class Solution {
 public:
  vector<int> evenOddBit(int n) {
    vector<int> ans(2);
    int i = 0;  // 0 := even, 1 := odd

    while (n > 0) {
      ans[i] += n & 1;
      n >>= 1;
      i ^= 1;
    }

    return ans;
  }
};
