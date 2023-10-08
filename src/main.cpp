#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <stack>
#include<regex>
#include <filesystem>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>
#include "Timer.h"
#include "Files.h"

namespace fs = std::filesystem;

using namespace std;



//void readFile(string &&fileName) {
//    if (fileName.find("bz2") != string::npos)
//        return;
//    string fileContent;
//    ifstream in(fileName);
//    if (!in.is_open())
//        throw bad_exception();
////        exception("open file error!![" + fileName + "]");
//    string line;
//    while (getline(in, line)) {
//        fileContent += line;
//    }
////
//    in.close();
////    if (fileContent.find("allDifferent") != string::npos && fileContent.find("type=\"CSP\"") != string::npos )
//    if (fileContent.find("allDifferent") != string::npos )
//        std::cout << fileName << std::endl;
//
//}




void readFile(string &&fileName, vector<string> &lines) {
//    if (fileName.find("bz2") != string::npos)
//        return;
//    string fileContent;
    ifstream in(fileName);
    if (!in.is_open())
        throw bad_exception();
//        exception("open file error!![" + fileName + "]");
    string line;
    while (getline(in, line)) {
        lines.push_back(line);
    }
//
    in.close();
//    if (fileContent.find("allDifferent") != string::npos && fileContent.find("type=\"CSP\"") != string::npos )
//        std::cout << fileName << std::endl;

}

int add(int a, int b)
{
#ifdef _WIN32


#elif defined(__GNUC__) || defined(__GNUG__)

#endif


}
int main() {
//    vector<vector<int>> adj(7);
//
////    adj[0].assign({1,2});
////    adj[1].assign({2});
////    adj[2].assign({0,3,5,6});
////    adj[3].assign({4});
////    adj[4].assign({0,1,3,6});
////    adj[5].assign({4,6});
////    adj[6].assign({4,5});
//
//    adj[0].assign({1});
//    adj[1].assign({2});
//    adj[2].assign({3});
//    adj[3].assign({4});
//    adj[4].assign({5});
//    adj[5].assign({6});
//    adj[6].assign({0});
//    find_bridges(adj);
//    int a = 0;
//
//
//    __int128 a = LONG_LONG_MAX;
//    __int128 b = LONG_LONG_MAX;
//    cout<<(a*b)<<endl;
//    85070591730234615847396907784232501249


//    std::cout <<  a << "ms"<<std::endl;
//    fs::path str_path = "D:\\fromLiZhe\\AllDiffBench\\";
    fs::path str_path = ".";
    vector<fs::path> files;
//    fs::path str_path = "D:\\XCSP3\\Sudoku\\Sudoku-table-s1\\";
//    Timer t;
    getAllFiles(str_path, files);



//    int counter = 0;
    vector<string> lines;
    for (auto &file: files) {
        readFile(file.string(), lines);
//        if(file.filename().string().find("ext") != string::npos && file.filename().string().find("bz2") == string::npos )
//            counter++;
//            cout<<file.parent_path()<<endl;
//        std::cout << file.filename() << std::endl;
//        std::cout <<  file.string() << std::endl;
//        xmlDoc *xml = new xmlDoc(file.string());
//        delete xml;
    }
//    cout<<counter<<endl;

    string outputFile = str_path.root_path().string() + "allOutput.csv";
    sort(lines.begin(), lines.end(), [](auto &e1, auto &e2) {
        string sub1 = e1.substr(e1.find(","));
        string sub2 = e2.substr(e2.find(","));
        return sub1 < sub2;
    });
    ofstream out(outputFile, ios::trunc);
    for (string &line: lines)
        out << line << endl;
    out.close();
//    std::cout <<   t.elapsed() << "ms"<<std::endl;

//    std::cout << "Hello, World!" << std::endl;
//    xmlDoc xml(R"(D:\XCSP3\Bibd\Bibd-sc-s1\Bibd-sc-03-03-01.xml)");
//    xmlDoc xml(R"(D:\XCSP3\DiamondFree\DiamondFree-m1-s1\DiamondFree-060.xml)");
//    xml.print();
//    cout << xml << endl;
    return 0;
}




//void write(__int128 x) {
//    if (x < 0) {
//        ;
//        x = -x;
//
//    }
//    if(x > 9)
//        write(x/10);
//    putchar(x%10+'0');
//
//}
//
//ofstream& operator<<(ofstream &of, __int128 &in)
//{
//    __int128 x = in;
//    if (x < 0)
//    {
//        of<<'-';
//        x = -x;
//    }
//    int bit[35] = {0};
//    int top = 0;
//    do {
//        bit[top++] = x % 10;
//        x /= 10;
//    } while (x);
//    while (top)
//    {
//        of<<bit[--top]<<"0";
//    }
//    return of;
//}
//
//
//
//int n; // number of nodes
// // adjacency list of graph
//
//vector<bool> visited;
//vector<int> tin, low;
//int timer;
//
//void dfs(vector<vector<int>>& adj,int v, int p = -1) {
//    visited[v] = true;
//    tin[v] = low[v] = timer++;
//    for (int to : adj[v]) {
//        if (to == p)
//            continue;
//        if (visited[to]) {
//            low[v] = min(low[v], tin[to]);
//        } else {
//            dfs(adj,to, v);
//            low[v] = min(low[v], low[to]);
//            if (low[to] > tin[v])
////                IS_BRIDGE(v, to);
//                cout<<v << " => " << to <<" is bridge."<<endl;
//        }
//    }
//}
//
//void find_bridges( vector<vector<int>>& adj) {
//    timer = 0;
//    visited.assign(n, false);
//    tin.assign(n, -1);
//    low.assign(n, -1);
//    for (int i = 0; i < n; ++i) {
//        if (!visited[i])
//            dfs(adj,i);
//    }
//}
//

