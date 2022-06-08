#ifndef VECINT_HPP
#define VECINT_HPP

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

#ifdef AUCA_DEBUG
#include <string>
#endif

class VecInt
{
    // field:
    // pointer to allocated space
    int *data;
    // size
    size_t sz;
    // capacity
    size_t cp;

public:
    static size_t numOfCopies;

    // iterators for begin() and end()
    using Iter = int *;
    using CIter = const int *;

    // default constructor
    VecInt() : data(nullptr), sz(0), cp(0) {}

    // constructor with size and initial value
    explicit VecInt(const std::size_t &size, const int &value = 0)
        : data(new int[size]), sz(size), cp(size)
    {
        for (size_t i = 0; i < sz; i++)
        {
            data[i] = value;
        }
    }

    // copy constructor
    VecInt(const VecInt &other);

    // move constructor
    VecInt(VecInt &&other);

    // initializer list constructor
    VecInt(std::initializer_list<int> initList) : VecInt()
    {
        for (auto e : initList)
        {
            pushBack(e);
        }
    }

    // destructor
    ~VecInt()
    {
        // to indicate number of released integers from heap
        // std::cout << "VecInt: " << sz << " integers released.\n";
        delete[] data;
    }

    // assigment operator
    VecInt &operator=(const VecInt &other);

    // move assigment operator
    VecInt &operator=(VecInt &&other) noexcept;

    // size of VecInt
    std::size_t size() const { return sz; }

    // iterator to begin
    Iter begin() { return data; }

    // iterator to end
    Iter end() { return data + sz; }

    // const iterator to begin
    CIter begin() const { return data; }

    // const iterator to end
    CIter end() const { return data + sz; }

    // const subscript operator
    const int &operator[](std::size_t index) const
    {
#ifdef AUCA_DEBUG
        if (index >= sz)
        {
            throw std::runtime_error("VecInt: incorrect index " + std::to_string(index));
        }
#endif
        return data[index];
    }

    // subscript operator
    int &operator[](std::size_t index)
    {
#ifdef AUCA_DEBUG
        if (index >= sz)
        {
            throw std::runtime_error("VecInt: incorrect index " + std::to_string(index));
        }
#endif
        return data[index];
    }

    // pushBack()
    void pushBack(int x);
};

#endif
// comparison operator
bool operator==(const VecInt &a, const VecInt &b);
// not equal operator
bool operator!=(const VecInt &a, const VecInt &b);