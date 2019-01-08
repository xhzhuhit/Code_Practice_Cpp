#include "template.h"

int main() {
    TestTemplate test_template;
    std::vector<double> data;
    data.push_back(1.0);
    data.push_back(2.0);
    data.push_back(3.0);
    test_template.do_test(&data);
    return 0;
}
