#pragma once


// simple_example_1.cpp
#include<iostream>
#include "..\..\..\boost_1_79_0\boost\tokenizer.hpp"
#include<string>
#include <fstream>

int letter_score(string& s)
{
    int score = 0;
    for (char c : s)
        score += c - 'A' + 1;
    return score;
}

void token_example()
{
    using namespace std;
    vector<string> vs;

    ifstream names("names.txt", ios::in);
    string str;
    if (!names.is_open())
    {
        cout << "unable to open file names.txt" << '\n';
        return;
    }
    names >> str;
    //string str1 = str.substr(0, 100);
    //cout << str1 << '\n';
    typedef boost::tokenizer<boost::char_separator<char> >
        tokenizer;
    boost::char_separator<char> sep(",\"");
    tokenizer tokens(str, sep);
    for (tokenizer::iterator tok_iter = tokens.begin();
        tok_iter != tokens.end(); ++tok_iter)
        vs.emplace_back(*tok_iter);

    sort(vs.begin(), vs.end());

    vector<int> counts;
    int count = 0;
    for (string s : vs)
    {
        count = letter_score(s);
        counts.emplace_back(count);
        //if (s == "COLIN")
        //    cout << count << '\n';
        // cout << count << ", ";
        // cout << s << ", ";
        // ++index;
    }
    vector<int> position(counts.size(), 0);
    iota(position.begin(), position.end(), 1);
    for (int x : counts)
        cout << x << ", ";
    int sum = inner_product(counts.begin(), counts.end(), position.begin(), 0);

    cout << "Names Score is " << sum << "       " << vs.size() << '\n';
    auto vs_it = find(vs.begin(), vs.end(), "COLIN");
    int vs_pos = vs_it - vs.begin() + 1;
    cout << "COLIN is at " << vs_pos << '\n';
    //    cout << s << "  ";
    //cout << "\n";
}


