#ifndef __COLLECT_H__
#define __COLLECT_H__


#include <set>
#include "cuckoo_filter.h"

class Collector {

private:
    std::set<element_t> ground_truth;
    index_t search_event_counter;
    index_t false_positive_counter;

public:
    void collect_insert(element_t val, bool cu_res);
    void collect_search(element_t val, bool cu_res);
    void collect_delete(element_t val, bool cu_res);
    double get_fpr();

    Collector() {
        search_event_counter = false_positive_counter = 0;
        ground_truth = std::set<element_t>();
    }
};

#endif