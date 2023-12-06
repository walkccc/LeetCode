class Solution {
 public:
  bool areNumbersAscending(string s) {
    int prev = 0;
    istringstream iss(s);

    for (string token; iss >> token;)
      if (isdigit(token[0])) {
        const int num = stoi(token);
        if (num <= prev)
          return false;
        prev = num;
      }

    return true;
  }
};
