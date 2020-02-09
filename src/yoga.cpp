

#include <iostream>
#include <emscripten/emscripten.h>


using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
    cout << "Hello javascript" << endl;
    cerr << "Error output" << endl;
    return 0;
}

extern "C" {
void EMSCRIPTEN_KEEPALIVE custom_func()
{
    for (std::size_t i{}; i < 10; ++i)
    {
        cout << "custom_func" << endl;
    }
}
}