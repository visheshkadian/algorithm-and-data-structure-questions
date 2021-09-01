/*
link:https://leetcode.com/problems/array-nesting/

Input: nums = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
One of the longest sets s[k]:
s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}

this problem have different approach
*/

//using DFS
class Solution {
public:
     int arrayNesting(vector<int>& nums) {
        vector<vector<int>> v(nums.size());
        for(int i = 0; i<nums.size(); i++){
            v[i].push_back(nums[i]);
        }
        vector <bool> visited(nums.size(),false);
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(!visited[i])
                ans = max(ans,dfs(i,v,visited));
        }
        return ans;
    }
private:
    int dfs(int node, vector<vector<int>> &v,vector<bool> &visited){
        visited[node] = true;
        
        for(auto u : v[node])
            if(!visited[u])
                return 1+dfs(u,v,visited);
        return 1;
    }
};

//using visited array
int arrayNesting(vector<int>& A) {
        int res = 0, n = A.size();
        vector<bool> seen(n);
        for (int i: A) {
            int cnt = 0;
            while (!seen[i]) {
                seen[i] = true;
                cnt++;
                i = A[i];
            }
            res = max(res, cnt);
        }
        return res;
    }

//Approach #3 Without Using Extra Space [Accepted]
public class Solution {
    public int arrayNesting(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != Integer.MAX_VALUE) {
                int start = nums[i], count = 0;
                while (nums[start] != Integer.MAX_VALUE) {
                    int temp = start;
                    start = nums[start];
                    count++;
                    nums[temp] = Integer.MAX_VALUE;
                }
                res = Math.max(res, count);
            }
        }
        return res;
    }
}
