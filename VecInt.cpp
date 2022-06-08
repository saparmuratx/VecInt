#include "VecInt.hpp"

//
size_t VecInt::numOfCopies;

// copy constructor
VecInt::VecInt(const VecInt &other) : data(new int[other.cp]), sz(other.sz), cp(other.cp) {
    for (size_t i = 0; i < sz; i++) {
        data[i] = other.data[i];
        numOfCopies++;
    }
}

// move constructor
VecInt::VecInt(VecInt &&other) : data(other.data), sz(other.sz), cp(other.cp) {
    other.data = nullptr;
    other.sz = 0;
    other.cp = 0;
}

// move assigment operator
VecInt &VecInt::operator=(VecInt &&other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        sz = other.sz;
        cp = other.cp;
        other.data = nullptr;
        other.sz = 0;
        other.cp = 0;
    }
    return *this;
}

// assigment operator
VecInt &VecInt::operator=(const VecInt &other) {
    // not to assign VecInt to itself
    if (&other != this) {
        int *newData = new int[other.cp];

        for (size_t i = 0; i < other.sz; i++) {
            newData[i] = other.data[i];
            numOfCopies++;
        }

        delete[] data;

        cp = other.cp;
        sz = other.sz;
        data = newData;
    }
    return *this;
}

// pushBack()
void VecInt::pushBack(int x) {
    //it's full increase capacity by 2
    if (cp == sz) {
        cp = (cp == 0) ? 1 : cp * 2;
        int *newValue = new int[cp];
        for (size_t i = 0; i < sz; i++) {
            newValue[i] = data[i];
        }
        delete[] data;
        this->data = newValue;
    }
    // push back
    this->data[sz++] = x;
}

//comparison: equal operator
bool operator==(const VecInt &a, const VecInt &b) {
    if (a.size() != b.size()) return false;

    // if sizes are equal compare one by one
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}
// comparison: not equal operator
bool operator!=(const VecInt &a, const VecInt &b) {
    //reuse
    return !(a == b);
}