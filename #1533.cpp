/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int l = 0, r = reader.length() - 1;
        while (l != r) {
            int lmid, rmid;
            lmid = (l + r) / 2;
            rmid = (l + r) % 2 ? lmid + 1 : lmid;
            int val = reader.compareSub(l, lmid, rmid, r);
            if (val == 0) {
                return lmid;
            } else if (val > 0) {
                r = lmid;
            } else {
                l = rmid;
            }
        }
        return l;
    }
};