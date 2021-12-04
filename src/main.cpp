#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include "cuckoo_filter.h"
#include "collect.h"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Please provide sufficient parameters" << std::endl;
        return 1;
    }

    index_t filter_size = std::stoi(argv[1]);
    
    Collector collector;
    CuckooFilter cuckoo(filter_size);

    std::mt19937_64 val_gen;
    std::vector<element_t> inserted_values;

    unsigned long long inserted_cnt = 0;
    std::cout << std::fixed << std::setprecision(8);
    // Testing load rates
    while (true) {
        element_t value = val_gen();
        inserted_values.push_back(value);
        bool cu_res = cuckoo.cu_insert(value);
        collector.collect_insert(value, cu_res);
        if (!cu_res) {
            std::cout << cuckoo.get_loadfactor(inserted_cnt) << std::endl;
            break;
        }
        inserted_cnt++;
    }

    size_t len = inserted_values.size();
    // inserted_values.clear();
    for (auto _ = 0; _ < len; ++_) {
        inserted_values.push_back(val_gen());
    }

    for (auto it: inserted_values) {
        bool cu_res = cuckoo.cu_search(it);
        collector.collect_search(it, cu_res);        
    }

    std::cout << "fpr: " << collector.get_fpr() << std::endl;

    return 0;
}