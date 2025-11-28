class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        if (maxOnes == sideLength * sideLength) return width * height;
        int rowN = width / sideLength;
        int colN = height / sideLength;
        int ans = rowN * colN * maxOnes;
        int colL = width % sideLength;
        int rowL = height % sideLength;
        int rcL = colL * rowL;
        if (maxOnes <= rcL) {
            return ans + maxOnes * (rowN + colN + 1);
        }
        ans += rcL;
        if (rowN > colN) {
            if (sideLength * rowL >= maxOnes) {
                return ans + rowN * maxOnes + colN * rcL;
            }
            ans += rowN * sideLength * rowL;
            int left = maxOnes - sideLength * rowL + rcL;
            if (sideLength * colL >= left) {
                return ans + colN * left;
            }
            return  ans + colN * sideLength * colL;
        } else {
            if (sideLength * colL >= maxOnes) {
                return ans + colN * maxOnes + rowN * rcL;
            }
            ans += colN * sideLength * colL;
            int left = maxOnes - sideLength * colL + rcL;
            if (sideLength * rowL >= left) {
                return ans + rowN * left;
            }
            return  ans + rowN * sideLength * rowL;
        }
    }
};