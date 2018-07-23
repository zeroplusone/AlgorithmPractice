#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

#define INF 1e9
#define EPS 1E-6
#define MAXN 5500

// double compare (EPS)
int dcmp(double x) { return fabs(x) < EPS ? 0 : (x < 0 ? -1 : 1); }

struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(const double &d) { return Point(x * d, y * d); }
    Point operator/(const double &d) { return Point(x / d, y / d); }
    bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
    double dot(const Point &p) { return x * p.x + y * p.y; }
    double det(const Point &p) { return x * p.y - y * p.x; }
};

// AB X AC
double cross(Point A, Point B, Point C)
{
    return (B - A).det(C - A);
}

// AB · AC
double multi(Point A, Point B, Point C)
{
    return (B - A).dot(C - A);
}

// distance AB
double dist(Point A, Point B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
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
    // AB X AC = |AB|*|AC|*sinO  (|AC|sinO = distance between Line AB and C)
    return fabs(cross(A, B, C) / dist(A, B));
}

double line_to_line(Point A, Point B, Point C, Point D)
{
    return min(min(point_to_line(A, B, C), point_to_line(A, B, D)), min(point_to_line(C, D, A), point_to_line(C, D, B)));
}

// O = angle BAC, AB · AC = |AB|*|AC|*cosO
double angle(Point A, Point B, Point C) { return acos(multi(A, B, C) / dist(A, B) / dist(A, C)); }

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

double solve2(Point *P, Point *Q, int n, int m)
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
    double ans = INF;
    for (int i = 0; i < n; ++i)
    {
        while (cross(P[yminP + 1], Q[ymaxQ + 1], P[yminP]) - cross(P[yminP + 1], Q[ymaxQ], P[yminP]) > EPS)
            ymaxQ = (ymaxQ + 1) % m;
        ans = min(ans, line_to_line(P[yminP], P[yminP + 1], Q[ymaxQ], Q[ymaxQ + 1]));
        yminP = (yminP + 1) % n;
    }
    return ans;
}

// Complete the solve function below.
double solve(vector<vector<int> > p, vector<vector<int> > q)
{
    // removeColinear
    Point P[MAXN], Q[MAXN];
    int N = p.size(), M = q.size();
    p.push_back(p[0]);
    p.push_back(p[1]);
    q.push_back(q[0]);
    q.push_back(q[1]);
    vector<bool> pRedun(N, false);
    vector<bool> qRedun(M, false);
    for (int i = 0; i < N; ++i)
    {
        if (fabs(cross(Point(p[i][0], p[i][1]), Point(p[i + 1][0], p[i + 1][1]), Point(p[i + 2][0], p[i + 2][1]))) < EPS)
        {
            pRedun[(i + 1) % N] = true;
        }
    }
    for (int i = 0; i < M; ++i)
    {
        if (fabs(cross(Point(q[i][0], q[i][1]), Point(q[i + 1][0], q[i + 1][1]), Point(q[i + 2][0], q[i + 2][1]))) < EPS)
        {
            qRedun[(i + 1) % M] = true;
        }
    }
    // turn vector to point
    int nN = 0, nM = 0;
    for (int i = 0; i < N; ++i)
    {
        if (!pRedun[i])
        {
            P[nN].x = p[i][0];
            P[nN].y = p[i][1];
            nN++;
        }
    }

    for (int i = 0; i < M; ++i)
    {
        if (!qRedun[i])
        {
            Q[nM].x = q[i][0];
            Q[nM].y = q[i][1];
            nM++;
        }
    }

    //sort anti clock
    for (int i = 0; i < N - 2; ++i)
    {
        double tmp = cross(P[i], P[i + 1], P[i + 2]);
        if (tmp > EPS)
            break;
        else if (tmp < -EPS)
        {
            for (int j = 0; j < N / 2; ++j)
            {
                swap(p[j], p[N - j - 1]);
            }
            break;
        }
    }

    for (int i = 0; i < M - 2; ++i)
    {
        double tmp = cross(Q[i], Q[i + 1], Q[i + 2]);
        if (tmp > EPS)
            break;
        else if (tmp < -EPS)
        {
            for (int j = 0; j < M / 2; ++j)
            {
                swap(q[j], q[M - j - 1]);
            }
            break;
        }
    }

    //intersection
    if (intersection(P, nN, Q, nM) || intersection(Q, nM, P, nN))
    {
        return 0;
    }

    return min(solve2(P, Q, nN, nM), solve2(Q, P, nM, nN));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split(rtrim(nm_temp));

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int> > p(n);

    for (int i = 0; i < n; i++)
    {
        p[i].resize(2);

        string p_row_temp_temp;
        getline(cin, p_row_temp_temp);

        vector<string> p_row_temp = split(rtrim(p_row_temp_temp));

        for (int j = 0; j < 2; j++)
        {
            int p_row_item = stoi(p_row_temp[j]);

            p[i][j] = p_row_item;
        }
    }

    vector<vector<int> > q(m);

    for (int i = 0; i < m; i++)
    {
        q[i].resize(2);

        string q_row_temp_temp;
        getline(cin, q_row_temp_temp);

        vector<string> q_row_temp = split(rtrim(q_row_temp_temp));

        for (int j = 0; j < 2; j++)
        {
            int q_row_item = stoi(q_row_temp[j]);

            q[i][j] = q_row_item;
        }
    }

    double result = solve(p, q);
    cout << setprecision(13) << result << endl;

    fout << setprecision(13) << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}