#include "include/ZOFIA"

int main() {
    zofia::Greeting::greeting("Luke");

    zofia::Application application;
    application.run();

    return 0;
}