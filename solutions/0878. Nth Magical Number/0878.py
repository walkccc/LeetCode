class Solution:
    def nthMagicalNumber(self, N: int, A: int, B: int) -> int:
        kMod = int(1e9 + 7)
        lcm = A * B // math.gcd(A, B)
        l = min(A, B)
        r = min(A, B) * N

        while l < r:
            m = (l + r) // 2
            if m // A + m // B - m // lcm < N:
                l = m + 1
            else:
                r = m

        return l % kMod
