# 1. 空间开销的解法
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        m = {}
        for n in nums:
            if n in m:
                m[n] += 1
                continue
            else:
                m[n] = 1
        for k, v in m.items():
            if v == 1:
                return k
        return None

# 2. O(n) + O(1)
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        single = 0
        for n in nums:
            single ^= n
        return single