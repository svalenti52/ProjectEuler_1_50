//
// Created by svalenti on 7/3/2022.
//

#ifndef PROJECTEULER_TRIANGLE_PATH_SUM_H
#define PROJECTEULER_TRIANGLE_PATH_SUM_H

#include <vector>
#include <deque>
#include <tuple>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

using VVI = vector<vector<int>>;
using VDB = vector<deque<bool>>;
using VI = vector<int>;

using PPIB = pair<pair<int, int>, bool>;
using VPPIB = vector<PPIB>;
using VVPPIB = vector<VPPIB>;

VVI vvi =
        {{ 75 },
        { 95, 64 },
        { 17, 47, 82 },
        { 18, 35, 87, 10},
        { 20,  4, 82, 47, 65},
        { 19,  1, 23, 75,  3, 34},
        { 88,  2, 77, 73,  7, 63, 67},
        { 99, 65,  4, 28,  6, 16, 70, 92},
        { 41, 41, 26, 56, 83, 40, 80, 70, 33},
        { 41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
        { 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
        { 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
        { 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
        { 63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
        {  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}};

/////////////////////////////////////////////////////////////////////

VVI vvi_sum =
{ { 75 },
{ 95, 64 },
{ 17, 47, 82 },
{ 18, 35, 87, 10},
{ 20,  4, 82, 47, 65},
{ 19,  1, 23, 75,  3, 34},
{ 88,  2, 77, 73,  7, 63, 67},
{ 99, 65,  4, 28,  6, 16, 70, 92},
{ 41, 41, 26, 56, 83, 40, 80, 70, 33},
{ 41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
{ 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
{ 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
{ 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
{ 63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
{  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23} };

//////////////////////////////////////////////////////////////////////

int triangle_bound = vvi.size();

VVI vvi_diff;
void init_vvi_diff()
{
    for (int rx = 1; rx < vvi.size(); ++rx)
    {
        VI temp;
        for (int cx = 0; cx < vvi[rx].size() - 1; ++cx)
        {
            temp.emplace_back(vvi[rx][cx + 1] - vvi[rx][cx]);
        }
        vvi_diff.emplace_back(temp);
    }
}

void show_vvi_diff()
{
    for (auto vi : vvi_diff)
    {
        for (int i : vi)
            cout << setw(4) << i << " ";
        cout << '\n';
    }
}

VVI vvi_vert;
void init_vvi_vert()
{
    copy(vvi_diff.begin(), vvi_diff.end(), back_inserter(vvi_vert));

    for (int rx = vvi_vert.size()-2; rx >= 0; --rx)
    {
        for (int cx = 0; cx < vvi_vert[rx].size(); ++cx)
        {
            int left = vvi_vert[rx + 1][cx] - vvi_vert[rx][cx];
            int right = vvi_vert[rx + 1][cx + 1] - vvi_vert[rx][cx];
            if (left > right)
                vvi_vert[rx][cx] = left;
            else
                vvi_vert[rx][cx] = right;
        }
    }
}

void show_vvi_vert()
{
    for (auto vi : vvi_vert)
    {
        for (int i : vi)
            cout << setw(5) << i << " ";
        cout << '\n';
    }
}


bool F = false;
bool T = true;

VVPPIB skeins;
VPPIB skein;
PPIB skein_elt;

VDB vdb;
void init_vdb()
{
    for (int ix = 0; ix < 15; ++ix)
    {
        deque<bool> temp;
        for (int jx = 0; jx < ix + 1; ++jx)
        {
            temp.push_back(F);
        }
        vdb.push_back(temp);
    }
}

void show_vdb()
{
    for (int rx = 0; rx < 15; ++rx)
    {
        for (int cx = 0; cx < rx + 1; ++cx)
        {
            cout << vdb[rx][cx] << " ";
        }
        cout << '\n';
    }
}

int find_skeins(int row, int col, int sum)
{
    if (row == vvi.size() - 1) return vvi[row][col] + sum;

    int cumsum = vvi[row][col] + sum;
    int sum1 = 0;
    int sum2 = 0;
    if (vdb[row + 1][col])
        sum1 = find_skeins(row + 1, col, cumsum);

    if (vdb[row + 1][col + 1])
        sum2 = find_skeins(row + 1, col + 1, cumsum);
    
    return max(sum1, sum2);
}

/////////////////////////////////////////////////////////////////////////////

int sum_from_bottom()
{
    auto nrx = vvi_sum.rend();
    for (auto rx = vvi_sum.rbegin(); rx != vvi_sum.rend(); ++rx)
    {
        if (nrx != vvi_sum.rend())
        {
            for (auto cx = rx->begin(); cx != rx->end(); ++cx)
            {
                cout << *cx << "*";
                size_t cxx = cx - rx->begin();
                int left = *(nrx->begin() + cxx);
                int right = *(nrx->begin() + cxx + 1);
                if (left > right)
                    *cx += left;
                else
                    *cx += right;
            }
            cout << '\n';
        }
        nrx = rx;
    }

    auto sum = vvi_sum[0].begin();

    return *sum;
}

void show_vvi_sum()
{
    for (auto vi : vvi_sum)
    {
        for (int i : vi)
            cout << setw(4) << i << " ";
        cout << '\n';
    }
}

/////////////////////////////////////////////////////////////////////////////

using value_t = int;
using row_t = int;
using col_t = int;
using connected_below_t = bool;
using tri_tup = tuple<value_t, row_t, col_t>;

class Tri_Tup
{
public:
    int value;
    int row;
    int col;
    bool connected_below;
    explicit Tri_Tup(int i_value, int i_row, int i_col) :
        value(i_value), row(i_row), col(i_col), connected_below(false) {}
    friend bool operator < (const Tri_Tup& lhs, const Tri_Tup& rhs);
    friend ostream& operator << (ostream& o, const Tri_Tup& tt);
};

using MTTB = map<Tri_Tup, bool>;
using VSTT = vector<set<Tri_Tup>>;

bool operator < (const Tri_Tup& lhs, const Tri_Tup& rhs)
{
    if (lhs.row < rhs.row) return true;
    if (lhs.row > rhs.row) return false;
    if (lhs.col < rhs.col) return true;
    return false;
}

ostream& operator << (ostream& o, const Tri_Tup& tt)
{
    cout << "value = " << tt.value << " row = " << tt.row << " col = " << tt.col;
    return o;
}

int sum_triangle(int row, int col)
{
    if (row == triangle_bound) return 0;
    int sum1 = sum_triangle(row+1, col);
    int sum2 = sum_triangle(row+1, col+1);
    //if (row == 0)
        // cout << sum1 << ", " << sum2 << '\n';

    if (sum1 > sum2)
        return sum1 + vvi[row][col];
    return sum2 + vvi[row][col];
}

void max_sum_path_brute_force()
{
    int max_sum = 0;

    max_sum = sum_triangle(0, 0);
    cout << "Maximum sum of Triangle Path = " << max_sum << '\n';
}

int get_and_remove_max(VI& rmv)
{
    auto itrmv = max_element(rmv.begin(), rmv.end());
    if (itrmv == rmv.end())
    {
        //cout << "0\n";
        return 0;
    }
    int max_elt = *itrmv;
    //cout << max_elt << '\n';
    rmv.erase(remove(rmv.begin(), rmv.end(), max_elt));
    return max_elt;
}

int accumulate_legitimate(VSTT& vstt)
{
    //vector<Tri_Tup> vtt;
    int sum = 0;
    for (int ix = 0; ix < vstt.size()-1; ++ix)
    {
    }
    for (auto& stt : vstt)
    {
        for (auto& tt : stt)
        {

        }
    }
    //for (Tri_Tup tt : vtt)
    //    cout << tt << '\n';
    return 0;
}

///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////

void max_sum_path()
{
    int max_sum = 0;
    VVI remove_max_array {vvi};
    MTTB max_triangle_tuple;
    VSTT max_triangle_paths;

    init_vdb();
    init_vvi_diff();
    //show_vvi_diff();
    cout << "\n\n";
    init_vvi_vert();
    //show_vvi_vert();

    for (int jx = 0; jx < 9; ++jx)
    {
        for (int ix = 0; ix < vvi.size(); ++ix)
        {
            int max_elt = get_and_remove_max(remove_max_array[ix]);
            if (max_elt == 0) continue;

            auto it = find(vvi[ix].begin(), vvi[ix].end(), max_elt);
            while (it != vvi[ix].end())
            {
                int col = it - vvi[ix].begin();
                vdb[ix][col] = true;  
                it = max_element(it + 1, vvi[ix].end());
                if (*it != max_elt) break;
            }
        }
        //show_vdb();
    }

    int sum = sum_from_bottom();

    show_vvi_sum();

    //int sum = find_skeins(0, 0, 0);

    cout << "Maximum Path = " << sum << '\n';
}

#endif //PROJECTEULER_TRIANGLE_PATH_SUM_H
