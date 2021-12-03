#include <iostream>
#include <algorithm>
#include <memory>
#include <map>
#include "cuckoo_filter.h"
#include "xxhash.h"

bool CuckooFilter::cu_search(element_t val) {
    fingerprint_t fingerprint = _get_fingerprint(val);
    index_t h1 = _hash(val);
    index_t h2 = _hash(val) ^ _hash(fingerprint);
    if (filter[h1] == fingerprint || filter[h2] == fingerprint) {
        return true;
    } else {
        return false;
    }
}


bool CuckooFilter::cu_delete(element_t val) {
    fingerprint_t fingerprint = _get_fingerprint(val);
    index_t h1 = _hash(val);
    index_t h2 = _hash(val) ^ _hash(fingerprint);
    if (filter[h1] == fingerprint) {
#ifdef LOG
        std::cout << "Delete: Factor " << val << " from h1 index " << h1 << std::endl;
#endif
        filter[h1] = INF;
        return val;
    } else if (filter[h2] == fingerprint) {
#ifdef LOG
        std::cout << "Delete: Factor " << val << " from h2 index " << h2 << std::endl;
#endif
        filter[h2] = INF;
        return val;
    } else {
        std::cerr << "Delete: Failed! Factor " << val << " has not been found" << std::endl;
        return -1;
    }
}


bool CuckooFilter::cu_insert(element_t val) {
    fingerprint_t fingerprint = _get_fingerprint(val);
    index_t h1 = _hash(val);
    index_t h2 = _hash(val) ^ _hash(fingerprint);

    if (cu_search(val)) {
        return true;
    }

    if (filter[h1] == INF) {
        filter[h1] = fingerprint;
#ifdef LOG
        std::cout << "Insertion: Factor " << val << " is inserted to " << h1 << std::endl;
#endif
    } else if (filter[h2] == INF) {
        filter[h2] = fingerprint;
#ifdef LOG
        std::cout << "Insertion: Factor " << val << " is inserted to " << h2 << std::endl;
#endif
    } else {
        // kickout h2
        std::map<index_t, bool> vis;
        fingerprint_t val_to_insert = fingerprint;
        index_t idx_to_insert = h2;
        while (filter[idx_to_insert] != INF && !_has_visited(vis, idx_to_insert)) {
            vis[idx_to_insert] = true;
            index_t idx_evict = idx_to_insert ^ _hash(filter[idx_to_insert]);
            std::swap(val_to_insert, filter[idx_to_insert]);
            idx_to_insert = idx_evict;
        }

        if (_has_visited(vis, idx_to_insert)) {
#ifdef LOG
            std::cerr << "Insertion: Failed! Factor " << val_to_insert << " has cycled evicting" << std::endl;
#endif
            return false;
        }

        filter[idx_to_insert] = val_to_insert;
    }
    return true;
}

double CuckooFilter::get_loadrate() {
    index_t load_cnt = 0;
    for (index_t i = 0; i < filter_size; ++i) {
        load_cnt += filter[i] != INF;
    }
    return static_cast<double>(load_cnt) / static_cast<double>(filter_size);
}

bool CuckooFilter::_has_visited(const std::map<index_t, bool>& vis, fingerprint_t fingerprint) {
    auto itr = vis.find(fingerprint);
    if (itr == vis.end()) {
        return false;
    } else {
        return itr->second;
    }
}

fingerprint_t CuckooFilter::_get_fingerprint(element_t val) {
    return (val & 0xf) | ((val & 0xff0) >> 4);
}

index_t CuckooFilter::_hash(element_t val) {
    XXH32_hash_t hash = XXH32(&val, sizeof(element_t), 1234) % filter_size;
    return static_cast<index_t>(hash);
}