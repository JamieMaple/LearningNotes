# # 1. 暴力解法
# import math
# class Solution:
#     def transferNum(self, x: int) -> [int]:
#         q = []
#         while True:
#             n = x % 2
#             x = math.floor(x / 2)
#             q.append(n)

#             if x <= 0:
#                 break

#         return q
#     def hammingDistance(self, x: int, y: int) -> int:
#         xq = self.transferNum(x)
#         yq = self.transferNum(y)
        
#         result = 0
#         i = 0
#         xn = yn = 0
#         while True:
#             if i >= len(xq):
#                 xn = 0
#             else:
#                 xn = xq[i]
            
#             if i >= len(yq):
#                 yn = 0
#             else:
#                 yn = yq[i]

#             if xn != yn:
#                 result += 1
            
#             i += 1
#             if i >= len(xq) and i >= len(yq):
#                 break

#         return result
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        result = 0
        r = x ^ y
        while True:
            if r & 1 == 1:
                result += 1

            r >>= 1
            if r == 0:
                break

        return result

s = Solution()
r = s.hammingDistance(1, 4)
print(r)
r = s.hammingDistance(3, 1)
print(r)
