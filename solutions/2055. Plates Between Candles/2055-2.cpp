class Solution {
 public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    const int n = s.length();
    vector<int> ans;
    vector<int> closestLeftCandle(n);
    vector<int> closestRightCandle(n);
    vector<int> candleCount(
        n);  // candleCount[i] := the number of candles in s[0..i]
    int candle = -1;
    int count = 0;

    for (int i = 0; i < n; ++i) {
      if (s[i] == '|') {
        candle = i;
        ++count;
      }
      closestLeftCandle[i] = candle;
      candleCount[i] = count;
    }

    candle = -1;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '|')
        candle = i;
      closestRightCandle[i] = candle;
    }

    for (const vector<int>& query : queries) {
      const int left = query[0];
      const int right = query[1];
      const int l = closestRightCandle[left];
      const int r = closestLeftCandle[right];
      if (l == -1 || r == -1 || l > r) {
        ans.push_back(0);
      } else {
        const int lengthBetweenCandles = r - l + 1;
        const int numCandles = candleCount[r] - candleCount[l] + 1;
        ans.push_back(lengthBetweenCandles - numCandles);
      }
    }

    return ans;
  }
};
