class Solution {
 public:
  vector<int> movesToStamp(string stamp, string target) {
    vector<int> ans;
    // stamped[i] := true if we already stamped target by stamping on index i
    vector<bool> stamped(target.length());
    int stampedCount = 0;  // Our goal is to make stampedCount = |target|.

    while (stampedCount < target.length()) {
      bool isStamped = false;
      // Try to stamp target[i..i + |stamp|) for each index.
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
      // After trying to stamp on each index, we can't find a valid stamp.
      if (!isStamped)
        return {};
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }

 private:
  // Stamps target[i..i + |stamp|) and returns the number of newly stamped
  // characters.
  // e.g. stampify("abc", "ababc", 2) returns 3 because target becomes "ab***".
  int stampify(const string& stamp, string& target, int s) {
    int stampified = stamp.length();

    for (int i = 0; i < stamp.length(); ++i)
      if (target[s + i] == '*')  // It's already been stamped.
        --stampified;
      else if (target[s + i] != stamp[i])
        return 0;  // We can't stamp on the index i.

    if (stampified > 0)
      fill(target.begin() + s, target.begin() + s + stamp.length(), '*');

    return stampified;
  }
};
