#include "seeMake.h"
#include <fstream>
#include <string>
#include <cstdio>

void SeeMake::create(int argc, const char *argv[])
{

    if (argc == 2)
    {
        std::string arg = argv[1];
        if(arg == "-h" || arg == "-H" || arg == "--help" || arg == "-help" || arg == "-usage")
        {
            std::cout << "\nUsage" << std::endl;
            std::cout << "  ./SeeMake" << std::endl;
            std::cout << "  ./SeeMake <output-file-name>" << std::endl;
            std::cout << "  ./SeeMake <output-file-name> <cpp-version-number>\n" << std::endl;
            std::cout << "  Using examples" << std::endl;
            std::cout << "      ./SeeMake" << std::endl;
            std::cout << "      ./SeeMake myFile 17\n" << std::endl;
            std::cout << "Explanation" << std::endl;
            std::cout << "  ./SeeMake                                           =   Output file name: main & C++ version: 20" << std::endl;
            std::cout << "  ./SeeMake <output-file-name>                        =   Output file name: <output-file-name> & C++ version: 20" << std::endl;
            std::cout << "  ./SeeMake <output-file-name> <cpp-version-number>   =   Output file name: <output-file-name> & C++ version: <cpp-version-number>\n" << std::endl;
            std::cout << "Help" << std::endl;
            std::cout << "  -h,-H,--help,-help,-usage                           =   Usage information\n" << std::endl;
            std::cout << "  Using example" << std::endl;
            std::cout << "      ./SeeMake -h\n" << std::endl;
            return;
        }
    }

    char const *fileCMakeLists = "CMakeLists.txt";

    remove(fileCMakeLists);

    std::ofstream contentCMakeLists (fileCMakeLists, std::ios::app);

    contentCMakeLists << "cmake_minimum_required(VERSION 3.0)\n" << std::endl;

    if(argc>=2) {
        contentCMakeLists << "project(" << argv[1] << ")\n" << std::endl;
    } else {
        contentCMakeLists << "project(main)\n" << std::endl;
    }

    if(argc>=3) {
        contentCMakeLists << "set(CMAKE_CXX_STANDARD " << argv[2] << ")\n" << std::endl;
    } else {
        contentCMakeLists << "set(CMAKE_CXX_STANDARD 20)\n" << std::endl;
    }

    contentCMakeLists << "include_directories(include)\n" << std::endl;

    std::string path = "./";
    std::string ext = ".cpp";
    contentCMakeLists << "add_executable(" << std::endl;
    if(argc>=2) {
        contentCMakeLists << "  " << argv[1] << std::endl;
    } else {
        contentCMakeLists << "  main" << std::endl;
    }
    for(auto &pathTemp : std::filesystem::recursive_directory_iterator(path))
    {
        if(pathTemp.path().extension() == ext)
        {
            contentCMakeLists << "  " << pathTemp.path().string().erase(0, 2) << std::endl;
        }
    }
    contentCMakeLists << ")" << std::endl;
    contentCMakeLists.close();
}