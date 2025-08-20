/**
 * Author: mzhang2021
 * Description: Sorts vectors radially based on angles [0, 2pi).
 * For parallel vectors, larger magnitude come later.
 * Source: https://codeforces.com/blog/entry/72815
 */

#include "Point.h"

template<typename T>
bool half(const P<T> &p) {
    // DO NOT INCLUDE (0, 0)
    assert(p.x != 0 || p.y != 0);
    return p.y < 0 || (p.y == 0 && p.x < 0);
    // Use if you want the polar sort to start from Point V
    // return cross(v,p) < 0 || (cross(v,p) == 0 && dot(v,p) < 0);
}

template<typename T>
bool comp(const P<T> &p, const P<T> &q) {
    return half(p) == half(q) ? cross(p, q) > 0 : half(p) < half(q);
}