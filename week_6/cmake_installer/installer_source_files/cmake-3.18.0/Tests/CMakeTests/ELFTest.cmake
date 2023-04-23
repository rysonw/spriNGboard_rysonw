set(names
  elf32lsb.bin
  elf32msb.bin
  elf64lsb.bin
  elf64msb.bin
  )

# Prepare binaries on which to operate.
set(in "/home/ryson/spriNGboard_rysonw/week_6/cmake_installer/installer_source_files/cmake-3.18.0/Tests/CMakeTests/ELF")
set(out "/home/ryson/spriNGboard_rysonw/week_6/cmake_installer/installer_source_files/cmake-3.18.0/Tests/CMakeTests/ELF-Out")
file(REMOVE_RECURSE "${out}")
file(MAKE_DIRECTORY "${out}")
foreach(f ${names})
  file(COPY ${in}/${f} DESTINATION ${out} NO_SOURCE_PERMISSIONS)
  list(APPEND files "${out}/${f}")
endforeach()

foreach(f ${files})
  # Check for the initial RPATH.
  file(RPATH_CHECK FILE "${f}" RPATH "/sample/rpath")
  if(NOT EXISTS "${f}")
    message(FATAL_ERROR "RPATH_CHECK removed ${f}")
  endif()

  # Change the RPATH.
  file(RPATH_CHANGE FILE "${f}"
    OLD_RPATH "/sample/rpath"
    NEW_RPATH "/path1:/path2")
  set(rpath)
  file(STRINGS "${f}" rpath REGEX "/path1:/path2" LIMIT_COUNT 1)
  if(NOT rpath)
    message(FATAL_ERROR "RPATH not changed in ${f}")
  endif()

  # Change the RPATH without compiler defined rpath removed
  file(RPATH_CHANGE FILE "${f}"
    OLD_RPATH "/path2"
    NEW_RPATH "/path3")
  set(rpath)
  file(STRINGS "${f}" rpath REGEX "/path1:/path3" LIMIT_COUNT 1)
  if(NOT rpath)
    message(FATAL_ERROR "RPATH not updated in ${f}")
  endif()

  # Change the RPATH with compiler defined rpath removed
  file(RPATH_CHANGE FILE "${f}"
    OLD_RPATH "/path3"
    NEW_RPATH "/rpath/sample"
    INSTALL_REMOVE_ENVIRONMENT_RPATH)
  set(rpath)
  file(STRINGS "${f}" rpath REGEX "/rpath/sample" LIMIT_COUNT 1)
  if(NOT rpath)
    message(FATAL_ERROR "RPATH not updated in ${f}")
  endif()
  file(STRINGS "${f}" rpath REGEX "/path1" LIMIT_COUNT 1)
  if(rpath)
    message(FATAL_ERROR "RPATH not removed in ${f}")
  endif()

  # Remove the RPATH.
  file(RPATH_REMOVE FILE "${f}")
  set(rpath)
  file(STRINGS "${f}" rpath REGEX "/rpath/sample" LIMIT_COUNT 1)
  if(rpath)
    message(FATAL_ERROR "RPATH not removed from ${f}")
  endif()

  # Check again...this should remove the file.
  file(RPATH_CHECK FILE "${f}" RPATH "/sample/rpath")
  if(EXISTS "${f}")
    message(FATAL_ERROR "RPATH_CHECK did not remove ${f}")
  endif()
endforeach()
