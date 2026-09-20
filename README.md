# BSDLibC
BSDLibC is an experimental port of the NetBSD libc for Linux.

# Whats available?
- support for x86_64
- A functional stdio
- Syscall wrappers
- The crt* objects from NetBSD
- Malloc and friends (jemalloc)
- String functions
- argc, argv and envp supported
- Some compatibility functions

# Achievements
- Build a run simple commands like hello world, uname and hostname.

# Goals
- Build gcc and other GNU projects
- Build a significant part of the NetBSD userland
- Create a linux distribution using BSDLibC
