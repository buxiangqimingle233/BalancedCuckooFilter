#include <cassert>
#include "utils.h"

template<int bucket_size>
class Bucket {
private:
    fingerprint_t data_[bucket_size];
    bool valid_[bucket_size];
    char evicted_idx;
#ifdef AWARE
    char last_evicted = 0;
#endif

public:
    Bucket() {
        for (int i = 0; i < bucket_size; ++i) {
            data_[i] = INF;
            valid_[i] = false;
        }
        evicted_idx = 0;
    }
    
    bool find(fingerprint_t val) {
        for (int i = 0; i < bucket_size; ++i) {
            if (valid_[i] && data_[i] == val) {
                return true;
            }
        }
        return false;
    }

    bool insert(fingerprint_t val) {
        for (int i = 0; i < bucket_size; ++i) {
            if (!valid_[i]) {
                data_[i] = val;
                valid_[i] = true;
                return true;
            }
        }
        return false;
    }

    fingerprint_t delete_(fingerprint_t val) {
        for (int i = 0; i < bucket_size; ++i) {
            if (valid_[i] && data_[i] == val) {
                valid_[i] = false;
                return data_[i];
            }
        }
        return INF;
    }

    fingerprint_t evict() {
        assert(full());
#ifdef RR
        evicted_idx = (evicted_idx + 1) % bucket_size;
#elif FIRST
        evicted_idx = 0;
#elif RANDOM
        evicted_idx = rand() % bucket_size;
#elif AWARE
        evicted_idx = rand() % bucket_size;
        if (evicted_idx == last_evicted) {
            evicted_idx = (evicted_idx + 1) % bucket_size;
        }
        last_evicted = evicted_idx;
#else
        evicted_idx = 0;
#endif
        return delete_(data_[evicted_idx]);
    }

    bool full() {
        for (int i = 0; i < bucket_size; ++i) {
            if (!valid_[i]) {
                return false;
            }
        }
        return true;
    }
};