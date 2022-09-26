class Solution {
 public:
  int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes,
                    int maxWeight) {
    const int n = boxes.size();
    // dp[i] := min trips to deliver boxes[0..i) and return to the storage
    vector<int> dp(n + 1);
    int trips = 2;
    int weight = 0;

    for (int l = 0, r = 0; r < n; ++r) {
      weight += boxes[r][1];

      // current box is different from previous one, need to make one more trip
      if (r > 0 && boxes[r][0] != boxes[r - 1][0])
        ++trips;

      while (r - l + 1 > maxBoxes || weight > maxWeight ||
             // loading boxes[l] in the previous turn is always no bad than
             // loading it in this turn
             (l < r && dp[l + 1] == dp[l])) {
        weight -= boxes[l][1];
        if (boxes[l][0] != boxes[l + 1][0])
          --trips;
        ++l;
      }

      //   min trips to deliver boxes[0..r]
      // = min trips to deliver boxes[0..l) + trips to deliver boxes[l..r]
      dp[r + 1] = dp[l] + trips;
    }

    return dp[n];
  }
};
