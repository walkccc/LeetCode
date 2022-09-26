class Solution {
 public:
  vector<int> constructRectangle(int area) {
    int width = sqrt(area);

    while (area % width)
      --width;

    return {area / width, width};
  }
};
