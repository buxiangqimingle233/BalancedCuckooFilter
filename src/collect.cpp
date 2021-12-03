#include <set>
#include <memory>
#include "collect.h"

void Collector::collect_insert(element_t val, bool cu_res) {
    ground_truth.insert(val);
}

void Collector::collect_search(element_t val, bool cu_res) {
    search_event_counter += 1;
    bool gt_res = ground_truth.find(val) != ground_truth.end();
    false_positive_counter += !gt_res && cu_res;
}

void Collector::collect_delete(element_t val, bool cu_res) {
    ground_truth.erase(val);
}

double Collector::get_fpr() {
    return static_cast<double>(false_positive_counter) / static_cast<double>(search_event_counter);
}