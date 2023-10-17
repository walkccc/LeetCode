class Solution:
  def generatePossibleNextMoves(self, currentState: str) -> List[str]:
    return [currentState[:i] + '--' + currentState[i + 2:]
            for i, (a, b) in enumerate(zip(currentState, currentState[1:]))
            if a == '+' and b == '+']
