class Solution {
 public:
  vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> count(26);
    // counts[i] := the count of s[0..i)
    vector<vector<int>> counts = {count};

    for (const char c : s) {
      ++count[c - 'a'];
      counts.push_back(count);
    }

    for (const vector<int>& query : queries) {
      const int l = query[0];
      const int r = query[1];
      int sameEndCount = 0;
      for (char c = 'a'; c <= 'z'; ++c) {
        //   the count of s[0..r + 1) - the count of s[0..l)
        // = the count of s[l..r]
        const int freq = counts[r + 1][c - 'a'] - counts[l][c - 'a'];
        //   C(freq, 2) + freq
        // = freq * (freq - 1) / 2 + freq
        // = freq * (freq + 1) / 2
        sameEndCount += freq * (freq + 1) / 2;
      }
      ans.push_back(sameEndCount);
    }

    return ans;
  }
};
