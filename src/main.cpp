#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <set>
#include "cuckoo_filter.h"
#include "collect.h"

int filter_size = 0;

int main(int argc, char* argv[]) {

    if (argc < 3) {
        std::cerr << "Please provide sufficient parameters" << std::endl;
        return 1;
    }

    filter_size = std::stoi(argv[1]);

    std::ifstream test_trace(argv[2]);
    if (!test_trace.is_open()) {
        std::cerr << "Cannot find tracefile: " << argv[2] << std::endl;
        return 1;
    }
    
    Collector collector;
    std::shared_ptr<char> filter(new char[filter_size]());

    std::string op_type;
    int value;
    while (test_trace >> op_type >> value) {
        if (op_type == "i") {
            int cu_res = cu_insert(filter.get(), value);
            collector.collect_insert(value, cu_res);
            // the filter is full
            if (!cu_res) {
                std::cout << "Filter needs rehashing, load rate is: " << get_loadrate(filter.get()) << std::endl;
                exit(1);
            }
        } else if (op_type == "s") {
            int cu_res = cu_search(filter.get(), value);
            collector.collect_search(value, cu_res);
        } else if (op_type == "d") {
            int cu_res = cu_delete(filter.get(), value);
            collector.collect_delete(value, cu_res);
        }
    }
    
}