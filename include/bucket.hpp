#include "utils.h"

template<int bucket_size>
class Bucket {
private:
    fingerprint_t data_[bucket_size];
    bool valid_[bucket_size];
    int evicted_idx;

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
        evicted_idx = (evicted_idx + 1) % bucket_size;
        return delete_(data_[evicted_idx]);
        // return delete_(data_[0]);
        // return delete_(data_[rand() % bucket_size]);
    }

    bool empty() {
        for (int i = 0; i < bucket_size; ++i) {
            if (valid_[i]) {
                return false;
            }
        }
        return true;
    }
};