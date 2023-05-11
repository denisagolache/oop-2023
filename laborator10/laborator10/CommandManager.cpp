#define _CRT_SECURE_NO_WARNINGS
#include "CommandManager.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <functional>
#include <map>
using namespace std;
void CommandManager::add(string name, function<void(vector<string>)> fn)
{
	commands[name] = fn;
}

void CommandManager::run() {
    while (true) {
        cout << "> ";
        string line;
        getline(cin, line);
        if (line.empty()) continue;

        vector<string> args;
        char* token = strtok(&line[0], " ");
        while (token != nullptr) {
            args.push_back(token);
            token = strtok(nullptr, " ");
        }

        if (args.empty()) continue;

        string commandName = args[0];
        if (commandName == "stop") return;

        auto it = commands.find(commandName);
        if (it != commands.end()) {
            try {
                it->second(vector<string>(args.begin() + 1, args.end()));
            }
            catch (const std::exception& ex) {
                cout << "Exception: " << ex.what() << endl;
            }
        }
        else {
            cout << "Command not found: " << commandName << endl;
        }
    }
}


FileException::FileException(const std::string& filename, const std::string& message): filename(filename), message(message)
{
}

const char* FileException::what() const noexcept
{
    return message.c_str();
}

