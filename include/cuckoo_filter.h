#ifndef __CUCKOO_FILTER_H__
#define __CUCKOO_FILTER_H__

#include <map>
#include <memory>
#include <random>

typedef char fingerprint_t;
// typedef int fingerprint_t;
typedef long long int index_t;
typedef unsigned long element_t;
const fingerprint_t INF = -1;

// FIXME: just enable contineous addresses
const int bucket_size = 4;

// #define LOG

class Bucket {
private:
    fingerprint_t data_[bucket_size];
    bool valid_[bucket_size];
    int leftmost_available;

public:
    Bucket() {
        for (int i = 0; i < bucket_size; ++i) {
            data_[i] = INF;
            valid_[i] = false;
        }
        leftmost_available = 0;
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
        // return delete_(data_[0]);
        return delete_(data_[rand() % bucket_size]);
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

// #define INF 0
class CuckooFilter {
private:
    index_t filter_size;
    Bucket* filter;

public:
    bool cu_search(element_t val);
    bool cu_delete(element_t val);
    bool cu_insert(element_t val);
    double get_loadfactor(unsigned long long inserted_cnt);

    index_t _hash(element_t val);
    fingerprint_t _get_fingerprint(element_t val);

    CuckooFilter(index_t filter_size_) {
        filter_size = filter_size_;
        // filter = std::make_shared<fingerprint_t>(new fingerprint_t[filter_size]());
        filter = new Bucket[filter_size + 1]();
    }
    ~CuckooFilter() {
        delete [] filter;
    }
};


#endif /* __CUCKOO_FILTER_H__ */