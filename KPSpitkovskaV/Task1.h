//Структура для виведення степенів двійки
template<int n>
struct power
{
    static void print()
    {
        power<n - 1>::print();
        std::cout << (1 << n) << " ~ ";
    }
};

template<>
struct power<0>
{
    static void print()
    {
        std::cout << 1 << " ~ ";
    }
};
