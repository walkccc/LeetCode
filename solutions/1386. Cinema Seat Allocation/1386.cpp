class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    int ans = 0;
    unordered_map<int, int> rowToSeats;

    for (const vector<int>& reservedSeat : reservedSeats) {
      const int row = reservedSeat[0];
      const int seat = reservedSeat[1];
      rowToSeats[row] |= 1 << (seat - 1);
    }

    for (const auto& [_, seats] : rowToSeats)
      if ((seats & 0b0111111110) == 0)
        // Can fit 2 four-person groups.
        ans += 2;
      else if ((seats & 0b0111100000) == 0 ||  // Left not occupied.
               (seats & 0b0001111000) == 0 ||  // Mid not occupied.
               (seats & 0b0000011110) == 0)    // Right not occupied.
        // Can fit 1 four-person group.
        ans += 1;

    // Any empty rows can fit 2 four-person groups.
    return ans + (n - rowToSeats.size()) * 2;
  }
};
