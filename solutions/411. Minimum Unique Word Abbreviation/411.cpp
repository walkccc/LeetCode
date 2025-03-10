class Solution {
 public:
  string minAbbreviation(string target, vector<string>& dictionary) {
    const int m = target.length();
    vector<int> masks;

    for (const string& word : dictionary) {
      if (word.length() != m)
        continue;
      masks.push_back(getMask(target, word));
    }

    if (masks.empty())
      return to_string(m);

    vector<string> abbrs;

    const int maxCand = pow(2, m);
    // all the candidate representation of the target
    for (int cand = 0; cand < maxCand; ++cand)
      // All the masks have at lease one bit different from the candidate.
      if (ranges::all_of(masks, [cand](int mask) { return cand & mask; }))
        abbrs.push_back(getAbbr(target, cand));

    string ans = target;

    for (const string& abbr : abbrs)
      if (getAbbrLen(abbr) < getAbbrLen(ans))
        ans = abbr;

    return ans;
  }

 private:
  int getMask(const string& target, const string& word) {
    const int m = target.length();
    // mask[i] = 0 := target[i] == word[i]
    // mask[i] = 1 := target[i] != word[i]
    // e.g. target = "apple"
    //        word = "blade"
    //        mask =  11110
    int mask = 0;
    for (int i = 0; i < m; ++i)
      if (word[i] != target[i])
        mask |= 1 << m - 1 - i;
    return mask;
  }

  string getAbbr(const string& target, int cand) {
    const int m = target.length();
    string abbr;
    int replacedCount = 0;
    for (int i = 0; i < m; ++i)
      if (cand >> m - 1 - i & 1) {
        // If cand[i] = 1, `abbr` should show the original character.
        if (replacedCount > 0)
          abbr += to_string(replacedCount);
        abbr += target[i];
        replacedCount = 0;
      } else {
        // If cand[i] = 0, `abbr` can be replaced.
        ++replacedCount;
      }
    if (replacedCount > 0)
      abbr += to_string(replacedCount);
    return abbr;
  }

  int getAbbrLen(const string& abbr) {
    int abbrLen = 0;
    int i = 0;
    int j = 0;
    while (i < abbr.length()) {
      if (isalpha(abbr[j]))
        ++j;
      else
        while (j < abbr.length() && isdigit(abbr[j]))
          ++j;
      ++abbrLen;
      i = j;
    }
    return abbrLen;
  }
};
