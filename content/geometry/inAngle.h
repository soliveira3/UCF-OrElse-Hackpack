/**
 * Author: CP-Geo Handbook
 * Description: Returns true if p is in the angle between b and c.
 * The angle starts at point a (b and c are endpoints).
 * The angle is assumed to be at most 180 and the points are not colinear.
 * Modify equals sign for exclusive inAngle check.
 */

#include "sideOf.h"
#include "Point.h"

bool inAngle(P a, P b, P c, P p)
{
    assert(sideOf(a, c, b) != 0);
    if (sideOf(a, c, b) < 0) swap(b, c);
    return sideOf(a, p, b) >= 0 && sideOf(a, p, c) <= 0;
}