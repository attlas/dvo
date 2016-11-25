#pragma once

#include <iostream>
#include <vector>

#include <boost/smart_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

//#include <boost/function.hpp>
//#include <boost/foreach.hpp>
//#include <boost/lexical_cast.hpp>
//#include <boost/algorithm/string/replace.hpp>
//#include <boost/regex.hpp>



#include "debug.hpp"
#include "base.hpp"

namespace dvo{
  //
  class logger;
  typedef boost::shared_ptr<logger>
    logger_ptr;
  //
  class workspace;
  typedef boost::shared_ptr<workspace>
    workspace_ptr;
  //
  class context;
  typedef boost::shared_ptr<context>
    context_ptr;
  //
  class component;
  typedef boost::shared_ptr<component>
    component_ptr;
  //
  class appl;
  typedef boost::shared_ptr<appl>
    appl_ptr;
}