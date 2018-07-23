struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(const double &d) { return Point(x * d, y * d); }
    bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
    double dot(const Point &p) { return x * p.x + y * p.y; }
    double det(const Point &p) { return x * p.y - y * p.x; }
};

double cross(Point A, Point B, Point C)
{
    return (B - A).det(C - A);
}

double multi(Point A, Point B, Point C)
{
    return (B - A).dot(C - A);
}

double dist(Point A, Point B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

void anticlockwise_sort(Point *p, int N)
{
    for (int i = 0; i < N - 2; ++i)
    {
        double tmp = cross(p[i], p[i + 1], p[i + 2]);
        if (tmp > EPS)
            return;
        else if (tmp < -EPS)
        {
            reverse(p, p + N);
            return;
        }
    }
}

double point_to_line(Point A, Point B, Point C)
{
    if (dist(A, B) < EPS)
        return dist(B, C);
    if (multi(A, B, C) < -EPS)
        return dist(A, C);
    if (multi(B, A, C) < -EPS)
        return dist(B, C);
    return fabs(cross(A, B, C) / dist(A, B));
}

// Line AB to C
double point_to_line(Point A, Point B, Point C)
{
    // A=B (not a line)
    if (dist(A, B) < EPS)
        return dist(B, C);
    // angle BAC = 90
    if (multi(A, B, C) < -EPS)
        return dist(A, C);
    // angle ABC = 90
    if (multi(B, A, C) < -EPS)
        return dist(B, C);
    // AB X AC = |AB|*|AC|*sinθ  (|AC|sinθ = distance between Line AB and C)
    return fabs(cross(A, B, C) / dist(A, B));
}

double line_to_line(Point A, Point B, Point C, Point D)
{
    return min(min(point_to_line(A, B, C), point_to_line(A, B, D)), min(point_to_line(C, D, A), point_to_line(C, D, B)));
}

// θ = angle BAC, AB · AC = |AB|*|AC|*cosθ
double angle(Point A, Point B, Point C) { return acos(multi(A, B, C) / dist(A, B) / dist(A, C)); }

// intersection(P, nN, Q, nM) || intersection(Q, nM, P, nN)  -> avoid P totally inside Q
bool intersection(Point *P, int N, Point *Q, int M)
{
    double angles[MAXN];
    int i, j, lowbound;

    angles[0] = 0;
    for (i = 2; i < N; i++)
        angles[i - 1] = angle(P[0], P[1], P[i]);
    for (i = 0; i < M; i++)
    {
        j = dcmp(cross(P[0], P[1], Q[i]));
        // outside or on the line (use dot to determine direction of P[0]Q)
        if (j < 0 || (j == 0 && multi(P[0], P[1], Q[i]) < 0))
            continue;
        j = dcmp(cross(P[0], P[N - 1], Q[i]));
        if (j > 0 || (j == 0 && multi(P[0], P[N - 1], Q[i]) < 0))
            continue;
        lowbound = lower_bound(angles, angles + N - 1, angle(P[0], P[1], Q[i])) - angles;
        if (lowbound == 0)
            j = 0;
        else
            j = lowbound - 1;
        // judge inside or outside
        if (dcmp(cross(Q[i], P[j + 1], P[j + 2])) >= 0)
            break;
    }
    if (i < M)
        return true;
    return false;
}

// distance between two convex
double solve(Point *P, Point *Q, int n, int m)
{
    int yminP = 0, ymaxQ = 0;
    for (int i = 0; i < n; ++i)
        if (P[i].y < P[yminP].y)
            yminP = i;
    for (int i = 0; i < m; ++i)
        if (Q[i].y > Q[ymaxQ].y)
            ymaxQ = i;
    P[n] = P[0];
    Q[m] = Q[0];
    double arg, ans = INF;
    for (int i = 0; i < n; ++i)
    {
        while (arg = cross(P[yminP + 1], Q[ymaxQ + 1], P[yminP]) - cross(P[yminP + 1], Q[ymaxQ], P[yminP]) > EPS)
            ymaxQ = (ymaxQ + 1) % m;
        ans = min(ans, line_to_line(P[yminP], P[yminP + 1], Q[ymaxQ], Q[ymaxQ + 1]));
        yminP = (yminP + 1) % n;
    }
    return ans;
}

// 旋轉卡殼
// https://blog.csdn.net/hanchengxi/article/details/8639476