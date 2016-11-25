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

  std::string workspace::getPrompt() const{
    return this->cursor->string();
  }

  component_ptr  workspace::getCursor() const{
    return this->cursor;
  }

  void workspace::cleanup(){
  }
}

