//
// Created by zhenl on 2022/9/6.
//

#ifndef XMLPARSER_FILES_H
#define XMLPARSER_FILES_H
#include <vector>
#include<regex>
#include <filesystem>



namespace fs = std::filesystem;

void getAllFiles(const fs::path& str_path, std::vector<fs::path>& files) {
//	std::regex xml("^([a-zA-Z]+-?)+[a-zA-Z0-9]+\\.[x|X][m|M][l|L]$");
    for (auto& fe : fs::directory_iterator(str_path)) {
        const auto& fp = fe.path();
        auto fFilename = fp.filename();

        // 递归调用, .和..不取
        if (fs::is_directory(fe)) {
            if (fFilename != "." && fFilename != "..") {
                //files.push_back(fp);
                getAllFiles(fp, files);
            }
        }
        else {
//			if(regex_match(fp.filename().string(),xml) != 0)
//            if(fp.filename().string().find("xml") != std::string::npos)
            if(fp.filename().string().find("csv") != std::string::npos && fp.filename().string().find("output") != std::string::npos)
                files.push_back(fp);
        }
    }
}

// 只获取一层文件,文件夹不取
void get_files(const fs::path& strPath, std::vector<fs::path>& files) {
    // 文件只取path
    for (auto& fe : fs::directory_iterator(strPath))
        if (!fs::is_directory(fe.path()))
            files.push_back(fe.path());
}

#endif //XMLPARSER_FILES_H
