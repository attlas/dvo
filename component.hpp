#pragma once

namespace dvo{

  class component : public base<component>{
  public:
    static component_ptr create(boost::filesystem::path const id, component_ptr parent) {
      component_ptr c = base_t::create();
      c->id = id;
      c->parent = parent;
      return c;
    }
    ///
    std::string string() const;
    ///
    boost::filesystem::path const& getId() const;
    ///
    void scan(boost::filesystem::path const home);
    ///
    void ls(std::ostream& os, std::string const offset) const;
    ///
    virtual void cleanup();
    ///
    ~component();

  protected:
  private:
    ///
    boost::filesystem::path
      id;
    ///
    typedef component_ptr
      component2component_t;
    component2component_t
      parent;
    ///
    typedef std::list<component_ptr>
      component2components_t;
    component2components_t
      children;
    ///
    boost::property_tree::ptree
      attrs;
    ///
    component();

    friend class base<component>;
  };
}
