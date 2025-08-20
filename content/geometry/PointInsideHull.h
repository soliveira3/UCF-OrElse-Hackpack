/**
 * Author: chilli
 * Date: 2019-05-17
 * License: CC0
 * Source: https://github.com/ngthanhtrung23/ACM_Notebook_new
 * Description: Determine whether a point t lies inside a convex hull (CCW
 * order, with no collinear points). Returns true if point lies within
 * the hull. If strict is true, points on the boundary aren't included.
 * Usage:
 * Status: stress-tested
 * Time: O(\log N)
 */
#pragma once

#include "Point.h"
#include "sideOf.h"
#include "OnSegment.h"

typedef Point<ll> P;

bool inHull(const vector<P>& h, P p, bool strict = true) {
	int a = 1, b = sz(h) - 1, r = !strict;
	if (sz(h) < 3) return r && onSegment(h[0], h.back(), p);
	if (sideOf(h[0], h[a], h[b]) > 0) swap(a, b);
	if (sideOf(h[0], h[a], p) >= r || sideOf(h[0], h[b], p)<= -r)
		return false;
	while (abs(a - b) > 1) {
		int c = (a + b) / 2;
		(sideOf(h[0], h[c], p) > 0 ? b : a) = c;
	}
	return sgn(h[a].cross(h[b], p)) < r;
}
