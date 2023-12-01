class Solution:
  def calPoints(self, operations: List[str]) -> int:
    scores = []

    for operation in operations:
      match operation:
        case '+':
          scores.append(scores[-1] + scores[-2])
        case 'D':
          scores.append(scores[-1] * 2)
        case 'C':
          scores.pop()
        case default:
          scores.append(int(operation))

    return sum(scores)
