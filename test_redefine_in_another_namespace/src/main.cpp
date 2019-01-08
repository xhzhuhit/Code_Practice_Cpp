//#include "../include/do_something.h"
#include "../utils/do_something.h"

//DoSomething do_some_cpp;
pos::DoSomething do_some_lib;
int main() {
    do_some_lib.say_something();
    do_some_lib.own_something();
    return 0;
}
