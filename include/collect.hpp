#ifndef __COLLECT_H__
#define __COLLECT_H__


#include <set>
#include "utils.h"
#include <memory>

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

//To make the compiler happy ... 
class CntAnalyzer;
static std::shared_ptr<CntAnalyzer> ptr(nullptr);

class CntAnalyzer {

private:
    int cnt;
    int sum;
    
public:
    static std::shared_ptr<CntAnalyzer> get_analyzer() {
        if (ptr != nullptr) {
            return ptr;
        } else {
            ptr = std::make_shared<CntAnalyzer>();
            return ptr;
        }
    }

    void add_sample(int sample) {
        sum += sample;
        cnt++;
    }

    double get_average() {
        return static_cast<double>(sum) / static_cast<double>(cnt);
    }

    CntAnalyzer(): cnt(0),sum(0) { }
};



#endif