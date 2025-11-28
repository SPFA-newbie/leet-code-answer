/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    void setFive(vector<int>& res, int a, int b, int c, int d, int e) {
        res.push_back(a);
        res.push_back(b);
        res.push_back(c);
        res.push_back(d);
        res.push_back(e);
    }
    int firstFive(ArrayReader &reader, vector<int>& res) {
        switch(reader.query(0, 1, 2, 3)) {
            case 4: {
                if(reader.query(0, 1, 2, 4) == 4) setFive(res, 0, 0, 0, 0, 0);
                    else setFive(res, 0, 0, 0, 0, 1);
                return 0;
            }
            case 2: {
                if (reader.query(0, 1, 2, 4) == 4) {
                    setFive(res, 0, 0, 0, 1, 0);
                } else if (reader.query(0, 1, 3, 4) == 4) {
                    setFive(res, 0, 0, 1, 0, 0);
                } else if (reader.query(0, 2, 3, 4) == 4) {
                    setFive(res, 0, 1, 0, 0, 0);
                } else if (reader.query(1, 2, 3, 4) == 4) {
                    setFive(res, 1, 0, 0, 0, 0);
                } else if (reader.query(0, 1, 2, 4) == 2) {
                    setFive(res, 0, 0, 0, 1, 1);
                } else if (reader.query(0, 1, 3, 4) == 2) {
                    setFive(res, 0, 0, 1, 0, 1);
                } else if (reader.query(0, 2, 3, 4) == 2) {
                    setFive(res, 0, 1, 0, 0, 1);
                } else {
                    setFive(res, 1, 0, 0, 0, 1);
                }
                return 0;
            }
            case 0: {
                int val[5] = {0, 0, 0, 0, 1};
                if (reader.query(0, 1, 2, 4) == 0) val[3] = 1;
                if (reader.query(0, 1, 3, 4) == 0) val[2] = 1;
                if (reader.query(0, 2, 3, 4) == 0) val[1] = 1;
                if (reader.query(1, 2, 3, 4) == 0) val[0] = 1;
                setFive(res, val[0], val[1], val[2], val[3], val[4]);
                return 1;
            }
        }
        return -1;
    }
    int guessMajority(ArrayReader &reader) {
        vector<int> res;
        int more = firstFive(reader, res);
        int less = (more == 1 ? 0 : 1);
        int bas[3], basn = 0, nbas = -1;
        int num[2] = {0, 0};
        for (int i = 0; i < 5; i++) {
            if (res[i] == more) {
                bas[basn] = i;
                if (basn != 2) basn++;
                num[more]++;
            } else {
                num[less]++;
                nbas = i;
            }
        }

        int len = reader.length();
        for (int i = 5; i < len; i++) {
            if (reader.query(bas[0], bas[1], bas[2], i) == 4) num[more]++;
                else num[less]++, nbas = i;
        }
        
        if (num[less] == num[more]) return -1;
        if (num[less] > num[more]) return nbas;
        return bas[0];
    }
};