from enum import Enum


class BoxCase(Enum):
  kEqualDistantBalls = 0
  kEqualBalls = 1


class Solution:
  def getProbability(self, balls: list[int]) -> float:
    n = sum(balls) // 2
    fact = [1, 1, 2, 6, 24, 120, 720]

    def cases(
            i: int,
            ballsCountA: int,
            ballsCountB: int,
            colorsCountA: int,
            colorsCountB,
            boxCase: BoxCase) -> float:
      if ballsCountA > n or ballsCountB > n:
        return 0
      if i == len(balls):
        return (1 if boxCase == BoxCase.kEqualBalls
                else colorsCountA == colorsCountB)

      ans = 0.0

      # balls taken from A for `balls[i]`
      for ballsTakenA in range(balls[i] + 1):
        ballsTakenB = balls[i] - ballsTakenA
        newcolorsCountA = colorsCountA + (ballsTakenA > 0)
        newcolorsCountB = colorsCountB + (ballsTakenB > 0)
        ans += (cases(i + 1,
                      ballsCountA + ballsTakenA,
                      ballsCountB + ballsTakenB,
                      newcolorsCountA, newcolorsCountB, boxCase) /
                (fact[ballsTakenA] * fact[ballsTakenB]))

      return ans

    return (cases(0, 0, 0, 0, 0, BoxCase.kEqualDistantBalls) /
            cases(0, 0, 0, 0, 0, BoxCase.kEqualBalls))
