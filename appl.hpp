#pragma once

namespace dvo{

  class appl : public base<appl>{
  public:
    ///
    bool init(int argc, char* argv[]);
    ///
    void run();
    ///
    virtual void cleanup();
    ///
    ~appl();
  protected:
  private:

    boost::filesystem::path
      home;
    ///
    component_ptr
      rootComponent;
    ///
    workspace_ptr
      currentWorkspace;
    typedef std::vector<workspace_ptr>
      appl2workspaces;
    appl2workspaces
      workspaces;

    ///
    appl();

    friend class base<appl>;
  };
}
