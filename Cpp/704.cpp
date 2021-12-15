#include <iostream>
#include <vector>
#include <string>

using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    int middle;
    while(left<=right){
        middle = left + (right - left)/2;
        if(nums[middle]>target){
            right = middle - 1;
        }
        else if(nums[middle]<target){
            left = middle + 1;
        }
        else{
            return middle;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums {1, 3, 5, 7};
    int target = 9;
    int result;
    result = search(nums, target);
    cout << result << endl;
}