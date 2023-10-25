template<typename T>
class AddElements
{
    T t_;
public:
    AddElements(const T& t) : t_(t)
    {}

    T add(const T& r) const
    {
        return t_ + r;
    }

    T concatenate(const T& r) const
    {
        return t_ + r;
    }
};
