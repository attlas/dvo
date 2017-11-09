#pragma once

namespace dvo{

  class workspace : public base<workspace>{
  public:
    static workspace_ptr create(component_ptr comp) {
      workspace_ptr w = base_t::create();
      w->cursor = comp;
      return w;
    }
    ///
    std::string getPrompt() const;
    ///
    component_ptr getCursor() const;
    ///
    virtual void cleanup();
    ///
    ~workspace();

  protected:
  private:
    typedef component_ptr
      workspace2cursor_t;
    workspace2cursor_t
      cursor;
    ///
    workspace();

    friend class base<workspace>;
  };
}
