/*Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

Example 3:

Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]

Example 4:

Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        stack<pair<int,int>>st;
        intervals.push_back(newInterval);
        if(newInterval.size()==0){
            return res;
        }
        sort(intervals.begin(),intervals.end());
        st.push({intervals[0][0],intervals[0][1]});
            for(int i=1;i<intervals.size();i++){
                pair<int,int>t = st.top();
                if(t.second<intervals[i][0]){
                    st.push({intervals[i][0],intervals[i][1]});
                }
                else if(t.second<intervals[i][1]){
                    t.second=intervals[i][1];
                    st.pop();
                    st.push(t);
                }
            }
    
        while(!st.empty()){
            pair<int,int>tp=st.top();
            st.pop();
            res.push_back({tp.first,tp.second});
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
