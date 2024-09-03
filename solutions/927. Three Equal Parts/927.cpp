class Solution {
 public:
  vector<int> threeEqualParts(vector<int>& arr) {
    const int ones = ranges::count_if(arr, [](int a) { return a == 1; });

    if (ones == 0)
      return {0, static_cast<int>(arr.size()) - 1};
    if (ones % 3 != 0)
      return {-1, -1};

    int k = ones / 3;
    int i;
    int j;
    int first;
    int second;
    int third;

    for (i = 0; i < arr.size(); ++i)
      if (arr[i] == 1) {
        first = i;
        break;
      }

    int gapOnes = k;

    for (j = i + 1; j < arr.size(); ++j)
      if (arr[j] == 1 && --gapOnes == 0) {
        second = j;
        break;
      }

    gapOnes = k;

    for (i = j + 1; i < arr.size(); ++i)
      if (arr[i] == 1 && --gapOnes == 0) {
        third = i;
        break;
      }

    while (third < arr.size() && arr[first] == arr[second] &&
           arr[second] == arr[third]) {
      ++first;
      ++second;
      ++third;
    }

    if (third == arr.size())
      return {first - 1, second};
    return {-1, -1};
  }
};
