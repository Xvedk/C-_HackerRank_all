#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // Calculate lengths of strings
    int len1 = s1.size();
    int len2 = s2.size();

    // Concatenate strings
    string s3 = s1 + s2;

    // Swap the first characters of s1 and s2
    swap(s1[0], s2[0]);

    // Print the results
    cout << len1 << " " << len2 << endl;
    cout << s3 << endl;
    cout << s1 << " " << s2 << endl;

    return 0;
}
