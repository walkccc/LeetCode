class Solution {
 public:
  int compareVersion(string version1, string version2) {
    istringstream iss1(version1);
    istringstream iss2(version2);
    int v1;
    int v2;
    char dotChar;

    while (bool(iss1 >> v1) + bool(iss2 >> v2)) {
      if (v1 < v2)
        return -1;
      if (v1 > v2)
        return 1;
      iss1 >> dotChar;
      iss2 >> dotChar;
      v1 = 0;
      v2 = 0;
    }

    return 0;
  };
};
