class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    // The substring s[j + 1..i] has no repeating characters.
    int j = -1;
    // lastSeen[c] := the index of the last time c appeared
    vector<int> lastSeen(128, -1);

    for (int i = 0; i < s.length(); ++i) {
      // Update j to lastSeen[s[i]], so the window must start from j + 1.
      j = max(j, lastSeen[s[i]]);
      ans = max(ans, i - j);
      lastSeen[s[i]] = i;
    }

    return ans;
  }
};
