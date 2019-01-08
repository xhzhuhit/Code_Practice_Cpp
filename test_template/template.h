#include <iostream>
#include <vector>

class TestTemplate {
public:
    TestTemplate(){}
    ~TestTemplate(){}
    //template <typename T> bool do_test(const std::vector<T> pose_xyyaw) {
    template <typename T> bool do_test(const T* const pose_xyyaw) {
        //double a1 = static_cast<double>(pose_xyyaw[0]);
        std::cout << "0 th = " << (*pose_xyyaw)[0] << std::endl;
        std::cout << "1 th = " << (*pose_xyyaw)[1] << std::endl;
        std::cout << "2 th = " << (*pose_xyyaw)[2] << std::endl;
    }
};
