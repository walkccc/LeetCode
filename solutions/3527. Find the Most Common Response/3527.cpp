class Solution {
 public:
  string findCommonResponse(vector<vector<string>>& responses) {
    string ans;
    unordered_map<string, int> count;
    int maxFreq = 0;

    for (const vector<string>& response : responses)
      for (const string& response :
           unordered_set<string>{response.begin(), response.end()})
        ++count[response];

    for (const pair<const string, int>& entry : count)
      maxFreq = max(maxFreq, entry.second);

    for (const auto& [response, freq] : count)
      if (freq == maxFreq && (ans.empty() || response < ans))
        ans = response;

    return ans;
  }
};
