#include "./pch.hpp"
#include "./component.hpp"

namespace dvo{

  component::component() : 
      base<component>()
    , id()
    , parent()
    , children()
    , attrs() {
  }

  component::~component(){
  }

  std::string component::string() const{
    return this->id.string();
  }

  boost::filesystem::path const& component::getId() const{
    return this->id;
  }

  void component::scan(boost::filesystem::path const home){
    this->children.push_back(component::create(boost::filesystem::path("boost-1.62.0"), this->shared_from_this()));
    this->children.push_back(component::create(boost::filesystem::path("php-7.0.11-x86-x64"), this->shared_from_this()));
  }

  void component::ls(std::ostream& os, std::string const offset) const{
    os << "?" << offset << this->string() << std::endl;
    std::string const o = offset + " ";
    BOOST_FOREACH(component_ptr c, this->children){
      c->ls(os, o);
    }
  }

  void component::cleanup(){
    BOOST_FOREACH(component_ptr c, this->children){
      c->cleanup();
    }
    this->children = component2components_t();
    this->parent = component_ptr();
  }
}

