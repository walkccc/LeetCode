class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    ranges::sort(properties, ranges::less{}, [](const vector<int>& property) {
      const int attack = property[0];
      const int defense = property[1];
      return pair<int, int>{-attack, defense};
    });

    int ans = 0;
    int maxDefense = 0;

    for (const vector<int>& property : properties) {
      const int defense = property[1];
      if (defense < maxDefense)
        ++ans;
      maxDefense = max(maxDefense, defense);
    }

    return ans;
  }
};
