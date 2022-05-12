class LogSystem {
 public:
  void put(int id, string timestamp) {
    idAndTimestamps.emplace_back(id, timestamp);
  }

  vector<int> retrieve(string start, string end, string granularity) {
    vector<int> ans;
    const int index = granularityToIndices.at(granularity);
    const string s = start.substr(0, index);
    const string e = end.substr(0, index);

    for (const auto& [id, timestamp] : idAndTimestamps) {
      const string& t = timestamp.substr(0, index);
      if (s <= t && t <= e)
        ans.push_back(id);
    }

    return ans;
  }

 private:
  const unordered_map<string, int> granularityToIndices{
      {"Year", 4},  {"Month", 7},   {"Day", 10},
      {"Hour", 13}, {"Minute", 16}, {"Second", 19}};
  vector<pair<int, string>> idAndTimestamps;
};
