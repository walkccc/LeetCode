class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> ans;
    vector<int> count(10);

    for (const int digit : digits)
      ++count[digit];

    // try to construct `abc`
    for (int a = 1; a <= 9; ++a)
      for (int b = 0; b <= 9; ++b)
        for (int c = 0; c <= 8; c += 2)
          if (count[a] > 0 && count[b] > (b == a) &&
              count[c] > (c == a) + (c == b))
            ans.push_back(a * 100 + b * 10 + c);

    return ans;
  }
};
