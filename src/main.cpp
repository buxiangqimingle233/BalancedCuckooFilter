#include <iostream>
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

    // std::string op_type;
    // element_t value;
    // while (test_trace >> op_type >> value) {
    //     if (op_type == "i") {
    //         bool cu_res = cuckoo.cu_insert(value);
    //         collector.collect_insert(value, cu_res);
    //         // the filter is full
    //         if (!cu_res) {
    //             std::cout << "Filter needs rehashing, load rate is: " << cuckoo.get_loadfactor() << std::endl;
    //             exit(1);
    //         }
    //     } 

    //     else if (op_type == "s") {
    //         bool cu_res = cuckoo.cu_search(value);
    //         collector.collect_search(value, cu_res);
    //     } 
        
    //     else if (op_type == "d") {
    //         bool cu_res = cuckoo.cu_delete(value);
    //         collector.collect_delete(value, cu_res);
    //     }
    // }
    
    // std::cout << "fpr: " << collector.get_fpr() << std::endl;

    return 0;
}