#ifndef MERGEINTERVALS_H
#define MERGEINTERVALS_H

#include <algorithm>
#include <vector>
using namespace std;

// Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

bool PtFuncCompare(const Interval &a,const Interval& b){
    return (a.start < b.start);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> data;
        if(intervals.empty()){
            return data;
        }

        std::sort(intervals.begin(), intervals.end(), cmpobject);

        Interval now = intervals[0];
        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i].start <= now.end){
                now.end = std::max(now.end, intervals[i].end);
                continue;
            }

            data.push_back(now);

            now.start = intervals[i].start;
            now.end = intervals[i].end;

        }
        data.push_back(now);

        return data;
    }

    class cmpclass {
    public:
        bool operator() (const Interval &i, const Interval & j) {
            return (i.start<j.start);
        }
    } cmpobject;
};

#include <stdlib.h>
#include <iostream>

void test_merge_interval(){
    srand(0);

    vector<Interval> data;

//    data.push_back(Interval(1, 3));
//    data.push_back(Interval(2, 6));
//    data.push_back(Interval(8, 10));
//    data.push_back(Interval(15, 18));
//    data.push_back(Interval(4, 9));

    data.push_back(Interval(1, 4));
    data.push_back(Interval(2, 3));

//    for(int i=0; i<4; ++i){
//        int s = rand()%10;
//        int e = s + rand()%10;
//        data.push_back(Interval(s, e));
//    }

    std::cout<<"Before"<<std::endl;
    for(int i=0; i<data.size(); ++i){
        std::cout<<"["<<data[i].start<<","<<data[i].end<<"]"<<std::endl;
    }

    Solution sol;
    vector<Interval> data2 = sol.merge(data);

    std::cout<<"After"<<std::endl;
    for(int i=0; i<data.size(); ++i){
        std::cout<<"["<<data[i].start<<","<<data[i].end<<"]"<<std::endl;
    }

    std::cout<<"After2"<<std::endl;
    for(int i=0; i<data2.size(); ++i){
        std::cout<<"["<<data2[i].start<<","<<data2[i].end<<"]"<<std::endl;
    }
}

#endif // MERGEINTERVALS_H
