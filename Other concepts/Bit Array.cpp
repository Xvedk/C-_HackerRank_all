int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N, S, P, Q;
    cin >> N >> S >> P >> Q;
    int modulo = 1u << 31;
    long int current;
    long int previous = S % modulo;
    int count = 1;
    for (int i = 1; i < N; i++) {
        current = (previous*P+Q) % modulo;
        if (current == previous)
            break;
        previous = current;
        count++;
    }
    cout << count << endl;
    return 0;
}
