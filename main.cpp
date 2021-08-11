#include "ShinyCounter.hpp"

int main(int argc, char** argv)
{
    unsigned int x = 300;
    unsigned int y = 300;

    const char* target = nullptr;

    if(argc == 2)
    {
        target = argv[1];
    }

    if(argc == 3)
    {
        x = atoi(argv[1]);
        y = atoi(argv[2]);
    }

    ShinyCounter sc("Shiny Counter", x, y, target);
    sc.run();

    return 0;
}
