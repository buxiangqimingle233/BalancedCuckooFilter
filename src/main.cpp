#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include "cuckoo_filter.hpp"
#include "collect.h"

template<int bucket_size, int relocate_limit>
void test(index_t capacity) {

    Collector collector;
    CuckooFilter<bucket_size, relocate_limit> cuckoo(capacity);

    std::mt19937_64 val_gen;
    std::vector<element_t> inserted_values;

    unsigned long long inserted_cnt = 0;
    // Testing load rates
    while (true) {
        element_t value = val_gen();
        inserted_values.push_back(value);
        bool cu_res = cuckoo.cu_insert(value);
        collector.collect_insert(value, cu_res);
        if (!cu_res) {
            break;
        }
        inserted_cnt++;
    }

    // Testing false positive rates   
    size_t len = inserted_values.size();
    for (auto _ = 0; _ < len; ++_) {
        element_t value = val_gen();
        bool cu_res = cuckoo.cu_search(value);
        collector.collect_search(value, cu_res);
    }

    fprintf(stdout, "%lld %d %.8f %.8f\n", 
            capacity, bucket_size, cuckoo.get_loadfactor(inserted_cnt), collector.get_fpr());
    
    return;
}


int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Please provide sufficient parameters" << std::endl;
        return 1;
    }

    index_t filter_size = std::stoi(argv[1]);

    test< 2 , 250 > (filter_size);
    test< 4 , 250 > (filter_size);

    return 0;
}