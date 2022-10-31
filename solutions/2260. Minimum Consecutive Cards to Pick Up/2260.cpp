class Solution {
 public:
  int minimumCardPickup(vector<int>& cards) {
    int ans = INT_MAX;
    unordered_map<int, int> lastOccurrence;

    for (int i = 0; i < cards.size(); ++i) {
      if (lastOccurrence.count(cards[i]))
        ans = min(ans, i - lastOccurrence[cards[i]] + 1);
      lastOccurrence[cards[i]] = i;
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
