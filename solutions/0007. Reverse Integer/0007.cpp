class Solution {
 public:
  int reverse(int x) {
    long ans = 0;

    while (x) {
      ans = ans * 10 + x % 10;
      x /= 10;
    }

    return (ans < INT_MIN || ans > INT_MAX) ? 0 : ans;
  }
};

class Solution
{
public:
  // using int which is 4bytes, 32bits
  int reverse(int x)
  {
    bool sign = x >= 0;
    x = sign ? x : -x;
    int ans = 0;
    while (x > 0)
    {
      if (ans > INT_MAX / 10 - x % 10 + 1)
        return 0;
      ans = ans * 10 + x % 10;
      x /= 10;
    }
    return sign ? ans : -ans;
  }
};
