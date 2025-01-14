class Solution {
 public:
  bool isValidSerialization(string preorder) {
    int degree = 1;  // out-degree (children) - in-degree (parent)
    istringstream iss(preorder);

    for (string node; getline(iss, node, ',');) {
      if (--degree < 0)
        return false;
      if (node != "#")
        degree += 2;
    }

    return degree == 0;
  }
};
