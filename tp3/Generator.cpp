#include "Generator.hpp"

Generator::Generator(int n) : original(n) { mult=0; }

int Generator::operator()() {
    return mult += original;
}