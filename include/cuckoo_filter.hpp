#ifndef __CUCKOO_FILTER_H__
#define __CUCKOO_FILTER_H__

#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <algorithm>
#include "utils.h"
#include "city.h"
#include "xxhash.h"
#include "bucket.hpp"

template<int bucket_size, int relocate_limit>
// #define INF 0
class CuckooFilter {
private:
    index_t filter_size;
    Bucket<bucket_size>* filter;

public:
    bool cu_search(element_t val) {
        fingerprint_t fingerprint = _get_fingerprint(val);
        index_t h1 = _hash(val);
        index_t h2 = h1 ^ _hash(fingerprint);
        if (filter[h1].find(fingerprint) || filter[h2].find(fingerprint)) {
            return true;
        } else {
            return false;
        }
    };

    bool cu_delete(element_t val) {
        fingerprint_t fingerprint = _get_fingerprint(val);
        index_t h1 = _hash(val);
        index_t h2 = h1 ^ _hash(fingerprint);
        if (filter[h1].delete_(fingerprint) != INF) {
#ifdef LOG
            std::cout << "Delete: Factor " << val << " from h1 index " << h1 << std::endl;
#endif
            return true;
        } else if (filter[h2].delete_(fingerprint) != INF) {
#ifdef LOG
            std::cout << "Delete: Factor " << val << " from h2 index " << h2 << std::endl;
#endif
            return true;
        } else {
            std::cerr << "Delete: Failed! Factor " << val << " has not been found" << std::endl;
            return false;
        }
    };

    bool cu_insert(element_t val) {
        fingerprint_t fingerprint = _get_fingerprint(val);
        index_t h1 = _hash(val);
        index_t h2 = h1 ^ _hash(fingerprint);

        if (cu_search(val)) {
            return true;
        }

        if (filter[h1].insert(fingerprint)) {
#ifdef LOG
            std::cout << "Insertion: Factor " << val << " is inserted to " << h1 << std::endl;
#endif
        } else if (filter[h2].insert(fingerprint)) {
#ifdef LOG
            std::cout << "Insertion: Factor " << val << " is inserted to " << h2 << std::endl;
#endif
        } else {
            // kickout h2
            fingerprint_t val_to_insert = fingerprint;
            index_t idx_to_insert = h2;
            int episode = 0;
            for (; episode < relocate_limit && !filter[idx_to_insert].insert(val_to_insert); episode++) {
                // Select an evictor and insert the present element
                fingerprint_t evictor = filter[idx_to_insert].evict();
                filter[idx_to_insert].insert(val_to_insert);

                val_to_insert = evictor;
                idx_to_insert = idx_to_insert ^ _hash(evictor);
            }

            if (episode >= relocate_limit) {
#ifdef LOG
                std::cerr << "Insertion: Failed! Factor " << val_to_insert << " has cycled evicting: " << vis.size() << std::endl;
#endif
                return false;
            } 
        }
        return true;
    };
    
    double get_loadfactor(unsigned long long inserted_cnt) {
        return static_cast<double>(inserted_cnt) / 
               static_cast<double>(filter_size * bucket_size);
    };

    index_t _hash(element_t val) {
        XXH32_hash_t hash = XXH64(&val, sizeof(element_t), 1234) % filter_size;
        // uint64 hash = CityHash64WithSeed(reinterpret_cast<const char*>(&val), sizeof(element_t), 1234) % filter_size;
        // std::cout << val << " " << hash << std::endl;
        return static_cast<index_t>(hash);        
    };
    
    fingerprint_t _get_fingerprint(element_t val) {
        return val;
        // return ((val & 0xf00) >> 8) | ((val & 0xf) << 4) | (val << 8);
        // XXH32_hash_t hash = XXH64(&val, sizeof(element_t), 1234);
        // return val & 0xff;
    };

    CuckooFilter(index_t filter_size_) {
        filter_size = filter_size_;
        filter = new Bucket<bucket_size> [filter_size + 1]();
    }
    ~CuckooFilter() {
        delete [] filter;
    }
};


#endif /* __CUCKOO_FILTER_H__ */