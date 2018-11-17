cmake_minimum_required(VERSION 3.12)
project(PackageDelieveryService)

set(CMAKE_CXX_STANDARD 14)

add_executable(PackageDelieveryService main.cpp Package.cpp Client.cpp TwoDayPackage.cpp OvernightPackage.cpp ../Shape/TwoDimentionalShape.cpp ../Shape/ThreeDimentionalShape.cpp ../Shape/TwoDShapes.cpp ../Shape/ThreeDShape.cpp ../Shape/Shape.cpp ../Shape/main.cpp package_details.cpp)