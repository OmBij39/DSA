# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);
        
        for (int d = 0; d < m + n - 1; ++d) {
            if (d % 2 == 0) {
                // Traverse upwards
                int r = min(d, m - 1);
                int c = d - r;
                while (r >= 0 && c < n) {
                    result.push_back(mat[r][c]);
                    --r;
                    ++c;
                }
            } else {
                // Traverse downwards
                int c = min(d, n - 1);
                int r = d - c;
                while (c >= 0 && r < m) {
                    result.push_back(mat[r][c]);
                    ++r;
                    --c;
                }
            }
        }
        
        return result;
    }
};

int main() {
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter matrix values row-wise:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    Solution sol;
    vector<int> result = sol.findDiagonalOrder(mat);
    
    cout << "Diagonal Traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}