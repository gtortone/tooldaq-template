
# ToolDAQ Application template

This template can be used to develop a brand new ToolDAQ toolchain with minimal effort.

## Usage

- Provides ToolFrameworkCore and ToolDAQFramework libraries in the same directory (e.g. /opt)

```
git clone https://github.com/ToolFramework/ToolFrameworkCore.git

cd ToolFrameworkCore
make clean
make
```

```
git clone https://github.com/ToolDAQ/ToolDAQFramework.git

cd ToolDAQFramework
make clean
make
```

- Modify `setup.sh` script (`TOOLFW_BASEDIR`, `TOOLDAQ_BASEDIR`) with paths of ToolFrameworkCore and ToolDAQFramework libraries

- Install following libraries with your package manager utility

```
boost_date_time
boost_iostreams
boost_serialization
cppzmq
```

- `source setup.sh` and you are ready to write/build your ToolDAQ application !

