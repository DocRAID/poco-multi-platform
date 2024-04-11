cmake_minimum_required(VERSION 3.19)
project(pocotest)

set(CMAKE_CXX_STANDARD 17)


set(LIBRARY_SET
        stdc++ Poco::Foundation Poco::Net Poco::Util Poco::XML Poco::JSON Poco::NetSSL
        )

find_package(Poco REQUIRED COMPONENTS Foundation Net NetSSL Util XML JSON)
include_directories(
        Poco::Data
        Poco::DataSQLite
        Poco::Foundation
        Poco::Net
        Poco::NetSSL
        Poco::Util
)
add_executable(pocotest main.cpp)
target_link_libraries(pocotest PUBLIC Poco::Foundation Poco::Net Poco::Util Poco::XML Poco::JSON Poco::NetSSL)



