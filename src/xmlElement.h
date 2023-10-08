//
// Created by zhenl on 2022/10/8.
//

#ifndef XMLPARSER_XMLELEMENT_H
#define XMLPARSER_XMLELEMENT_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;
class xmlElement {
    int layer; //所属层数
    string markName;
    string content;
    string info;
    vector<xmlElement *> children;
    xmlElement *father;

public:

    xmlElement(xmlElement *Father, string &fileContent, string &MarkNameIn, uint64_t start, int layerIn) {
        uint64_t nameEnd = MarkNameIn.size() + start + 1;
        if (fileContent[nameEnd] != '>') {
            int length = 0;
            while (fileContent[nameEnd + length] != '>')
                length++;
            string sub = fileContent.substr(nameEnd, length);
            info = sub;
        }
        markName = MarkNameIn;
        father = Father;
        layer = layerIn;
    }

    void updateContent(string &fileContent, uint64_t start, uint64_t end) {
//        cout << start << "        " << end << endl;
//        cout << fileContent[start + 1] << "        " << fileContent[end] << endl;
        string sub = fileContent.substr(start + 1, end - start - 2);

        if (sub.find('<') == string::npos) {
//            cout << sub << endl;
            uint64_t t = sub.find('>');
            content = sub.substr(t + 1, end - t - 2);
        }
    }

    void addChild(xmlElement *child) {
        children.push_back(child);
    }

    friend ostream &operator<<(ostream &out, xmlElement &xml) {
        string space;
        for (int i = 0; i < xml.layer; ++i) {
            space += "  ";
        }
        out << space << "<" << xml.markName << xml.info << ">";
        if (xml.content.empty()) {
            out << endl;
        }
        out << xml.content;
        for (auto &e: xml.children)
            cout << *e << endl;
        if (xml.content.empty()) {
            out << space;
        }
        out << " </" << xml.markName << ">";
        return out;
    }


    ~xmlElement() {
        for (auto &e: children)
            delete e;
    }

};

#endif //XMLPARSER_XMLELEMENT_H
