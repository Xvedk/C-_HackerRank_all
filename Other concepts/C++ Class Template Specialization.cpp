template<>
struct Traits<Color>
{
 public:
    static string name(int i)
    {
        if (i == (int) Color::red) return "red";
        if (i == (int) Color::green) return "green";
        if (i == (int) Color::orange) return "orange";
        return "unknown";
    }
};


template<>
struct Traits<Fruit>
{
 public:
    static string name(int i)
    {
        if (i == (int) Fruit::apple) return "apple";
        if (i == (int) Fruit::orange) return "orange";
        if (i == (int) Fruit::pear) return "pear";
        return "unknown";
    }
};
