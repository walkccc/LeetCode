class Solution:
  def badSensor(self, sensor1: list[int], sensor2: list[int]) -> int:
    # A -> B, so B is defect
    def canReplace(A, B):
      i = 0  # A's index
      j = 0  # B's index
      droppedValue = -1

      while i < len(A):
        if A[i] == B[j]:
          i += 1
          j += 1
        else:
          droppedValue = A[i]
          i += 1

      return j == len(B) - 1 and B[-1] != droppedValue

    oneDefect = canReplace(sensor2, sensor1)
    twoDefect = canReplace(sensor1, sensor2)
    if oneDefect and twoDefect:
      return -1
    if not oneDefect and not twoDefect:
      return -1
    return 1 if oneDefect else 2
