sudo apt-get install cmake
unzip gtest.zip
mkdir /usr/src/gtest
cd gtest
cp -r * /usr/src/gtest
cd /usr/src/gtest
cmake CMakeLists.txt
make
cd lib
cp *.a /usr/lib
