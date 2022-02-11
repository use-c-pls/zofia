# Zofia


# Compile and run in Mac OS (Catalina@10.15)
- Install conan
- Conan profile
````
[settings]
os=Macos
os_build=Macos
arch=x86_64
arch_build=x86_64
compiler=clang
compiler.version=12
compiler.libcxx=libc++
build_type=Release

[options]
[build_requires]
[env]
````
- Run run-mac.sh