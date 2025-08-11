class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> stack;

    for (const int a : asteroids)
      if (a > 0) {
        stack.push_back(a);
      } else {  // a < 0
        // Destroy the previous positive one(s).
        while (!stack.empty() && stack.back() > 0 && stack.back() < -a)
          stack.pop_back();
        if (stack.empty() || stack.back() < 0)
          stack.push_back(a);
        else if (stack.back() == -a)
          stack.pop_back();  // Both asteroids explode.
        else                 // stack[-1] > the current asteroid.
          ;                  // Destroy the current asteroid, so do nothing.
      }

    return stack;
  }
};
