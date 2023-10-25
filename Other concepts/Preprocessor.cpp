#define INF 1000000000

#define FUNCTION(f, comp) \
        void f(int& a, int b) \
        { if (b comp a) a = b; }

#define io(v) \
    cin >> v

#define toStr(x) #x

#define foreach(v, i) \
    for (size_t i = 0; i < v.size(); ++i)
