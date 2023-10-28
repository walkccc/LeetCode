class Solution {
 public:
  int oddEvenJumps(vector<int>& arr) {
    const int n = arr.size();
    map<int, int> map;    // {num: min index}
    vector<bool> inc(n);  // inc[i] := can reach arr[n - 1] from i w/ inc jump
    vector<bool> dec(n);  // dec[i] := can reach arr[n - 1] from i w/ dec jump

    map[arr[n - 1]] = n - 1;
    inc.back() = true;
    dec.back() = true;

    for (int i = n - 2; i >= 0; --i) {
      const auto lo = map.lower_bound(arr[i]);  // Min val >= arr[i]
      const auto hi = map.upper_bound(arr[i]);  // Min val > arr[i]
      if (lo != map.cend())
        inc[i] = dec[lo->second];
      if (hi != map.cbegin())
        dec[i] = inc[prev(hi)->second];
      map[arr[i]] = i;
    }

    return ranges::count(inc, true);
  }
};
