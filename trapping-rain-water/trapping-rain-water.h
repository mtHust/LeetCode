#ifndef TRAPPINGRAINWATER_H
#define TRAPPINGRAINWATER_H
/* https://oj.leetcode.com/problems/trapping-rain-water/
Trapping Rain Water Total Accepted: 26654 Total Submissions: 89756 My Submissions Question Solution
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

http://www.leetcode.com/wp-content/uploads/2012/08/rainwatertrap.png

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Hide Tags Array Stack Two Pointers

*/

class Solution {
public:
    int trap(int A[], int n) {

        int ret = 0;
        if(n<3)
        {
            return ret;
        }

        int max = 0;
        for(int i=1; i<n; i++)
        {
            if(A[max] < A[i])
            {
                max = i;
            }
        }

        int maxL=0;
        for(int i=1; i<max; ++i)
        {
            if(A[maxL] < A[i])
                maxL = i;
            else
                ret += A[maxL] - A[i];
        }

        int maxR = n-1;
        for(int i=n-2; i>max; --i)
        {
            if(A[maxR] < A[i])
                maxR = i;
            else
                ret += A[maxR] - A[i];
        }

        return ret;
    }
};

void test_trapping_rain_water(){
    Solution solv;
    int A[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    solv.trap(A, 12);
}

#endif // TRAPPINGRAINWATER_H
