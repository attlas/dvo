#include "./pch.hpp"
#include "./component.hpp"

namespace dvo{

  component::component() : base<component>(), id(), attrs() {
  }

  component::~component(){
  }

  void component::init(boost::filesystem::path const path){
    this->id = path;
  }

  std::string component::string() const{
    return this->id.string();
  }

  boost::filesystem::path const& component::getId() const{
    return this->id;
  }

  void component::cleanup(){
  }
}

