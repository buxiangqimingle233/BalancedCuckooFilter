#ifndef __CUCKOO_FILTER_H__
#define __CUCKOO_FILTER_H__

#include <map>
#include <memory>

typedef char fingerprint_t;
typedef long long int index_t;
typedef int element_t;
const fingerprint_t INF = 0;
// #define LOG

// #define INF 0
class CuckooFilter {
private:
    index_t filter_size;
    // std::shared_ptr<fingerprint_t> filter;
    fingerprint_t* filter;

public:
    bool cu_search(element_t val);
    bool cu_delete(element_t val);
    bool cu_insert(element_t val);
    double get_loadrate();

    bool _has_visited(const std::map<index_t, bool>& vis, fingerprint_t fingerprint);
    index_t _hash(element_t val);
    fingerprint_t _get_fingerprint(element_t val);

    CuckooFilter(index_t filter_size_) {
        filter_size = filter_size_;
        // filter = std::make_shared<fingerprint_t>(new fingerprint_t[filter_size]());
        filter = new fingerprint_t[filter_size + 1]();
    }
    ~CuckooFilter() {
        delete [] filter;
    }
};

// extern int filter_size;


#endif /* __CUCKOO_FILTER_H__ */