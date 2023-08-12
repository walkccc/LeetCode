class Solution {
 public:
  int findInteger(int k, int digit1, int digit2) {
    const int minDigit = min(digit1, digit2);
    const int maxDigit = max(digit1, digit2);
    const vector<int> digits = minDigit == maxDigit
                                   ? vector<int>{minDigit}
                                   : vector<int>{minDigit, maxDigit};
    queue<int> q;

    for (const int digit : digits)
      q.push(digit);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      if (u > k && u % k == 0)
        return u;
      if (u == 0)
        continue;
      for (const int digit : digits) {
        const long nextNum = u * 10L + digit;
        if (nextNum > INT_MAX)
          continue;
        q.push(nextNum);
      }
    }

    return -1;
  }
};
