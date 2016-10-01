#pragma once

namespace dvo{

#ifdef NDEBUG
  class debug{
  };
#else
  class debug{
    public:
      debug(){
        objCount++;
        if (objCount > objTotal){
          objTotal++;
        }
      }      
      ~debug(){
        this->objCount--;
      }      
      static void validate(std::ostream& os){
        os  << std::endl
            << "Balance of created objects\t" << objCount << std::endl
            << "Total created objects\t\t" << objTotal << std::endl
        ;
      }
    protected:
    private:
    static unsigned int objCount;
    static unsigned int objTotal;
  };
#endif

  template<class T>
  class base : public boost::enable_shared_from_this<T>, public debug{
  public:
    ///
    static boost::shared_ptr<T> create() {
      return boost::shared_ptr<T>(new T());
    }
    ///
    base(){
    }
    ///
    ~base(){
    }
    ///
    virtual void cleanup() = 0;

  protected:
  private:
  };


}
