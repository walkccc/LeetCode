class Solution {
 public:
  bool isPathCrossing(string path) {
    set<int> seen;

    seen.insert(0);

    int x = 0;
    int y = 0;

    for (const char c : path) {
      switch (c) {
        case 'N':
          ++y;
          break;
        case 'S':
          --y;
          break;
        case 'E':
          ++x;
          break;
        case 'W':
          --x;
          break;
      }
      const int key = x * 20001 + y;
      if (seen.count(key)) return true;
      seen.insert(key);
    }

    return false;
  }
};
