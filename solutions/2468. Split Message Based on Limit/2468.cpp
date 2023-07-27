class Solution {
 public:
  vector<string> splitMessage(string message, int limit) {
    const int kMessageLength = message.length();
    int b = 1;
    // Total length of a. Initialized with the length of "1".
    int aLength = sz(1);

    // Total length of b := b * sz(b)
    // Total length of "</>" := b * 3
    while (b * limit < b * (sz(b) + 3) + aLength + kMessageLength) {
      // If the length the last suffix "<b/b>" := sz(b) * 2 + 3 >= limit,
      // then it's impossible that the length of "*<b/b>" <= limit.
      if (sz(b) * 2 + 3 >= limit)
        return {};
      aLength += sz(++b);
    }

    vector<string> ans;

    for (int i = 0, a = 1; a <= b; ++a) {
      // Length of "<a/b>" := sz(a) + sz(b) + 3
      const int j = limit - (sz(a) + sz(b) + 3);
      ans.push_back(message.substr(i, j) + "<" + to_string(a) + "/" +
                    to_string(b) + ">");
      i += j;
    }

    return ans;
  }

 private:
  int sz(int num) {
    return to_string(num).length();
  }
};
