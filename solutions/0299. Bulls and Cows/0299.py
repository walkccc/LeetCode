class Solution:
  def getHint(self, secret: str, guess: str) -> str:
    bulls = sum(map(operator.eq, secret, guess))
    bovine = sum(min(secret.count(x), guess.count(x)) for x in set(guess))
    return '%dA%dB' % (bulls, bovine - bulls)
