class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        ans = []
        
        # Sort the given array:
        nums.sort()

        # Calculating the quadruplets:
        for i in range(n):
            # Avoid duplicates while moving i:
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            for j in range(i + 1, n):
                # Avoid duplicates while moving j:
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                
                # Two pointers:
                k = j + 1
                l = n - 1
                
                while k < l:
                    total_sum = nums[i] + nums[j] + nums[k] + nums[l]
                    
                    if total_sum == target:
                        temp = [nums[i], nums[j], nums[k], nums[l]]
                        ans.append(temp)
                        k += 1
                        l -= 1
                        
                        # Skip the duplicates:
                        while k < l and nums[k] == nums[k - 1]:
                            k += 1
                        while k < l and nums[l] == nums[l + 1]:
                            l -= 1
                    elif total_sum < target:
                        k += 1
                    else:
                        l -= 1
        
        return ans