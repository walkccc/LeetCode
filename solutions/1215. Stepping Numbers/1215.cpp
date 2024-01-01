class Solution {
 public:
  vector<int> countSteppingNumbers(int low, int high) {
    vector<int> ans;
    if (low == 0)
      ans.push_back(0);

    queue<long> q;

    for (int i = 1; i <= 9; ++i)
      q.push(i);

    while (!q.empty()) {
      const long curr = q.front();
      q.pop();
      if (curr > high)
        continue;
      if (curr >= low)
        ans.push_back(curr);
      const int lastDigit = curr % 10;
      if (lastDigit > 0)
        q.push(curr * 10 + lastDigit - 1);
      if (lastDigit < 9)
        q.push(curr * 10 + lastDigit + 1);
    }

    return ans;
  }
};
