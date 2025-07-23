class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    ranges::sort(envelopes, ranges::less{}, [](const vector<int>& envelope) {
      const int w = envelope[0];
      const int h = envelope[1];
      return pair<int, int>{w, -h};
    });
    return lengthOfLIS(envelopes);
  }

 private:
  // Same to 300. Longest Increasing Subsequence
  int lengthOfLIS(vector<vector<int>>& envelopes) {
    // tails[i] := the minimum tail of all the increasing subsequences having
    // length i + 1
    vector<int> tails;

    for (const vector<int>& envelope : envelopes) {
      const int h = envelope[1];
      if (tails.empty() || h > tails.back())
        tails.push_back(h);
      else
        tails[firstGreaterEqual(tails, h)] = h;
    }

    return tails.size();
  }

 private:
  int firstGreaterEqual(const vector<int>& arr, int target) {
    return ranges::lower_bound(arr, target) - arr.begin();
  }
};
