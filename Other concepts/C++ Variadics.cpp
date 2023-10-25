template<bool...digits>
int reversed_binary_value(...)
{
    //bool bits[] = { digits... };
    auto i = 0, r = 0;
    for (auto b : { digits... })
    {
        if (b) r |= 1 << i;
        i++;
    }
    return r;
}
