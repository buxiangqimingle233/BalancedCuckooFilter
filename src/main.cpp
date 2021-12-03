#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <set>
#include "cuckoo_filter.h"
#include "collect.h"

int main(int argc, char* argv[]) {

    if (argc < 3) {
        std::cerr << "Please provide sufficient parameters" << std::endl;
        return 1;
    }

    index_t filter_size = std::stoi(argv[1]);

    std::ifstream test_trace(argv[2]);
    if (!test_trace.is_open()) {
        std::cerr << "Cannot find tracefile: " << argv[2] << std::endl;
        return 1;
    }
    
    Collector collector;
    CuckooFilter cuckoo(filter_size);

    std::string op_type;
    element_t value;
    while (test_trace >> op_type >> value) {
        if (op_type == "i") {
            bool cu_res = cuckoo.cu_insert(value);
            collector.collect_insert(value, cu_res);
            // the filter is full
            if (!cu_res) {
                std::cout << "Filter needs rehashing, load rate is: " << cuckoo.get_loadrate() << std::endl;
                exit(1);
            }
        } 

        else if (op_type == "s") {
            bool cu_res = cuckoo.cu_search(value);
            collector.collect_search(value, cu_res);
        } 
        
        else if (op_type == "d") {
            bool cu_res = cuckoo.cu_delete(value);
            collector.collect_delete(value, cu_res);
        }
    }
    
    std::cout << "fpr: " << collector.get_fpr() << std::endl;
}