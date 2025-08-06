class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        used = set()
        unplaced = 0
        n = len(fruits)
        m = len(baskets)
        
        for fruit in fruits:
            placed = False
            for i in range(m):
                if i not in used and baskets[i] >= fruit:
                    used.add(i)
                    placed = True
                    break
            if not placed:
                unplaced += 1
        return unplaced
