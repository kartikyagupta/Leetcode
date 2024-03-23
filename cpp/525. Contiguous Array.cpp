class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    int maxLength = 0;
    int count = 0; // Stores the difference between 1s and 0s seen so far
    unordered_map<int, int> map; // Map to store the first index seen for a specific count

    map[0] = -1; // Initialize with -1 for handling the case where the entire array starts with equal 0s and 1s

    for (int i = 0; i < nums.size(); i++) {
      count += (nums[i] == 0) ? -1 : 1; // Decrement for 0, increment for 1

      // Check if the current count has been seen before
      if (map.count(count)) {
        maxLength = max(maxLength, i - map[count]); // Update maxLength
      } else {
        map[count] = i; // Store the first index for the current count
      }
    }

    return maxLength;
  }
};
