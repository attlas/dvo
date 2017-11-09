export BOOST_ROOT=~/dvo/boost-1.62.0
#export BOOST_INCLUDE=~/dvo/boost-1.62.0
#export BOOST_LIB=~/dvo/boost-1.62.0/stage/lib
cd ..
mkdir clang-debug
cd clang-debug
cmake ./../src
#-DBoost_DEBUG=ON
make
