/*
Input: rungs = [1,3,5,10], dist = 2
Output: 2
Explanation:
You currently cannot reach the last rung.
Add rungs at heights 7 and 8 to climb this ladder. 
The ladder will now have rungs at [1,3,5,7,8,10].

Input: rungs = [3,6,8,10], dist = 3
Output: 0
Explanation:
This ladder can be climbed without adding additional rungs.

Input: rungs = [3,4,6,7], dist = 2
Output: 1
Explanation:
You currently cannot reach the first rung from the ground.
Add a rung at height 1 to climb this ladder.
The ladder will now have rungs at [1,3,4,6,7].

link:https://leetcode.com/problems/add-minimum-number-of-rungs/

*/
class Solution {
public:
    
    int addRungs(vector<int>& rungs, int dist) {
        int count=0;
        
        //represents the previous height
        int prevHeight=0;
        int diff;
        for(int i=0;i<rungs.size();i++)
        {
            diff=rungs[i]-prevHeight;
            if(diff>dist)
            {
                //the number of rungs needed to be inserted
                count+=(diff)/dist;
                //if the diference is divided by dist with 0 remainder then count may count-1 are needed
                //for example  [4] dist=2 here , (4-0)/2 =2 but (4-0)%2 == 0 so count decreases (count-1) the ans is [2,4]
                if((diff)%dist==0)
                    count--;
            }
            prevHeight=rungs[i];
        }
        return count;
    }
};