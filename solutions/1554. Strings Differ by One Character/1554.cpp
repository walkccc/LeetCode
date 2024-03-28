class Solution {
 public:
  bool differByOne(vector<string>& dict) {
    unordered_set<string> seen;

    for (string& word : dict) {
      for (char& c : word) {
        const char cache = c;
        for (char next = 'a'; next <= 'z'; ++next) {
          if (next == cache)
            continue;
          c = next;
          if (seen.count(word))
            return true;
        }
        c = cache;
      }
      seen.insert(word);
    }

    return false;
  }
};
