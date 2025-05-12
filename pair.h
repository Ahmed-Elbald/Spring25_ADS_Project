#ifndef PAIR_H
#define PAIR_H

namespace custom {
    template <typename T1, typename T2>
    class pair {
    public:
        T1 first;
        T2 second;

        // Default constructor
        pair() = default;

        // Parameterized constructor
        pair(const T1& first, const T2& second) : first(first), second(second) {};

        // Copy constructor
        pair(const pair<T1, T2>& other) : first(other.first), second(other.second) {};

        // Assignment operator
        pair<T1, T2>& operator=(const pair<T1, T2>& other) {
            if (this != &other) {
                first = other.first;
                second = other.second;
            }
            return *this;
        };
    };
}

#endif // PAIR_H
