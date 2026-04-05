class Solution {
 public:
  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    vector<string> ans;
    unordered_map<string, vector<int>> nameToMinutes;

    for (int i = 0; i < keyName.size(); ++i) {
      const int minutes = getMinutes(keyTime[i]);
      nameToMinutes[keyName[i]].push_back(minutes);
    }

    for (auto& [name, minutes] : nameToMinutes)
      if (hasAlert(minutes))
        ans.push_back(name);

    ranges::sort(ans);
    return ans;
  }

 private:
  // Returns true if any worker uses the key-card three or more times in an
  // one-hour period.
  bool hasAlert(vector<int>& minutes) {
    if (minutes.size() > 70)
      return true;
    ranges::sort(minutes);
    for (int i = 2; i < minutes.size(); ++i)
      if (minutes[i - 2] + 60 >= minutes[i])
        return true;
    return false;
  }

  int getMinutes(const string& time) {
    const int h = stoi(time.substr(0, 2));
    const int m = stoi(time.substr(3));
    return 60 * h + m;
  }
};
