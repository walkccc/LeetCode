class Solution {
 public:
  int oddEvenJumps(vector<int>& A) {
    const int n = A.size();
    map<int, int> map;    // {num: min index}
    vector<bool> inc(n);  // inc[i] := can reach A[n - 1] from i w/ inc jump
    vector<bool> dec(n);  // dec[i] := can reach A[n - 1] from i w/ dec jump

    map[A[n - 1]] = n - 1;
    inc.back() = true;
    dec.back() = true;

    for (int i = n - 2; i >= 0; --i) {
      const auto lo = map.lower_bound(A[i]);  // min val >= A[i]
      const auto hi = map.upper_bound(A[i]);  // min val > A[i]
      if (lo != cend(map))
        inc[i] = dec[lo->second];
      if (hi != cbegin(map))
        dec[i] = inc[prev(hi)->second];
      map[A[i]] = i;
    }

    return count(begin(inc), end(inc), true);
  }
};
