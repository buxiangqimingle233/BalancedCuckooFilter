#include <iostream>
#include <algorithm>
#include <memory>
#include <map>
#include "cuckoo_filter.h"
#include "xxhash.h"

int cu_search(char filter[], int val) {
    char footprint = get_footprint(val);
    int h1 = hash(val);
    int h2 = hash(val) ^ hash(footprint);
    if (filter[h1] == footprint) {
        return h1;
    } else if (filter[h2] == footprint) {
        return h2;
    } else {
        return -1;
    }
}


int cu_delete(char filter[], int val) {
    char footprint = get_footprint(val);
    int h1 = hash(val);
    int h2 = hash(val) ^ hash(footprint);
    if (filter[h1] == footprint) {
#ifdef LOG
        std::cout << "Delete: Factor " << val << " from h1 index " << h1 << std::endl;
#endif
        filter[h1] = INF;
        return val;
    } else if (filter[h2] == footprint) {
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


int cu_insert(char filter[], int val) {
    char footprint = get_footprint(val);
    int h1 = hash(val);
    int h2 = hash(val) ^ hash(footprint);

    if (filter[h1] == INF) {
        filter[h1] = footprint;
#ifdef LOG
        std::cout << "Insertion: Factor " << val << " is inserted to " << h1 << std::endl;
#endif
    } else if (filter[h2] == INF) {
        filter[h2] = footprint;
#ifdef LOG
        std::cout << "Insertion: Factor " << val << " is inserted to " << h2 << std::endl;
#endif
    } else {
        // kickout h2
        std::map<int, bool> vis;
        char val_to_insert = footprint;
        int idx_to_insert = h2;
        while (filter[idx_to_insert] != INF && !has_visited(vis, idx_to_insert)) {
            vis[idx_to_insert] = true;
            int idx_evict = idx_to_insert ^ hash(filter[idx_to_insert]);
            std::swap(val_to_insert, filter[idx_to_insert]);
            idx_to_insert = idx_evict;
        }

        if (has_visited(vis, idx_to_insert)) {
#ifdef LOG
            std::cerr << "Insertion: Failed! Factor " << val_to_insert << " has cycled evicting" << std::endl;
#endif
            return false;
        }

        filter[idx_to_insert] = val_to_insert;
    }
    return true;
}

double get_loadrate(char filter[]) {
    int load_cnt = 0;
    for (int i = 0; i < filter_size; ++i) {
        load_cnt += filter[i] != INF;
    }
    return static_cast<double>(load_cnt) / static_cast<double>(filter_size);
}

bool has_visited(const std::map<int, bool>& vis, char footprint) {
    auto itr = vis.find(footprint);
    if (itr == vis.end()) {
        return false;
    } else {
        return itr->second;
    }
}

char get_footprint(int val) {
    return (val & 0xf) | ((val & 0xff0) >> 4);
}

int hash(int val) {
    XXH32_hash_t hash = XXH32(&val, sizeof(int), 1234) % filter_size;
    return static_cast<int>(hash);
}