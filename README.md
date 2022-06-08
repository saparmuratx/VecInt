# VecInt
Simple std::vector&lt;int> implementation in C++

Compile and Run:
----------------    
    to compile:
    $ make
    to run:
    $ ./main

Constructors:
-------------
    default contructor:
    VecInt a; // empty vector
    
    constructor with size and initial value:
    VecInt a(2); // a = {0 , 0}
    VecInt a(3, 9); // a = {9, 9, 9}

    initializer list constructor:
    VecInt a = {1, 2, 3};
    
    copy/move contructor:
    VecInt a = {1, 2, 3};
    VecInt b(a); 
    
Operators:
----------    
    = // assignment operator
    [] // subscript operator
    == // equal operator
    != // not equal operator

Functions:
----------
    size()
    begin()
    end()

Compatible with STL functions:
------------------------------
    sort()
    reverse()