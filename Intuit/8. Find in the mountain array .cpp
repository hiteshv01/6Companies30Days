/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &Arr) 
    {
          int left = 0 ;
          int right = Arr.length() - 1;
        // Find the peak index
        while (left < right)
        {    
            int mid = left + (right - left) / 2;
            if (Arr.get(mid) < Arr.get(mid + 1))
            {
                left = mid + 1;
            } 
            else
            { 
                right = mid;
            }
        }
        
        
        int peak = left;
        // Binary search on increasing subarray
        left = 0;
        right = peak;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (Arr.get(mid) < target) 
            {
                left = mid + 1;
            } 
            else if (Arr.get(mid) > target) 
            { 
                right = mid - 1;
            } 
            else
            {
                return mid;
            }
        }
        
        // Binary search on decreasing subarray
        left = peak;
        right = Arr.length() - 1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (Arr.get(mid) < target)
            {
                right = mid - 1;
            } 
            else if (Arr.get(mid) > target) 
            { 
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        
        
        return -1;
    }
};