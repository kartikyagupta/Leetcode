# Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

class Solution:
    def findMedianSortedArrays(self, nums1:list[int], nums2: list[int]) -> float:
        nums = sorted(nums1 + nums2)
        n = len(nums)
        if n % 2 == 0:
            return (nums[n//2-1] + nums[n//2])/2
        else:
            return nums[n//2]