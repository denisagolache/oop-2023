#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include "CommandManager.h"

using namespace std;
int main() {
	CommandManager manager;

	auto ping = [](vector<string> args) { printf("pong!\n"); };
	manager.add("ping", ping);
    
	auto count = [](vector<string> args) { cout<<args.size()<<"\n";  };
	manager.add("count", count);

	int timesCount = 0;
	auto times = [&timesCount](vector<string> args) {printf("Times called %d\n", ++timesCount); };
	manager.add("times", times);

    auto copy = [](vector<string> args) {
        if (args.size() != 2) {
            printf("Usage: copy <source_file> <destination_file>\n");
            return;
        }

        try {
            ifstream source_file(args[0], ios::binary);
            if (!source_file) {
                throw FileException(args[0], "Cannot open source file for reading");
            }
            ofstream dest_file(args[1], ios::binary);
            if (!dest_file) {
                throw FileException(args[1], "Cannot open destination file for writing");
            }
            dest_file << source_file.rdbuf();

            printf("File copied successfully.\n");
        }
        catch (const FileException& ex) {
            printf("File error: %s\n", ex.what());
        }
        catch (const exception& ex) {
            printf("Error: %s\n", ex.what());
        }
    };
    manager.add("copy", copy);

    auto print_args = [](vector<string> args) {
        for (const auto& arg : args) {
            cout << arg << " ";
        }
        cout << endl;
    };

    manager.add("print_args", print_args);

    manager.add("bad_alloc", [](vector<string> args) {
        size_t size = args.empty() ? 100000000000 : stoi(args[0]);
    char* ptr = new char[size];
    delete[] ptr;
        });

	manager.run();

	printf("goodbye.\n");
}