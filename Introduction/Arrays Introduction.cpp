#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];  // Declare an array of size n

    // Read the elements into the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print the elements in reverse order
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}
