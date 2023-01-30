class Solution:
    def tribonacci(self, n: int) -> int:
        t0 = 0
        t1 = t2 = 1
        
        if n == 0:
            return t0
        elif n == 1:
            return t1
        elif n == 2:
            return t2
        else:
            for _ in range(3, n + 1):
                t = t0 + t1 + t2
                t0 = t1
                t1 = t2
                t2 = t
                
            return t
