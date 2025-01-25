rdma_provider(phx
  phoenix.c
  phoenix_verbs.c
)

find_package(PhoenixSyscalls REQUIRED)

if(PhoenixSyscalls_FOUND)
  message(STATUS "PhoenixSyscalls include path: ${PHOENIX_SYSCALLS_INCLUDE_DIRS}")
  message(STATUS "PhoenixSyscalls libraries: ${PHOENIX_SYSCALLS_LIBRARIES}")

  set(DEST "phx")
  if (ENABLE_STATIC)
    target_include_directories(${DEST} PRIVATE ${PHOENIX_SYSCALLS_INCLUDE_DIRS})
    target_link_libraries(${DEST} LINK_PRIVATE ${PHOENIX_SYSCALLS_LIBRARIES})
  endif()
  set(DEST "${DEST}-rdmav${IBVERBS_PABI_VERSION}")
  target_include_directories(${DEST} PRIVATE ${PHOENIX_SYSCALLS_INCLUDE_DIRS})
  target_link_libraries(${DEST} LINK_PRIVATE ${PHOENIX_SYSCALLS_LIBRARIES})
else()
  message(FATAL_ERROR "PhoenixSyscalls not found!")
endif()