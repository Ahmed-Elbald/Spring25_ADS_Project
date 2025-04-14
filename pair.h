#ifndef PAIR_H
#define PAIR_H
template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    // Default constructor
    Pair();

    // Parameterized constructor
    Pair(const T1& first, const T2& second);

    // Copy constructor
    Pair(const Pair<T1, T2>& other);

    // Assignment operator
    Pair<T1, T2>& operator=(const Pair<T1, T2>& other);
};


#endif // PAIR_H
