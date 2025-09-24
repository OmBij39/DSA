#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return 0;

        int maxIndex = 0;
        int maxValue = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxIndex = i;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i != maxIndex && nums[i] * 2 > maxValue) {
                return -1;
            }
        }

        return maxIndex;
        
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
    int dominantIdx = sol.dominantIndex(nums);
    if (dominantIdx != -1) {
        cout << "Dominant Index: " << dominantIdx << endl;
    } else {
        cout << "No Dominant Index found." << endl;
    }
}