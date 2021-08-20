/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

Link:https://leetcode.com/problems/trapping-rain-water/

*/
/*
In brute force, we iterate over the left and right parts again and again just to find the highest bar size upto that index. But, 
this could be stored. 
Voila, dynamic programming.

Algorithm

Find maximum height of bar from the left end upto an index i in the array left_max.
Find maximum height of bar from the right end upto an index i in the array right_max.
Iterate over the \text{height}height array and update ans:
Add min(left_max[i],right_max[i])−height[i] to ans

*/
int trap(vector<int>& height)
{
    if(height.empty())
        return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}
/*
Using 2 pointers:
Algorithm

Initialize \text{left}left pointer to 0 and right pointer to size-1
While \text{left}< left<right, do:
If \text{height[left]}height[left] is smaller than \text{height[right]}height[right]
If \text{height[left]} \geq \text{left\_max}height[left]≥left_max, update \text{left\_max}left_max
Else add \text{left\_max}-\text{height[left]}left_max−height[left] to \text{ans}ans
Add 1 to \text{left}left.
Else
If \text{height[right]} \geq \text{right\_max}height[right]≥right_max, update \text{right\_max}right_max
Else add \text{right\_max}-\text{height[right]}right_max−height[right] to \text{ans}ans
Subtract 1 from right.


*/
int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}