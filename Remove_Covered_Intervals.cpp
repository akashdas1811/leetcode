/*Given a list of intervals, remove all intervals that are covered by another interval in the list.

Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1

Example 3:

Input: intervals = [[0,10],[5,12]]
Output: 2

Example 4:

Input: intervals = [[3,10],[4,10],[5,11]]
Output: 2

Example 5:

Input: intervals = [[1,2],[1,4],[3,4]]
Output: 1

 

Constraints:

    1 <= intervals.length <= 1000
    intervals[i].length == 2
    0 <= intervals[i][0] < intervals[i][1] <= 10^5
    All the intervals are unique.
*/
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        stack<pair<int,int>>st;
        if(intervals.size()==0){
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& x, const auto& y){
            return x[0] != y[0] ? x[0] < y[0] : x[1] > y[1];
        });
        int count=0, max_second = intervals[0][1];
        for (int i=1;i<intervals.size();i++) {
            if (intervals[i][1] <= max_second) {
                count++;
            }
            max_second=max(max_second,intervals[i][1]);
        }
        return intervals.size()-count;
    }
};
