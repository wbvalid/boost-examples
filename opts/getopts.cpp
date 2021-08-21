#include <boost/program_options.hpp>
#include <string>
#include <iostream>

namespace opt = boost::program_options;

int main(int argc, char *argv[])
{
    opt::options_description desc("All options");

    desc.add_options()("help,h", "produce help message")("file", opt::value<std::string>()->default_value("input.txt"), "set file to read")("out", opt::value<std::string>()->default_value("output.txt"), "set output file name");
    opt::variables_map vm;
    opt::store(opt::parse_command_line(argc, argv, desc), vm);
    opt::notify(vm);
    if (vm.count("help"))
    {
        std::cout << desc << '\n';
        exit(EXIT_FAILURE);
    }
    if (vm.count("file"))
    {
        std::cout << "file = " << vm["file"].as<std::string>() << '\n';
    }
    if (vm.count("out"))
    {
        std::cout << "output file = " << vm["out"].as<std::string>() << '\n';
    }
    return 0;
}