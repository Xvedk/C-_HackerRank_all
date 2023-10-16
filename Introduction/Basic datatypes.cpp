#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int integer;
    long long_num;
    char character;
    float float_num;
    double double_num;

    // Reading values
    scanf("%d %ld %c %f %lf", &integer, &long_num, &character, &float_num, &double_num);

    // Printing values with formatting
    printf("%d\n", integer);
    printf("%ld\n", long_num);
    printf("%c\n", character);
    printf("%.3f\n", float_num);
    printf("%.9lf\n", double_num);

    return 0;
}
