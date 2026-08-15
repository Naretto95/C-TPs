#ifndef TP4_H
#define TP4_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Approximates pi with a Monte Carlo method (random points in a unit square). */
float monte_carlo_pi(int iterations);

/** Approximates pi with the Madhava-Leibniz series. */
float madhava_pi(int terms);

/** Approximates pi with the Wallis product. */
float wallis_pi(int terms);

/** Approximates sqrt(2) with Newton's method. */
float newton_sqrt2(int iterations);

/** Approximates sqrt(2) with Halley's method. */
float halley_sqrt2(int iterations);

/** Approximates sqrt(2) with Theon of Smyrna's ladder. */
float theon_sqrt2(int iterations);

#endif
