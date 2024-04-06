class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, e = 0, len(height) - 1
        maxi = 0
        
        while l < e:
            min_h = min(height[l], height[e])
            curr_area = min_h * (e - l)
            
            maxi = max(maxi, curr_area)
            
            if height[l] < height[e]:
                l += 1
            else:
                e -= 1
        
        return maxi