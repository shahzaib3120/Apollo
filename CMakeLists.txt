cmake_minimum_required(VERSION 3.5)

project(test1 VERSION 0.1 LANGUAGES CXX)
file(GLOB src CONFIGURE_DEPENDS
    "*.h"
    "*.cpp"
)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(Apollo-backend/)
#add_subdirectory(Apollo-backend/)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Eigen3 REQUIRED)
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Apollo-backend/Layers/Layer.cpp Apollo-backend/Layers/Layer.h Apollo-backend/Layers/Dense.cpp Apollo-backend/Layers/Dense.h Apollo-backend/Layers/Sigmoid.cpp Apollo-backend/Layers/Sigmoid.h Apollo-backend/Layers/Softmax.cpp Apollo-backend/Layers/Softmax.h Apollo-backend/Utils/Dataloader.cpp Apollo-backend/Utils/Dataloader.h Apollo-backend/Loss/Loss.cpp Apollo-backend/Model/Model.cpp Apollo-backend/Model/Model.h Apollo-backend/Loss/Loss.h Apollo-backend/Utils/linalg.h Apollo-backend/Utils/linalg.cpp Apollo-backend/Preprocessing/Preprocessing.h Apollo-backend/Preprocessing/Preprocessing.cpp Apollo-backend/Apollo.h )
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(test1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${src}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET test1 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(test1 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(test1
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(test1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Eigen3::Eigen)
set_target_properties(test1 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS test1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(test1)
endif()
