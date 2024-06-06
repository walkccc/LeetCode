class Solution {
 public:
  long long smallestNumber(long long num) {
    string s = to_string(abs(num));
    ranges::sort(s, [&](int a, int b) { return num < 0 ? a > b : a < b; });
    if (num > 0)
      swap(s[0], s[s.find_first_not_of('0')]);
    return stoll(s) * (num < 0 ? -1 : 1);
  }
};
