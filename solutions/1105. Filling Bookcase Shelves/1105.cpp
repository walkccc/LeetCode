class Solution {
 public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    // dp[i] := the minimum height to place the first i books
    vector<int> dp(books.size() + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < books.size(); ++i) {
      int sumThickness = 0;
      int maxHeight = 0;
      // Place books[j..i] on a new shelf.
      for (int j = i; j >= 0; --j) {
        const int thickness = books[j][0];
        const int height = books[j][1];
        sumThickness += thickness;
        if (sumThickness > shelfWidth)
          break;
        maxHeight = max(maxHeight, height);
        dp[i + 1] = min(dp[i + 1], dp[j] + maxHeight);
      }
    }

    return dp.back();
  }
};
