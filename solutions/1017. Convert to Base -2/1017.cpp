class Solution {
 public:
  string baseNeg2(int N) {
    string ans;

    while (N) {
      ans = to_string(N & 1) + ans;
      N = -(N >> 1);
    }

    return ans == "" ? "0" : ans;
  }
};
