#ifndef __CUCKOO_FILTER_H__

#include <map>

#define LOG
const char INF = 0;



extern int filter_size;

int cu_search(char filter[], int val);
int cu_delete(char filter[], int val);
int cu_insert(char filter[], int val);

bool has_visited(const std::map<int, bool>& vis, char footprint);
char get_footprint(int val);
int hash(int val);
double get_loadrate(char filter[]);

#endif /* __CUCKOO_FILTER_H__ */