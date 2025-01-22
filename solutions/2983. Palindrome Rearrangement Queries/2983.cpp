class Solution {
 public:
  vector<bool> canMakePalindromeQueries(string s,
                                        vector<vector<int>>& queries) {
    const int n = s.length();
    // mirroredDiffs[i] := the number of different letters between the first i
    // letters of s[0..n / 2) and the first i letters of s[n / 2..n)[::-1]
    const vector<int> mirroredDiffs = getMirroredDiffs(s);
    // counts[i] := the count of s[0..i)
    const vector<vector<int>> counts = getCounts(s);
    vector<bool> ans;

    for (const vector<int>& query : queries) {
      // Use left-closed, right-open intervals to facilitate the calculation.
      //   ...... [a, b) ...|... [rb, ra) ......
      //   .... [rd, rc) .....|..... [c, d) ....
      const int a = query[0];
      const int b = query[1] + 1;
      const int c = query[2];
      const int d = query[3] + 1;
      const int ra = n - a;  // the reflected index of a in s[n / 2..n)
      const int rb = n - b;  // the reflected index of b in s[n / 2..n)
      const int rc = n - c;  // the reflected index of c in s[n / 2..n)
      const int rd = n - d;  // the reflected index of d in s[n / 2..n)
      // No difference is allowed outside the query ranges.
      if (min(a, rd) > 0 && mirroredDiffs[min(a, rd)] > 0 ||
          n / 2 > max(b, rc) &&
              mirroredDiffs[n / 2] - mirroredDiffs[max(b, rc)] > 0 ||
          rd > b && mirroredDiffs[rd] - mirroredDiffs[b] > 0 ||
          a > rc && mirroredDiffs[a] - mirroredDiffs[rc] > 0) {
        ans.push_back(false);
      } else {
        // The `count` map of the intersection of [a, b) and [rd, rc) in
        // s[0..n / 2) must equate to the `count` map of the intersection of
        // [c, d) and [rb, ra) in s[n / 2..n).
        vector<int> leftRangeCount = subtractArrays(counts[b], counts[a]);
        vector<int> rightRangeCount = subtractArrays(counts[d], counts[c]);
        if (a > rd)
          rightRangeCount = subtractArrays(
              rightRangeCount, subtractArrays(counts[min(a, rc)], counts[rd]));
        if (rc > b)
          rightRangeCount = subtractArrays(
              rightRangeCount, subtractArrays(counts[rc], counts[max(b, rd)]));
        if (c > rb)
          leftRangeCount = subtractArrays(
              leftRangeCount, subtractArrays(counts[min(c, ra)], counts[rb]));
        if (ra > d)
          leftRangeCount = subtractArrays(
              leftRangeCount, subtractArrays(counts[ra], counts[max(d, rb)]));
        ans.push_back(ranges::all_of(leftRangeCount, [](int freq) {
          return freq >= 0;
        }) && ranges::all_of(rightRangeCount, [](int freq) {
          return freq >= 0;
        }) && leftRangeCount == rightRangeCount);
      }
    }

    return ans;
  }

 private:
  vector<int> getMirroredDiffs(const string& s) {
    vector<int> diffs(1);
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j)
      diffs.push_back(diffs.back() + (s[i] != s[j] ? 1 : 0));
    return diffs;
  }

  vector<vector<int>> getCounts(const string& s) {
    vector<int> count(26);
    vector<vector<int>> counts{count};
    for (const char c : s) {
      ++count[c - 'a'];
      counts.push_back(count);
    }
    return counts;
  }

  vector<int> subtractArrays(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    for (int i = 0; i < a.size(); ++i)
      res.push_back(a[i] - b[i]);
    return res;
  }
};
