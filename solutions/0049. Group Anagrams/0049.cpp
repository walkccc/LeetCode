class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> keyToAnagrams;

    for (const string& str : strs) {
      string key = str;
      sort(begin(key), end(key));
      keyToAnagrams[key].push_back(str);
    }

    for (const auto& [_, anagrams] : keyToAnagrams)
      ans.push_back(anagrams);

    return ans;
  }
};
