/**
 * Author: Samuel Oliveira
 * Description: Translates a line using a given translation vector u
 * or given a distance dist
 */

void vectorTransaltion (P &s, P &e, P u) {
    s += u; e+=u;
}

void shiftLeft (P &s, P &e, ld dist) {
    P v = e-s, n = P(-v.y, v.x);
    n = n * (dist / abs(n));
    s += u; e+=u;
}
