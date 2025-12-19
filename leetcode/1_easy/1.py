class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for key, n in enumerate(nums):
            rest = target - n
            map[rest] = key
        for key, n in enumerate(nums):
            if n in map and map[n] != key:
                return [key, map[n]]