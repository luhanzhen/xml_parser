//
// Created by zhenl on 2022/10/8.
//

#ifndef XMLPARSER_XMLDOC_H
#define XMLPARSER_XMLDOC_H

#include <unordered_map>
#include <stack>
#include <fstream>
#include "xmlElement.h"

using namespace std;

class xmlDoc {

    xmlElement *root; //根部
    string fileName; //文件名
    string fileContent; //文件内容
    string header;  //头部
//    unordered_map<string, uint64_t> elementBegin; //元素标记开始位置
    vector<pair<string, uint64_t>> elementBegin; //元素标记开始位置
    vector<pair<string, uint64_t>> elementEnd; //元素标记终点位置
//    unordered_map<string, uint64_t> elementEnd; //元素标记终点位置
    unordered_map<string, xmlElement *> elementByName; //根据名字找到元素
    unordered_map<xmlElement *, xmlElement *> element2Father;// 找到元素的父亲
    stack<pair<string, uint64_t> *> stack;

    friend class xmlElement;

    void readFile() {
        ifstream in(fileName);
        if (!in.is_open())
            throw bad_exception();
//        exception("open file error!![" + fileName + "]");
        string line;
        while (getline(in, line))
            fileContent += line;
        in.close();
    }


    void processContent() {
        uint64_t size = fileContent.size();
        for (uint64_t i = 0; i < size; ++i) {
            if (fileContent[i] == '<') {
                uint64_t second = i + 1;
                while (fileContent[i] != '>' && fileContent[i] != ' ') {
                    i++;
                }
                string name = fileContent.substr(second, i - second);
                if (fileContent[second] == '/') {
                    elementEnd.emplace_back(name, second - 1);
                } else {
                    elementBegin.emplace_back(name, second - 1);
                    elementByName[name] = nullptr;
                }
            }
        }
    }

    void processElements() {
        int beginIdx = 1;
        int endIdx = 0;
        xmlElement *father = root;
        int layer = 0;
        while (!stack.empty()) {
            while (elementEnd[endIdx].first != ("/" + stack.top()->first)) {
                stack.push(&elementBegin[beginIdx]);
//                cout << elementBegin[beginIdx].first << endl;
                auto *e = new xmlElement(father, fileContent, elementBegin[beginIdx].first,
                                         elementBegin[beginIdx].second, layer + 1);
                father->addChild(e);
                element2Father[e] = father;
                father = e;
                layer++;
                elementByName[elementBegin[beginIdx].first] = e;
                beginIdx++;
            }

//            uint64_t top = stack.top()->second;
            if (elementEnd[endIdx].second < elementBegin[beginIdx].second || beginIdx >= elementBegin.size()) {
                pair<string, uint64_t> *top = stack.top();
                stack.pop();
//                cout << "                          "<<top->first << endl;
                xmlElement *e = elementByName[top->first];
                e->updateContent(fileContent, top->second, elementEnd[endIdx].second);
                father = element2Father[e];
                layer--;
                endIdx++;
            }
        }
    }

public:
    explicit xmlDoc(string filename) {
        fileName = std::move(filename);
        readFile();
        processContent();
        stack.push(&elementBegin[0]);
        root = new xmlElement(nullptr, fileContent, elementBegin[0].first, elementBegin[0].second, 0);
        elementByName[elementBegin[0].first] = root;
        processElements();
    }

    void print() {
//        cout << fileContent << endl;
        for (auto &e: elementBegin) {
            cout << e.first << "->" << e.second << "     " << endl;
        }
        cout << endl << endl;
        for (auto &e: elementEnd) {
            cout << e.first << "->" << e.second << "     " << endl;
        }
        cout << endl;
    }

    friend ostream &operator<<(ostream &in, xmlDoc &xml) {
//        for (auto &e: xml.elementBegin) {
//            in << e.first << "->" << e.second << "     " << endl;
//        }
//        in << endl << endl;
//        for (auto &e: xml.elementEnd) {
//            in << e.first << "->" << e.second << "     " << endl;
//        }
//        in << endl;
        in << *xml.root;
        return in;
    }

    ~xmlDoc() {
        delete root;
    }

};


#endif //XMLPARSER_XMLDOC_H
