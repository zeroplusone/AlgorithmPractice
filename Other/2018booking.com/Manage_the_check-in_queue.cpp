#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the solve function below.
int solve(int m, vector<vector<int>> desks)
{
    int total = 0, wait = 0, totalwait = 0, totalm = m;
    int maxLine = -1;
    for (int i = 0; i < desks.size(); ++i)
    {
        total += desks[i][0];
        wait = desks[i][1] / desks[i][0] + (desks[i][1] % desks[i][0] == 0 ? 0 : 1);
        maxLine = wait > maxLine ? wait : maxLine;
        totalm += desks[i][1];
    }
    totalwait = totalm / total + (totalm % total == 0 ? 0 : 1);

    return totalwait > maxLine ? totalwait : maxLine;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split(rtrim(nm_temp));

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> desks(n);

    for (int i = 0; i < n; i++)
    {
        desks[i].resize(2);

        string desks_row_temp_temp;
        getline(cin, desks_row_temp_temp);

        vector<string> desks_row_temp = split(rtrim(desks_row_temp_temp));

        for (int j = 0; j < 2; j++)
        {
            int desks_row_item = stoi(desks_row_temp[j]);

            desks[i][j] = desks_row_item;
        }
    }

    int result = solve(m, desks);

    fout << result << "\n";

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
