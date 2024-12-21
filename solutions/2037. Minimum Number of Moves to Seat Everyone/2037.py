class Solution:
  def minMovesToSeat(self, seats: list[int], students: list[int]) -> int:
    return sum(
        abs(seat - student) for seat,
        student in zip(sorted(seats),
                       sorted(students)))
