#ifndef FINDMINIMUMINROTATEDSORTEDARRAY
#define FINDMINIMUMINROTATEDSORTEDARRAY
/* https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Find Minimum in Rotated Sorted Array Total Accepted: 26338 Total Submissions: 80570 My Submissions Question Solution
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Hide Tags Array Binary Search

*/
#include <vector>
using std::vector;

class Solution {
public:
    int findMin(vector<int> &num) {
        int nsize = num.size();
        if(nsize==0)
            return 0;
        int ileft = 0;
        int iright = nsize - 1;

        while(ileft<iright){
            int imid = (iright + ileft)/2;

            if(imid==ileft){
                if(num[imid]>num[iright]){
                    ileft = iright;
                }
                break;
            }

            if(num[ileft]<num[imid] && num[imid]<num[iright]){
                break;
            }

            if(num[ileft]<num[imid] && num[imid]>num[iright]){
                ileft = imid;
            }

            if(num[ileft]>num[imid] && num[imid]<num[iright]){
                iright = imid;
            }
        }

        return num[ileft];
    }
};

void test_find_minimum_in_rotated_sorted_array(){
    Solution solv;

    vector<int> num;

    num.push_back(2);
    num.push_back(3);
    num.push_back(1);

    solv.findMin(num);

}

#endif // FINDMINIMUMINROTATEDSORTEDARRAY

