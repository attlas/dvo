#include "./pch.hpp"
#include "./appl.hpp"

int main(int argc, char* argv[]){
  {
    dvo::appl_ptr a(dvo::appl::create(boost::filesystem::path("d:/dvo")));
    if (a->init(argc, argv)){
      a->run();
    }
    a->cleanup();
  }
#ifdef NDEBUG
#else
  dvo::debug::validate(std::cout);
#endif
  return 0;
}
