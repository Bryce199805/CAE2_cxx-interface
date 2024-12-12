# C++ Interface

```shell
# build with filesystem
cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX=D:/libCAEFILE .. -DUSE_FILESYSTEM=ON
make 
make install

# build without filesystem
cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX=D:/libCAE .. -DUSE_FILESYSTEM=OFF
make 
make install
```
## ATTENTION!!
Character encoding set as gb18030.