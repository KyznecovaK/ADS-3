// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max_val = num;
    
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > max_val) {
            max_val = num;
        }
    }
    return max_val;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        length++;
    }
    
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    if (lbound > rbound || lbound < 2) {
        if (maxlen) *maxlen = 0;
        return 0;
    }
    
    unsigned int max_length = 0;
    unsigned int best_number = lbound;
    
    for (uint64_t num = lbound; num <= rbound; num++) {
        unsigned int length = collatzLen(num);
        
        if (length > max_length) {
            max_length = length;
            best_number = num;
        }
    }
    
    if (maxlen) {
        *maxlen = max_length;
    }
    
    return best_number;
}
