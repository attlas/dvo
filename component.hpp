#pragma once

namespace dvo{

  class component : public base<component>{
  public:
    ///
    void init(boost::filesystem::path const path);
    ///
    std::string string() const;
    ///
    boost::filesystem::path const& getId() const;
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
    boost::property_tree::ptree
      attrs;
    ///
    component();

    friend class base<component>;
  };
}
