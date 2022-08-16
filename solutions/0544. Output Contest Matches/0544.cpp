class Solution {
 public:
  string findContestMatch(int n) {
    vector<string> matches(n);

    for (int i = 0; i < n; ++i)
      matches[i] = to_string(i + 1);

    return generateMatches(matches);
  }

 private:
  string generateMatches(const vector<string>& matches) {
    if (matches.size() == 1)
      return matches[0];

    vector<string> nextMatches;

    for (int i = 0; i < matches.size() / 2; ++i)
      nextMatches.push_back("(" + matches[i] + "," +
                            matches[matches.size() - 1 - i] + ")");

    return generateMatches(nextMatches);
  }
};
