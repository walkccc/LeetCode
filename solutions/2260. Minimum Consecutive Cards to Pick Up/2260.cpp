class Solution {
 public:
  int minimumCardPickup(vector<int>& cards) {
    int ans = INT_MAX;
    unordered_map<int, int> lastSeen;

    for (int i = 0; i < cards.size(); ++i) {
      if (const auto it = lastSeen.find(cards[i]); it != lastSeen.cend())
        ans = min(ans, i - it->second + 1);
      lastSeen[cards[i]] = i;
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
