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

    if(target != nullptr)
    {
        ShinyCounter sc("Shiny Counter", x, y, target);
        sc.run();
    }

    else
    {
        std::cerr<<"Target cannot be nullptr"<<std::endl;
        return 1;
    }

    return 0;
}
