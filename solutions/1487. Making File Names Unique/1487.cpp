class Solution {
 public:
  vector<string> getFolderNames(vector<string>& names) {
    vector<string> ans;
    unordered_map<string, int> nameToSuffix;

    for (const string& name : names)
      if (const auto it = nameToSuffix.find(name); it != nameToSuffix.cend()) {
        int suffix = it->second;
        string newName = getName(name, ++suffix);
        while (nameToSuffix.count(newName))
          newName = getName(name, ++suffix);
        nameToSuffix[name] = suffix;
        nameToSuffix[newName] = 0;
        ans.push_back(newName);
      } else {
        nameToSuffix[name] = 0;
        ans.push_back(name);
      }

    return ans;
  }

 private:
  string getName(const string& name, int suffix) {
    return name + "(" + to_string(suffix) + ")";
  }
};
