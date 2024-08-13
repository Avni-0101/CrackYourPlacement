class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalPts = 0, n = cardPoints.size();
        int newMax = 0;
        int maxPts = 0;

        for (int i = 0; i < n; i++) {
            totalPts += cardPoints[i];
            if (i < n - k) newMax += cardPoints[i];
        }

        int start = 0, end = n - k - 1;

        while (end < n - 1) {
            maxPts = max(maxPts, totalPts - newMax);
            newMax -= cardPoints[start];
            newMax += cardPoints[end + 1];
            start++;
            end++;
        }

        maxPts = max(maxPts, totalPts - newMax);

        return maxPts;
    }
};
