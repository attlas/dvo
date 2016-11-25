#include "./pch.hpp"
#include "./component.hpp"
#include "./workspace.hpp"
#include "./appl.hpp"

namespace dvo{
  //
  std::string const appl::dvoVersion = "0.1.0";
  //
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
    this->workspaces.push_back(this->currentWorkspace = workspace::create(this->rootComponent = component::create(boost::filesystem::path("/"), component_ptr())));
    this->rootComponent->scan(this->home);
    return true;
  }

/*
  [-r|--recursive]
  [*] filter

  > help - display help
  > update - update repos in .dvo at current level [-r]
  > push - push all changes from .dvo repos
  > reload - reset all loaded components and load again
  > ls [-r][*] - list available component at the current level
  > exit

  > <goal>[;<goal>[;...]] [<comp>[;<comp>[;...]]] - execute set of goals on set of components 

  > ws ls - list of all availabe workspaces
  > ws checkout <ws_name> [--create|-c]
  - switch or create_and_switch to the new workspace
  > ws remove <ws_name> - delete workspace

*/
  void appl::run(){
    std::istream& is = std::cin;
    std::ostream& os = std::cout;
    //
    os << "--- DevOps helper [" << appl::dvoVersion << "] ---" << std::endl;
    //
    std::string str;
    while (true) {
      os << "[" << this->home.string() << "]:" << this->currentWorkspace->getPrompt() << "> ";
      std::getline(is, str);
      os << str << std::endl;
      if (str == "exit"){
        break;
      } else if (str == "ls"){
        this->currentWorkspace->getCursor()->ls(os, " ");
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
