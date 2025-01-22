class Solution {
 public:
  vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> ans;
    vector<string> digitLogs;
    vector<pair<string, string>> letterLogs;

    for (const string& log : logs) {
      const int i = log.find_first_of(' ');
      if (isdigit(log[i + 1]))
        digitLogs.push_back(log);
      else
        letterLogs.emplace_back(log.substr(0, i), log.substr(i + 1));
    }

    ranges::sort(letterLogs, [](const pair<string, string>& a,
                                const pair<string, string>& b) {
      return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    for (const auto& [identifier, letters] : letterLogs)
      ans.push_back(identifier + ' ' + letters);

    for (const string& digitLog : digitLogs)
      ans.push_back(digitLog);

    return ans;
  }
};
