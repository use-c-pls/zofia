#include "core/core.hpp"

int main() {
    zofia::Greeting::greeting("Luke");

    zofia::Application application;
    application.run();

    return 0;
}