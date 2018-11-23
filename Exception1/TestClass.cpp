//
// Created by devansh on 23/11/18.
//
#include "Member.cpp"


class TestClass {

    Member m1, m2, m3, m4;

public:

    /*Exception gets thrown during construction of object m3 because
     * throwException of class Member's constructor is set.
     * Object m4 is not constructed
     */

    TestClass() : m1(1), m2(2), m3(3, true), m4(4) {}
};