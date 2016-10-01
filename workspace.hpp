#pragma once

namespace dvo{

  class workspace : public base<workspace>{
  public:
    ///
    void init(component_ptr comp);
    ///
    std::string getPrompt() const;
    ///
    virtual void cleanup();
    ///
    ~workspace();

  protected:
  private:
    typedef component_ptr
      workspace2cursor_component;
    workspace2cursor_component
      cursor;
    ///
    workspace();

    friend class base<workspace>;
  };
}
