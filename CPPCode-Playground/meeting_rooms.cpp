// meeting room
// https://leetcode.com/problems/meeting-rooms-ii/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <algorithm>
#include <cmath>
 
class Solution {
public:
    struct EP {
        int val;
        bool isBegin;
    };

    int minMeetingRooms(vector<Interval>& intervals) {
        vector<EP> endPoints;
        for(int i = 0; i < intervals.size(); ++i) {
            Interval x = intervals[i];
            endPoints.push_back({x.start, true});
            endPoints.push_back({x.end, false});
        }
        sort(endPoints.begin(), endPoints.end(),
            [](EP& fr, EP& se) {
                return (fr.val < se.val) || (fr.val == se.val && !fr.isBegin);
            }
        );
        
        int count = 0;
        int maxi = 0;
        for(int i = 0; i < endPoints.size(); ++i) {
            EP x = endPoints[i];
            if (x.isBegin) {
                ++count;
                maxi = max(maxi, count);
            } else {
                --count;
            }
        }
        return maxi;
    }
};