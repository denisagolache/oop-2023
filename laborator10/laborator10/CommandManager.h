#pragma once
#define _CRT_SECURE_NO_WARNINGS_
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include <functional>
#include <map>
using namespace std;
class CommandManager {
private:
    map<string, function<void(vector<string>)>> commands;

public:
    void add(string name, function<void(vector<string>)> fn);
    void run();
};

class FileException :public exception {
    string filename;
    string message;

public:
    FileException(const string& filename, const string& message);
    virtual const char* what()const noexcept;


};