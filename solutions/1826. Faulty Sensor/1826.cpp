class Solution {
 public:
  int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
    const bool oneDefect = canReplace(sensor2, sensor1);
    const bool twoDefect = canReplace(sensor1, sensor2);
    if (oneDefect && twoDefect)
      return -1;
    if (!oneDefect && !twoDefect)
      return -1;
    return oneDefect ? 1 : 2;
  }

 private:
  bool canReplace(const vector<int>& A, const vector<int>& B) {
    int i = 0;  // A's index
    int j = 0;  // B's index
    int droppedValue = -1;

    while (i < A.size())
      if (A[i] == B[j]) {
        ++i;
        ++j;
      } else {
        droppedValue = A[i];
        ++i;
      }

    return j == B.size() - 1 && B[j] != droppedValue;
  }
};
