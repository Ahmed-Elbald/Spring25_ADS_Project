#ifndef PAIR_H
#define PAIR_H
template <typename T1, typename T2>
class pair {
public:
    T1 first;
    T2 second;

    // Default constructor
    pair();

    // Parameterized constructor
    pair(const T1& first, const T2& second);

    // Copy constructor
    pair(const pair<T1, T2>& other);

    // Assignment operator
    pair<T1, T2>& operator=(const pair<T1, T2>& other);
};

/**
 *  Documentation *

 */

/*
 * pair()
 *
 * Preconditions:
 * - None.
 *
 * Postconditions:
 * - A pair object is created with default-initialized values.
 */

/**
 * pair(const T1& first, const T2& second)
 *
 * Preconditions:
 * - first must be a valid object of type T1.
 * - second must be a valid object of type T2.
 *
 * Postconditions:
 * - A pair object is created with the given first and second values.
 */

/**
 * pair(const Pair<T1, T2>& other)
 *
 * Preconditions:
 * - other must be a valid pair object.
 *
 * Postconditions:
 * - A new pair object is created as a copy of other.
 */

/**
 * pair<T1, T2>& operator=(const Pair<T1, T2>& other)
 *
 * Preconditions:
 * - other must be a valid pair object.
 *
 * Postconditions:
 * - The current pair object is assigned the values of other.
 * - Returns a reference to the current object.
 */

#endif // PAIR_H
