include (ExternalProject)

set( Eigen3_VERSION "3.3.3" )
set(eigen_URL "http://bitbucket.org/eigen/eigen/get/${Eigen3_VERSION}.tar.bz2")
set(EIGEN_INCLUDE_DIRS "${PROJECT_BINARY_DIR}/include/eigen")

add_definitions(-DEIGEN_USE_BLAS)
find_package(BLAS REQUIRED)
ExternalProject_Add(eigen
    PREFIX eigen
    URL ${eigen_URL}
    DOWNLOAD_DIR "${DOWNLOAD_LOCATION}"
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND cp -r Eigen unsupported ${EIGEN_INCLUDE_DIRS}
    INSTALL_DIR ${EIGEN_INCLUDE_DIRS})
add_definitions(-DHAS_EIGEN)

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

macro(requires_eigen NAME)
  target_link_libraries(${NAME} ${BLAS_LIBRARIES})
  target_link_libraries(${NAME} ${LAPACK_LIBRARIES})
  add_dependencies(${NAME} eigen)
endmacro(requires_eigen)









#set( Eigen3_VERSION "3.3.3" )
#
#set(EIGEN_INSTALL "${PROJECT_BINARY_DIR}/include/eigen")
#
#add_definitions(-DEIGEN_USE_BLAS -DEIGEN_USE_LAPACKE)
#find_package(BLAS REQUIRED)
#ExternalProject_Add(eigen
#    PREFIX eigen
#    URL "http://bitbucket.org/eigen/eigen/get/${Eigen3_VERSION}.tar.bz2"
#    DOWNLOAD_DIR "${DOWNLOAD_LOCATION}"
#    CONFIGURE_COMMAND ""
#    BUILD_COMMAND ""
#    BUILD_IN_SOURCE 1
#    INSTALL_COMMAND cp -r Eigen unsupported ${EIGEN_INSTALL}
#    INSTALL_DIR ${EIGEN_INSTALL})
#add_definitions(-DHAS_EIGEN)

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

macro(requires_eigen NAME)
  target_link_libraries(${NAME} ${BLAS_LIBRARIES})
  target_link_libraries(${NAME} ${LAPACK_LIBRARIES})
  add_dependencies(${NAME} eigen)
endmacro(requires_eigen)