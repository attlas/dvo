#pragma once

namespace dvo{

  template<class T>
  class base : public boost::enable_shared_from_this<T>, public debug{
  public:
    ///
    base(){
    }
    ///
    ~base(){
    }
    ///
    virtual void cleanup() = 0;

  protected:
    typedef base<T>
      base_t;
    ///
    static boost::shared_ptr<T> create() {
      return boost::shared_ptr<T>(new T());
    }
  private:
  };
}
