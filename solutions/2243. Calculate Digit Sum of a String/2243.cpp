class Solution {
 public:
  string digitSum(string s, int k) {
    while (s.length() > k) {
      string next;
      for (int i = 0; i < s.length(); ++i)
        next += to_string(accumulate(
            s.begin() + i, s.begin() + min(static_cast<int>(s.length()), i + k),
            0, [](int subtotal, char c) { return subtotal + c - '0'; }));
      s = std::move(next);
    }
    return s;
  }
};
