class Encrypter:
  def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
    self.keyToValue = {k: v for k, v in zip(keys, values)}
    self.decrypt = collections.Counter(self.encrypt(word)
                                       for word in dictionary).__getitem__

  def encrypt(self, word1: str) -> str:
    return ''.join(self.keyToValue[c] for c in word1)
