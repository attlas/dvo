#include "./pch.hpp"
#include "./component.hpp"
#include "./workspace.hpp"
#include "./appl.hpp"

namespace dvo{
  appl::appl() : 
      base<appl>()
    , home()
    , rootComponent()
    , currentWorkspace()
    , workspaces(){
  }

  appl::~appl(){
  }

  bool appl::init(int argc, char* argv[]){
    this->home = boost::filesystem::path("d:/dvo");
    //
    this->rootComponent = component::create();
    this->rootComponent->init(boost::filesystem::path("boost-1.61.0"));
    //
    this->currentWorkspace = workspace::create();
    this->currentWorkspace->init(this->rootComponent);
    this->workspaces.push_back(this->currentWorkspace);
    return true;
  }

  void appl::run(){
    std::istream& is = std::cin;
    std::ostream& os = std::cout;
    //
    std::string str;
    while (true) {
      os << this->home.string() << ":" << this->currentWorkspace->getPrompt() << "> ";
      std::getline(is, str);
      os << str << std::endl;
      if (str == "exit"){
        break;
      }
    }
  }

  void appl::cleanup(){
    this->currentWorkspace.reset();
    //
    BOOST_FOREACH(workspace_ptr w, this->workspaces){ w->cleanup(); }
    this->workspaces.clear();
    //
    this->rootComponent->cleanup();
    this->rootComponent.reset();
  }
}









#if 0
    std::string str;
  os << "> ";
  while (true) {
      char c;
      //c = _getch();
      c = getchar();
       os << c;
       printf("%d", c);
    //is.getline(&c, 1);
      if (c == '\r' || c == '\n'){
    os << std::endl << str << std::endl;
        if (str == "exit"){
          break;
        }
        str = "";
    os << "> ";
    }
    else{
        str += c;
      }
      //
    }

#endif
