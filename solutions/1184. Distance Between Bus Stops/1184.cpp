class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance, int start,
                              int destination) {
    int clockwise = 0;
    int counterclockwise = 0;

    if (start > destination)
      swap(start, destination);

    for (int i = 0; i < distance.size(); ++i) {
      if (i >= start && i < destination)
        clockwise += distance[i];
      else
        counterclockwise += distance[i];
    }

    return min(clockwise, counterclockwise);
  }
};
