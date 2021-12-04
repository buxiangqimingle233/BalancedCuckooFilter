#ifndef __COLLECT_H__
#define __COLLECT_H__


#include <set>
#include "utils.h"


class Collector {

private:
    std::set<element_t> ground_truth;
    index_t search_event_counter;
    index_t false_positive_counter;

public:
    void collect_insert(element_t val, bool cu_res) {
        ground_truth.insert(val);
    };

    void collect_search(element_t val, bool cu_res) {
        search_event_counter += 1;
        bool gt_res = ground_truth.find(val) != ground_truth.end();
        false_positive_counter += (!gt_res && cu_res);       
    };

    void collect_delete(element_t val, bool cu_res) {
        ground_truth.erase(val);
    };

    double get_fpr() {
        return static_cast<double>(false_positive_counter) / static_cast<double>(search_event_counter);
    };

    Collector() {
        search_event_counter = false_positive_counter = 0;
        ground_truth = std::set<element_t>();
    }
};

#endif