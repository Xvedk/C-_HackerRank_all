class Matrix
{
public:
    vector<vector<int>> a;

    Matrix& operator+(const Matrix& r)
    {
        if (a.size() == r.a.size())
        {
            for (size_t i = 0; i < a.size(); ++i)
            {
                auto& ai = a[i];
                const auto& ri = r.a[i];
                if (ai.size() == ri.size())
                {
                    for (size_t j = 0; j < ai.size(); ++j)
                    {
                        ai[j] += ri[j];
                    }

                }
            }
        }
        return *this;
    }
};
