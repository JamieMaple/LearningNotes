# 1. 暴力解法 -> n^2
# class Solution:
#     def trap(self, height: List[int]) -> int:
#         result = 0
#         for i in range(0, len(height)):
#             h = lMax = rMax = height[i]
            
#             # find left max height
#             for l in range(0, i):
#                 lMax = max(lMax, height[l])
#             # find right min height
#             for r in range(i, len(height)):
#                 rMax = max(rMax, height[r])

#             result += min(lMax, rMax) - h
#         return result

# 2. 动态规划
class Solution:
    def trap(self, height) -> int:
        result = 0
        lMaxList = [0] * len(height)
        rMaxList = [0] * len(height)
        maxHeight = max(height)

        for i, h in enumerate(height):
            if i <= 0:
                lMaxList[i] = h
            else:
                lMaxList[i] = max(lMaxList[i - 1], h)
        for j in range(len(height) - 1, -1, -1):
            h = height[j]
            if j >= len(height) - 1:
                rMaxList[j] = h
            else:
                rMaxList[j] = max(rMaxList[j + 1], h)
            
        for i, h in enumerate(height):
            lMax = lMaxList[i]
            rMax = rMaxList[i]
            result += min(lMax, rMax) - h

        return result

# # final 最终解法
# class Solution:
#     def trap(self, height: List[int]) -> int:
#         result = 0
#         l = 0
#         r = len(height) - 1
#         lMax = 0
#         rMax = 0

#         while l < r:
#             lMax = max(height[l], lMax)
#             rMax = max(height[r], rMax)
            
#             if height[l] < height[r]:
#                 result += lMax - height[l]
#                 l += 1
#             else:
#                 result += rMax - height[r]
#                 r -= 1

#         return result
