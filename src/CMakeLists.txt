cmake_minimum_required(VERSION 3.5)

project(Aoralscan)

# find_package(PCL 1.9 REQUIRED COMPONENTS common io)
find_package(PCL 1.9 REQUIRED)

# include_directories(${PCL_INCLUDE_DIRS})
add_definitions(${PCL_DEFINITIONS})

# Qt库查询
set(Qt5_DIR $ENV{QT590}/lib/cmake/Qt5)
message(${Qt5_DIR})
set(ACTIVE_QT_DIR $ENV{QTDIRMSVC})

# Qt查询路径
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${ACTIVE_QT_DIR}")
set(INSTALL_PREFIX_INITIALIZED ${CMAKE_CURRENT_SOURCE_DIR}/build/install CACHE STRINGS "change prefix")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(RESOURCE_DIR MedicalVisualization.qrc)
find_package(Qt5 REQUIRED Widgets Core)
qt5_wrap_cpp( MOC widget.h)
qt5_wrap_ui( UIC widget.ui)
qt5_add_resources(RCC MedicalVisualization.qrc)

# 库目录
# link_directories(${PCL_LIBRARY_DIRS})
link_directories(${PCL_ROOT}/3rdParty/OpenNI2/Lib)
link_directories(${PCL_ROOT}/D:/PCL 1.9.1/3rdParty/VTK/lib)
link_directories(${PCL_ROOT}/D:/PCL 1.9.1/3rdParty/Qhull/lib)
link_directories(${PCL_ROOT}/D:/PCL 1.9.1/3rdParty/FLANN/lib)
link_directories(${PCL_ROOT}/D:/PCL 1.9.1/3rdParty/Boost/lib)
link_directories(${PCL_ROOT}/D:/PCL 1.9.1/lib)

# 包含目录
include_directories(${PCL_ROOT}/3rdParty/OpenNI2/Include)
include_directories(${PCL_ROOT}/3rdParty/VTK/include/vtk-8.1)
include_directories(${PCL_ROOT}/3rdParty/Qhull/include)
include_directories(${PCL_ROOT}/3rdParty/FLANN/include)
include_directories(${PCL_ROOT}/3rdParty/Eigen/eigen3)
include_directories(${PCL_ROOT}/3rdParty/Boost/include/boost-1_68)
include_directories(${PCL_ROOT}/include/pcl-1.9)

# 查找源文件
aux_source_directory(. DIR_SRCS)

# 查找头文件
file(GLOB HEADER ./*.h ./*.h++)

set(EXE_NAME Aoralscan)
add_executable(${EXE_NAME} ${DIR_SRCS} ${HEADER})

target_link_libraries(${EXE_NAME} ${PCL_LIBRARIES} Qt5::Widgets)
# target_link_libraries(pcd_write_test ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})