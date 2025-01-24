class Solution {
 public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if (tomatoSlices % 2 == 1 || tomatoSlices < 2 * cheeseSlices ||
        tomatoSlices > cheeseSlices * 4)
      return {};

    int jumboBurgers = (tomatoSlices - 2 * cheeseSlices) / 2;

    return {jumboBurgers, cheeseSlices - jumboBurgers};
  }
};
