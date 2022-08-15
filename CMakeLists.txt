cmake_minimum_required(VERSION 3.1)

project(Nodawa VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

#set the default build type as release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-O2")

#link wxWidgets to the executable
find_package(wxWidgets 3.1 REQUIRED COMPONENTS net core base)

if(wxWidgets_FOUND)
  message("-- You have wxWidgets installed in system, so no need to install it again.")
  include(${wxWidgets_USE_FILE})
  add_executable(Nodawa src/application.cpp src/frame.cpp)
  target_link_libraries(Nodawa ${wxWidgets_LIBRARIES})

#if wxwidgets is not found
else(NOT wxWidgets_FOUND)
    if(LINUX)
     message("---You are running Linux---")
     message("--You do not have wxWidgets installed.")
     message("--installing it in progress...")
    
     #check the linux disto
     find_file(ARCH_FOUND arch-release
               PATHS /etc
              )
     if(ARCH_FOUND)
       message(STATUS "--You are running Arch Linux, installing wxWidgets using pacman...")
       
       #install wxWidgets using pacman
       execute_process (
       COMMAND bash -c "pacman -S wxgtk3 && pacman -S wxgtk-common"

     )

       message("--building the program again:")
       find_package(wxWidgets 3.0 REQUIRED COMPONENTS net core base)
       include(${wxWidgets_USE_FILE})
       add_executable(Nodawa src/application.cpp src/frame.cpp)
       target_link_libraries(Nodawa ${wxWidgets_LIBRARIES})

     endif(ARCH_FOUND)
   
       #check for debian
       find_file (DEBIAN_BASED_FOUND debian_version OR ubunto_version OR kubunto_version
       PATHS /etc
       )
     if (DEBIAN_FOUND)
       message(STATUS "--You are running Debian, installing wxWidgets using APT...")
      
       #install wxWIdgets using apt
       execute_process (
       COMMAND bash -c "apt install libwxgtk3.0-dev"

       )

       message("--building the program again:")
       find_package(wxWidgets 3.0 REQUIRED COMPONENTS net core base)
       include(${wxWidgets_USE_FILE})
       add_executable(Nodawa src/application.cpp src/frame.cpp)
       target_link_libraries(Nodawa ${wxWidgets_LIBRARIES})

     endif (DEBIAN_FOUND)

     ##  Check for Fedora

     find_file (FEDORA_FOUND fedora-release
        PATHS /etc
        )
     if (FEDORA_FOUND)
        message(STATUS "--You are running Fedora Linux, installing wxWidgets using dnf...")
     
        #install wxWIdgets using dnf
        execute_process (
        COMMAND bash -c "dnf install wxGTK3-devel"
      
        )
        message("--building the program again:")
        find_package(wxWidgets 3.0 REQUIRED COMPONENTS net core base)
        include(${wxWidgets_USE_FILE})
        add_executable(Nodawa src/application.cpp src/frame.cpp)
        target_link_libraries(Nodawa ${wxWidgets_LIBRARIES})
     endif (FEDORA_FOUND)

   endif(LINUX)

endif(wxWidgets_FOUND)

include(CPack)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/Nodawa DESTINATION bin)