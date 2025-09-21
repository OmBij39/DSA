#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
    int n = nums.size();
    if (n == 0) return -1;

    int totalSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        totalSum += num;
    }

    int leftSum = 0;
    for (int i = 0; i < n; ++i) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}
};

int main(){
    vector<int> nums(5, 0);
    cout<<"Enter Values: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cin>>nums[i];
    }
    Solution sol;
    int pivot = sol.pivotIndex(nums);
    if (pivot != -1) {
        cout << "Pivot Index: " << pivot << endl;
    } else {
        cout << "No Pivot Index found." << endl;
    }
}