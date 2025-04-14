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
}

/**
 *  Documentation *

 */

/*
 * Pair()
 *
 * Preconditions:
 * - None.
 *
 * Postconditions:
 * - A Pair object is created with default-initialized values.
 */

/**
 * Pair(const T1& first, const T2& second)
 *
 * Preconditions:
 * - first must be a valid object of type T1.
 * - second must be a valid object of type T2.
 *
 * Postconditions:
 * - A Pair object is created with the given first and second values.
 */

/**
 * Pair(const Pair<T1, T2>& other)
 *
 * Preconditions:
 * - other must be a valid Pair object.
 *
 * Postconditions:
 * - A new Pair object is created as a copy of other.
 */

/**
 * Pair<T1, T2>& operator=(const Pair<T1, T2>& other)
 *
 * Preconditions:
 * - other must be a valid Pair object.
 *
 * Postconditions:
 * - The current Pair object is assigned the values of other.
 * - Returns a reference to the current object.
 */

#endif // PAIR_H
