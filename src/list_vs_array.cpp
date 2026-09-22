#include <cstddef>  // size_t
#include <cstdint>  // uint64_t
#include <iostream> // cout
#include <list>     // list
#include <random>   // mt19937_64
#include <vector>   // vector

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {

    // test here...
    std::mt19937_64 rng(0); // create random number generator with seed 0
    Timer timer;            // create the timer
    std::list<uint64_t> container; // create the list
    rng.seed(0); // reset random number

    timer.restart(); // start list test
    for (size_t i = 0; i < SIZE; ++i) { // fill the list
        container.push_back(rng()); } // with random numbers
    std::cout << timer.click<Timer::Micros>() << '\n'; // print time taken

    std::vector<uint64_t> vector; // vector test without reserve
    rng.seed(0); // reset random number
    timer.restart(); // start vector test
    for (size_t i = 0; i < SIZE; ++i) { // fill w
        vector.push_back(rng()); } // ran num
    std::cout << timer.click<Timer::Micros>() << '\n'; // print time taken

    std::vector<uint64_t> reservedVector; // vector test with reserve
    reservedVector.reserve(SIZE); // reserves memory for all values before inserting
    rng.seed(0); // reset random number
    timer.restart(); // start reserved vector test
    for (size_t i = 0; i < SIZE; ++i) { // fill the vector
        reservedVector.push_back(rng()); } // with random numbers
    std::cout << timer.click<Timer::Micros>() << '\n'; // print time taken

    timer.restart(); // start sum list test
    uint64_t sum = 0; 
    for (uint64_t x : container) {  // iterate over each element
        sum += x; } // add all values in the list
    std::cout << sum << '\n'; // print sum
    std::cout << timer.click<Timer::Micros>() << '\n'; // print time taken

    timer.restart(); // start sum vector without reserve
    uint64_t vectorSum = 0;
    for (uint64_t x : vector) { // iterate over each element
        vectorSum += x; }       // add all values in the vector
    std::cout << vectorSum << '\n'; // print sum
    std::cout << timer.click<Timer::Micros>() << '\n'; // print time taken

    timer.restart(); // start sum vector with reserve
    uint64_t reservedSum = 0;
    for (uint64_t x : reservedVector) { // iterate over each element
        reservedSum += x; }             // add all values in the vector
    std::cout << reservedSum << '\n'; // print sum
    std::cout << timer.click<Timer::Micros>() << '\n'; // print time taken

return 0; }