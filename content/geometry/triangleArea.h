/**
 * Author: CP-Geo Handbook
 * Description: Finds the area of a triangle
 */

ld triangleArea(P a, P b, P c) {
    return abs((b-a).cross(c-a)) / (ld)(2);
}