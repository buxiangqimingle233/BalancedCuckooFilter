#ifndef __COLLECT_H__
#include <set>

class Collector {

private:
    std::set<int> ground_truth;
    int search_event_counter;
    int false_positive_counter;

public:
    void collect_insert(int val, bool cu_res);
    void collect_search(int val, bool cu_res);
    void collect_delete(int val, bool cu_res);
    double get_fpr();

    Collector() {
        search_event_counter = false_positive_counter = 0;
        ground_truth = std::set<int>();
    }
};

#endif