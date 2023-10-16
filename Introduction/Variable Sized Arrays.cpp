#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> variableArrays;

    // Read variable-length arrays
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> arr(k);
        for (int j = 0; j < k; j++) {
            cin >> arr[j];
        }
        variableArrays.push_back(arr);
    }

    // Process queries
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << variableArrays[x][y] << endl;
    }

    return 0;
}
