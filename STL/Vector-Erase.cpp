#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int pos;
    cin >> pos;

    v.erase(v.begin() + (pos - 1)); // Erase the element at the specified position

    int start, end;
    cin >> start >> end;

    v.erase(v.begin() + (start - 1), v.begin() + (end - 1)); // Erase the range of elements

    cout << v.size() << endl; // Print the size of the updated vector

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // Print the elements of the updated vector
    }

    return 0;
}
