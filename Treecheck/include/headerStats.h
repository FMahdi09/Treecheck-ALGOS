#ifndef HEADERSTATS_H_INCLUDED
#define HEADERSTATS_H_INCLUDED

#include <limits>

struct nodeStats{

    int depth = 1;
    int maxKey = 0;
    int minKey = std::numeric_limits<int>::max();
    int total = 0;
    int counter = 0;
    bool AVL = true;

} typedef nodeStats;


#endif // HEADERSTATS_H_INCLUDED
