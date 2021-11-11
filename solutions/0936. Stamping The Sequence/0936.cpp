class Solution {
 public:
  vector<int> movesToStamp(string stamp, string target) {
    vector<int> ans;
    // stamped[i] := true if we already stamped target by stamp on index i
    vector<bool> stamped(target.length());
    int stampedCount = 0;  // out goal is to make stampedCount = target.length()

    while (stampedCount < target.length()) {
      bool isStamped = false;
      // try to stamp target[i..i + stamp.length()) for each index
      for (int i = 0; i <= target.length() - stamp.length(); ++i) {
        if (stamped[i])
          continue;
        const int stampified = stampify(stamp, target, i);
        if (stampified == 0)
          continue;
        stampedCount += stampified;
        isStamped = true;
        stamped[i] = true;
        ans.push_back(i);
      }
      // after trying stamp each index, we can't find a valid stamp
      if (!isStamped)
        return {};
    }

    reverse(begin(ans), end(ans));
    return ans;
  }

 private:
  // stamp target[i..i + stamp.length()) and return # of newly stamped chars
  // e.g. stampify("abc", "ababc", 2) returns 3 because target becomes "ab***"
  int stampify(const string& stamp, string& target, int s) {
    int stampified = stamp.length();

    for (int i = 0; i < stamp.length(); ++i)
      if (target[s + i] == '*')  // already stamped
        --stampified;
      else if (target[s + i] != stamp[i])
        return 0;  // we can't stamp on index i

    if (stampified > 0)
      fill(begin(target) + s, begin(target) + s + stamp.length(), '*');

    return stampified;
  }
};
