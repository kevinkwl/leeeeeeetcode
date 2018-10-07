#define abs(a) (a >= 0 ? (a) : (-(a)))
int mySqrt(int x) {
    double g = 1.0;
    while (abs(g*g-x) > 1e-6)
        g = 0.5 * (g + x / g);
    return g;
}
