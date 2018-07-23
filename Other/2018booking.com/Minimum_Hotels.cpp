#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the solve function below.
int solve(vector<int> customer, int k)
{
    int ans = 1, house;
    sort(customer.begin(), customer.end());
    house = customer[0] + k;
    for (int i = 1; i < customer.size(); ++i)
    {
        if (customer[i] - k > house)
        {
            ans++;
            house = customer[i] + k;
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
        string customer_count_temp;
        getline(cin, customer_count_temp);

        int customer_count = stoi(ltrim(rtrim(customer_count_temp)));

        string customer_temp_temp;
        getline(cin, customer_temp_temp);

        vector<string> customer_temp = split(rtrim(customer_temp_temp));

        vector<int> customer(customer_count);

        for (int i = 0; i < customer_count; i++)
        {
            int customer_item = stoi(customer_temp[i]);

            customer[i] = customer_item;
        }

        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        int result = solve(customer, k);

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
