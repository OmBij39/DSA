#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(){
    vector<int> digits(5, 0);
    cout<<"Enter Values: ";
    for (int i = 0; i < digits.size(); i++)
    {
        cin>>digits[i];
    }
    Solution sol;
    vector<int> result = sol.plusOne(digits);
    cout << "Result after plus one: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}