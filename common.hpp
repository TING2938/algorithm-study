#ifndef __COMMON_LEARN_HEADER__
#define __COMMON_LEARN_HEADER__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) 
{
    os << '{';
    if (!vec.empty()) {
        os << vec[0];
    }
    for (int i = 1; i < vec.size(); i++) {
        os << ", " << vec[i];
    }
    os << '}';
    return os;
}


#endif // !__COMMON_LEARN_HEADER__
