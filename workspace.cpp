#include "./pch.hpp"
#include "./component.hpp"
#include "./workspace.hpp"

namespace dvo{
  workspace::workspace(): 
      base<workspace>()
    , cursor() {
  }

  workspace::~workspace(){
  }

  void workspace::init(component_ptr comp){
    this->cursor = comp;
  }

  std::string workspace::getPrompt() const{
    return this->cursor->string();
  }

  void workspace::cleanup(){
  }
}

