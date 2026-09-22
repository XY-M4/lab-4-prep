#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {

    assert(scale >= 1); // validate sclae
    uint64_t result = 0; // store expanded result
    for (size_t i = 0; i < 64; ++i) { // go through each bit in input
        uint64_t newPosition = i * static_cast<uint64_t>(scale); // find where this bit should go after expanding
        if (newPosition >= 64) { // stop if bit would go past 64 bits
            break; }
        if ((input & (1ULL << i)) != 0) { // check if the current input bit is 1
            result |= (1ULL << newPosition); } // place bit in new position
    }
return result; } // return expanded value

int main() { 
    // test examples from lab
    assert(expand(0b1111ULL, 3) == 0b001001001001ULL);
    assert(expand(0b0101ULL, 2) == 0b00010001ULL);
    assert(expand(0b1011ULL, 1) == 0b1011ULL);    // test scale 1
    assert(expand(0ULL, 4) == 0ULL); // test zero input
    assert(expand(0b11ULL, 64) == 0b1ULL); // test truncation
return 0; }