class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Edge case: If there are no balloons, no arrows needed
        if (points.empty()) return 0;

        // Sort the balloons based on their ending position
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrowPos = points[0][1]; // Position of the first arrow
        int arrowCount = 1; // At least one arrow is needed

        for (int i = 1; i < points.size(); i++) {
            // If the current balloon's start position is greater than the last arrow position,
            // we need a new arrow to burst this balloon
            if (points[i][0] > arrowPos) {
                arrowPos = points[i][1]; // Update the arrow position
                arrowCount++;
            }
        }

        return arrowCount;
    }
};