class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int j = -1;                     // s[j + 1..i] has no repeating chars.
    vector<int> lastSeen(128, -1);  // lastSeen[c] := index of last c appeared.

    for (int i = 0; i < s.length(); ++i) {
      // Update j to lastSeen[c], so the window must start from j + 1.
      j = max(j, lastSeen[s[i]]);
      ans = max(ans, i - j);
      lastSeen[s[i]] = i;
    }

    return ans;
  }
};
