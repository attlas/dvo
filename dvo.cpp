#include "./pch.hpp"
#include "./appl.hpp"

int main(int argc, char* argv[]){
  std::cout << "Hello world!" << std::endl;
  {
    dvo::appl_ptr a(dvo::appl::create());
    if (a->init(argc, argv)){
      a->run();
    }
    a->cleanup();
  }
#ifdef NDEBUG
#else
  dvo::debug::validate(std::cout);
#endif

  std::cout << "Bye world!" << std::endl;
  return 0;
}
