#ifndef __CUCKOO_FILTER_H__
#define __CUCKOO_FILTER_H__

#include <map>
#include <memory>

typedef char footprint_t;
typedef long long int index_t;
typedef int element_t;
const footprint_t INF = 0;
#define LOG

// #define INF 0
class CuckooFilter {
private:
    index_t filter_size;
    // std::shared_ptr<footprint_t> filter;
    footprint_t* filter;

public:
    bool cu_search(element_t val);
    bool cu_delete(element_t val);
    bool cu_insert(element_t val);
    double get_loadrate();

    bool _has_visited(const std::map<index_t, bool>& vis, footprint_t footprint);
    index_t _hash(element_t val);
    footprint_t _get_footprint(element_t val);

    CuckooFilter(index_t filter_size_) {
        filter_size = filter_size_;
        // filter = std::make_shared<footprint_t>(new footprint_t[filter_size]());
        filter = new footprint_t[filter_size + 1]();
    }
    ~CuckooFilter() {
        delete [] filter;
    }
};

// extern int filter_size;


#endif /* __CUCKOO_FILTER_H__ */