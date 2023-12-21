class Solution {
 public:
  vector<long long> minimumRelativeLosses(vector<int>& prices,
                                          vector<vector<int>>& queries) {
    const int n = prices.size();
    vector<long long> ans;
    vector<long long> prefix{0};

    ranges::sort(prices);

    for (const int price : prices)
      prefix.push_back(prefix.back() + price);

    for (const vector<int>& query : queries) {
      const int k = query[0];
      const int m = query[1];
      const int countFront = getCountFront(k, m, prices, prefix);
      const int countBack = m - countFront;
      ans.push_back(getRelativeLoss(countFront, countBack, k, prefix));
    }

    return ans;
  }

 private:
  // Returns the `countFront` for query (k, m) s.t. picking the first
  // `countFront` and the last `m - countFront` chocolates is optimal.
  //
  // Define loss[i] := the relative loss of picking `prices[i]`.
  // 1. For prices[i] <= k, Bob pays prices[i] while Alice pays 0.
  //    Thus, loss[i] = prices[i] - 0 = prices[i].
  // 2. For prices[i] > k, Bob pays k while Alice pays prices[i] - k.
  //    Thus, loss[i] = k - (prices[i] - k) = 2 * k - prices[i].
  // By observation, we deduce that it is always better to pick from the front
  // or the back since loss[i] is increasing for 1. and is decreasing for 2.
  //
  // Assume that picking `left` chocolates from the left and `right = m - left`
  // chocolates from the right is optimal. Therefore, we are selecting
  // chocolates from `prices[0..left - 1]` and `prices[n - right..n - 1]`.
  //
  // To determine the optimal `left` in each iteration, we simply compare
  // `loss[left]` with `loss[n - right]`; if `loss[left] < loss[n - right]`,
  // it's worth increasing `left`.
  int getCountFront(int k, int m, const vector<int>& prices,
                    const vector<long long>& prefix) {
    const int n = prices.size();
    const int countNoGreaterThanK =
        ranges::upper_bound(prices, k) - prices.begin();
    int l = 0;
    int r = min(countNoGreaterThanK, m);

    while (l < r) {
      const int mid = (l + r) / 2;
      const int right = m - mid;
      // Picking prices[mid] is better than picking prices[n - right].
      if (prices[mid] < 2LL * k - prices[n - right])
        l = mid + 1;
      else
        r = mid;
    }

    return l;
  }

  // Returns the relative loss of picking `countFront` and `countBack`
  // chocolates.
  long long getRelativeLoss(int countFront, int countBack, int k,
                            const vector<long long>& prefix) {
    const long long lossFront = prefix[countFront];
    const long long lossBack =
        2LL * k * countBack -
        (prefix.back() - prefix[prefix.size() - 1 - countBack]);
    return lossFront + lossBack;
  }
};
