class Solution {
 public:
  bool isTransformable(string s, string t) {
    if (getCount(s) != getCount(t))
      return false;

    vector<queue<int>> positions(10);

    for (int i = 0; i < s.length(); ++i)
      positions[s[i] - '0'].push(i);

    // For each digit in the `t`, check if we can put this digit in the `s` at
    // the same position as the `t`. Ensure that all the left digits are equal
    // to or greater than it. This is because the only operation we can perform
    // is sorting in ascending order. If there is a digit to the left that is
    // smaller than it, we can never move it to the same position as in the `t`.
    // However, if all the digits to its left are equal to or greater than it,
    // we can move it one position to the left until it reaches the same
    // position as in the `t`.
    for (const char c : t) {
      const int d = c - '0';
      const int front = positions[d].front();
      positions[d].pop();
      for (int smaller = 0; smaller < d; ++smaller)
        if (!positions[smaller].empty() && positions[smaller].front() < front)
          return false;
    }
    return true;
  }

 private:
  vector<int> getCount(const string& s) {
    vector<int> count(10);
    for (const char c : s)
      ++count[c - '0'];
    return count;
  }
};
