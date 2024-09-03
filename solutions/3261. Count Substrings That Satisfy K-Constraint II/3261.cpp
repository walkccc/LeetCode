class Solution {
 public:
  vector<long long> countKConstraintSubstrings(string s, int k,
                                               vector<vector<int>>& queries) {
    const int n = s.size();
    vector<long long> ans;
    vector<int> count(2);
    // leftToRight[l] : = the maximum right index r s.t.s[l..r] is valid
    vector<int> leftToRight(n);
    // rightToLeft[r] := the minimum left index l s.t. s[l..r] is valid
    vector<int> rightToLeft(n);
    // prefix[i] := the number of valid substrings ending in [0..i - 1].
    vector<long> prefix{0};

    for (int l = 0, r = 0; r < n; ++r) {
      ++count[s[r] - '0'];
      while (count[0] > k && count[1] > k)
        --count[s[l++] - '0'];
      rightToLeft[r] = l;
    }

    count = vector<int>(2);

    for (int l = n - 1, r = n - 1; l >= 0; --l) {
      ++count[s[l] - '0'];
      while (count[0] > k && count[1] > k)
        --count[s[r--] - '0'];
      leftToRight[l] = r;
    }

    for (int r = 0; r < n; ++r)
      prefix.push_back(prefix.back() + r - rightToLeft[r] + 1);

    for (const vector<int>& query : queries) {
      const int l = query[0];
      const int r = query[1];
      long numValidSubstrings = 0;
      if (r > leftToRight[l]) {
        // If r is beyond leftToRight[l], compute the number of valid substrings
        // from l to leftToRight[l] and add the number of valid substrings
        // ending in [leftToRight[l] + 1..r].
        //
        // prefix[r + 1] := the number of valid substrings ending in [0..r].
        // prefix[leftToRight[l] + 1] := the number of valid substrings ending
        // in [0..leftToRight].
        // => prefix[r + 1] - prefix[leftToRight[l] + 1] := the number of valid
        // substrings ending in [leftToRight[l] + 1..r].
        const int sz = leftToRight[l] - l + 1;
        numValidSubstrings =
            (sz * (sz + 1)) / 2 + (prefix[r + 1] - prefix[leftToRight[l] + 1]);
      } else {
        // If r is within the range of leftToRight[l], compute the number of
        // valid substrings directly from l to r.
        const int sz = r - l + 1;
        numValidSubstrings = (sz * static_cast<long>(sz + 1)) / 2;
      }
      ans.push_back(numValidSubstrings);
    }

    return ans;
  }
};
