/**
 * Author: Samuel Oliveira
 * Description: Sorts points on a line s->e
 * (or from their projections / parallel intersections)
 * s and e represent the line we are comparing to
 */

#include "Point.h"

bool cmpProj(P p, P q) {
    P v = e - s;
    return v.dot(p - s) < v.dot(q - s);
}