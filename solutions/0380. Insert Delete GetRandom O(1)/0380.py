class RandomizedSet:
    def __init__(self):
        self.vals = []
        self.dict = collections.defaultdict(int)

    def insert(self, val: int) -> bool:
        if val in self.dict:
            return False
        self.dict[val] = len(self.vals)
        self.vals.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.dict:
            return False
        index = self.dict[val]
        self.dict[self.vals[-1]] = index
        del self.dict[val]
        self.vals[index] = self.vals[-1]
        self.vals.pop()
        return True

    def getRandom(self) -> int:
        index = random.randint(0, len(self.vals) - 1)
        return self.vals[index]
