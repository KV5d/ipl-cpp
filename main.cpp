#include<stdio.h>
#include<string>
#include<iostream>
#include"HTTPRequest.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc > 2) {
        printf("%s\n", "too many args");
        return 1;
    } else if (argc < 2) {
        printf("%s\n", "not enough args");
        return 1;
    }

    printf("\n%s", "\033[1;36m=================================\033[0m");
    printf("\n%s\n", "\033[1;35m               ipl\033[0m");
    printf("%s\n", "\033[1;36m=================================\033[0m");

    string api = "http://ip-api.com/json/";
    string ip = argv[1];
    string api_full = api + ip + "?fields=761";

    try {
        http::Request request{api_full};

        const auto response = request.send("GET");

        printf("\n\033[1;33m%s\033[0m\n", response.body.data());
    } catch (const exception& e) {
        cerr << "error: " << e.what() << '\n';
    }

    return 0;
}
