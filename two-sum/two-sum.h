#ifndef TWOSUM_H
#define TWOSUM_H

#include<iostream>

#include <algorithm>
#include <vector>
using namespace std;

#define TWO_SUM_SOLVE_1 0
#define TWO_SUM_SOLVE_2 1

#if TWO_SUM_SOLVE_1
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {

        int sz = numbers.size();
        Solution::pData = &numbers;

        vector<int> inds(sz);
        for(int i=0; i<sz; ++i){
            inds[i] = i;
        }

        std::sort(inds.begin(), inds.end(), cmpfunc);

        int ind1 = 0;
        int ind2 = sz - 1;
        bool bfind = false;

        while( ind1<ind2 ){
            int sum = numbers[inds[ind1]] + numbers[inds[ind2]];
            if(sum<target){
                ++ind1;
            }else if(sum>target){
                --ind2;
            }else{
                bfind = true;
                break;
            }
        }

        vector<int> data;
        if(bfind){
            data.push_back(min(inds[ind1], inds[ind2])+1);
            data.push_back(max(inds[ind1], inds[ind2])+1);
        }

        return data;
    }
private:
    static vector<int> *pData;
    static bool cmpfunc(const int &i, const int &j){
                return (*Solution::pData)[i] < (*Solution::pData)[j];
            }
};
vector<int> *Solution::pData = 0;
#endif

#ifdef TWO_SUM_SOLVE_2
#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> data;
        std::map<int, int> mnum;
        int sz = numbers.size();

        for(int i=0; i<sz; ++i){
            mnum.insert(make_pair(numbers[i], i));
        }
        for(int i=0; i<sz; ++i){
            int num2 = target - numbers[i];
            std::map<int, int>::iterator it = mnum.find(num2);
            if(it!=mnum.end() && i!=it->second){
                data.push_back(std::min(i, it->second ) + 1);
                data.push_back(std::max(i, it->second ) + 1);
                break;
            }
        }

        return data;
    }
};
#endif

void test_two_sum(){
    vector<int> numbers;
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(4);

    int target = 6;

    std::cout<<"Before"<<std::endl;
    for(int i=0; i<numbers.size(); ++i){
        std::cout<<numbers[i]<<std::endl;
    }

    Solution solv;
    vector<int> data = solv.twoSum(numbers, target);

    std::cout<<"After"<<std::endl;
    for(int i=0; i<numbers.size(); ++i){
        std::cout<<numbers[i]<<std::endl;
    }

    std::cout<<"After2"<<std::endl;
    for(int i=0; i<data.size(); ++i){
        std::cout<<data[i]<<std::endl;
    }

}

#endif // TWOSUM_H
