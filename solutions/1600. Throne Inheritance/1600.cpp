class ThroneInheritance {
 public:
  ThroneInheritance(string kingName) : kingName(kingName) {}

  void birth(string parentName, string childName) {
    family[parentName].push_back(childName);
  }

  void death(string name) {
    dead.insert(name);
  }

  vector<string> getInheritanceOrder() {
    vector<string> ans;
    dfs(kingName, ans);
    return ans;
  }

 private:
  unordered_set<string> dead;
  unordered_map<string, vector<string>> family;
  string kingName;

  void dfs(const string& name, vector<string>& ans) {
    if (!dead.contains(name))
      ans.push_back(name);
    if (!family.contains(name))
      return;

    for (const string& child : family[name])
      dfs(child, ans);
  }
};
