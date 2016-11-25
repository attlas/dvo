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
}
