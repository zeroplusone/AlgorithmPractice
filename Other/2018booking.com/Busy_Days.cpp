#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

struct DATE
{
    int n;
    string str;
    int isEnd;
    bool operator<(const struct DATE d) const
    {
        return n == d.n ? isEnd < d.isEnd : n < d.n;
    }
} tmp;

int transToNumber(string s)
{
    int ret = 0;
    for (int i = 0; i < 4; ++i)
    {
        ret += (s[i] - '0') * pow(10, (8 - i - 1));
    }
    for (int i = 5; i < 7; ++i)
    {
        ret += (s[i] - '0') * pow(10, (8 - i));
    }
    for (int i = 8; i < 10; ++i)
    {
        ret += (s[i] - '0') * pow(10, (8 - i + 1));
    }
    return ret;
}

// Complete the solve function below.
string solve(vector<vector<string>> reservations)
{
    vector<struct DATE> dlist;
    for (int i = 0; i < reservations.size(); ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            tmp.n = transToNumber(reservations[i][j]);
            tmp.str = reservations[i][j];
            tmp.isEnd = j;
            dlist.push_back(tmp);
        }
    }
    sort(dlist.begin(), dlist.end());
    string ans;
    int cnt = 0, maxN = -1;
    for (int i = 0; i < dlist.size(); ++i)
    {
        if (dlist[i].isEnd == 0)
        {
            cnt++;
            if (cnt > maxN)
            {
                ans = dlist[i].str;
                maxN = cnt;
            }
        }
        else
        {
            cnt--;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<string>> reservations(n);

        for (int i = 0; i < n; i++)
        {
            reservations[i].resize(2);

            string reservations_row_temp_temp;
            getline(cin, reservations_row_temp_temp);

            vector<string> reservations_row_temp = split(rtrim(reservations_row_temp_temp));

            for (int j = 0; j < 2; j++)
            {
                string reservations_row_item = reservations_row_temp[j];

                reservations[i][j] = reservations_row_item;
            }
        }

        string result = solve(reservations);

        fout << result << "\n";
    }

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
