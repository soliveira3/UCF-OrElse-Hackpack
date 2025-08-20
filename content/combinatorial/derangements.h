/**
 * Author: Benq
 * Description: Finds number of derangements
 */
d[0] = 1; d[1] = 0;
rep (i, 2, n+1) d[i] = (i-1)*(d[i-1]+d[i-2]);