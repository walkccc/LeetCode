class Solution {
 public:
  string digitSum(string s, int k) {
    while (s.length() > k) {
      string next;
      for (int i = 0; i < s.length(); ++i)
        next += to_string(accumulate(
            begin(s) + i, begin(s) + min(static_cast<int>(s.length()), i + k),
            0, [](int subtotal, char c) { return subtotal + c - '0'; }));
      s = move(next);
    }
    return s;
  }
};
