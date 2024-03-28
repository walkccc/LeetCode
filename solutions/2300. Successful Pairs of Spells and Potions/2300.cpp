class Solution {
 public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                              long long success) {
    vector<int> ans;
    ranges::sort(potions);

    for (const int spell : spells)
      ans.push_back(potions.size() -
                    firstIndexSuccess(spell, potions, success));

    return ans;
  }

 private:
  // Returns the first index i s.t. spell * potions[i] >= success.
  int firstIndexSuccess(int spell, const vector<int>& potions,
                        long long success) {
    int l = 0;
    int r = potions.size();
    while (l < r) {
      const int m = (l + r) / 2;
      if (static_cast<long long>(spell) * potions[m] >= success)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
