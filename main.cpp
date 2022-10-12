//
// Created by DavidWisdom on 2022/10/12.
//
#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    locale china("chs");
    wcin.imbue(china);
    wcout.imbue(china);
    wfstream res;
    res.imbue(china);
    res.open("output.txt", ios::out);
    wstring s;
    wstring dictionary;
    getline(wcin, s);
    dictionary += s;
    wcout << "dictionary:" << dictionary << '\n';
    wstring longtext;
    while (wcin >> s) {
        longtext += s;
    }
    int n = dictionary.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < longtext.size(); ++i) {
        for (int k = 0; k < n; ++k) {
            if (longtext[i] == dictionary[k]) {
                ++dp[k];
                break;
            }
        }
    }
    // TODO: 查找算法有待改进
    for (int i = 0; i < n; ++i) {
        res << dictionary[i] << ":" << dp[i] << '\n';
    }
    return 0;
}
