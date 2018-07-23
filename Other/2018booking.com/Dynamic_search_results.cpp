#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the solve function below.

int LIS(vector<int> &s)
{
    if (s.size() == 0)
        return 0;

    vector<int> v;
    v.push_back(s[0]);

    for (int i = 1; i < s.size(); ++i)
    {
        int n = s[i];

        if (n > v.back())
            v.push_back(n);
        else
            *lower_bound(v.begin(), v.end(), n) = n;
    }

    return v.size();
}

// Complete the solve function below.
int solve(vector<int> list1, vector<int> list2)
{
    map<int, int> l1;
    for (int i = 0; i < list1.size(); ++i)
    {
        l1[list1[i]] = i;
        //l1.insert ( l1.begin(), pair<int,int>(list1[i],i));
    }

    std::map<int, int>::iterator it;
    for (it = l1.begin(); it != l1.end(); ++it)
        cout << it->first << " => " << it->second << '\n';

    int len = list1.size() + list2.size(), same = 0;

    for (int i = 0; i < list2.size();)
    {
        if (l1.count(list2[i]) != 0)
        {
            same++;
            list2[i] = l1[list2[i]];
            ++i;
        }
        else
        {
            list2.erase(list2.begin() + i);
        }
    }
    return len - 2 * same + list2.size() - LIS(list2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split(rtrim(nm_temp));

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string list1_temp_temp;
    getline(cin, list1_temp_temp);

    vector<string> list1_temp = split(rtrim(list1_temp_temp));

    vector<int> list1(n);

    for (int i = 0; i < n; i++)
    {
        int list1_item = stoi(list1_temp[i]);

        list1[i] = list1_item;
    }

    string list2_temp_temp;
    getline(cin, list2_temp_temp);

    vector<string> list2_temp = split(rtrim(list2_temp_temp));

    vector<int> list2(m);

    for (int i = 0; i < m; i++)
    {
        int list2_item = stoi(list2_temp[i]);

        list2[i] = list2_item;
    }

    int result = solve(list1, list2);

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
