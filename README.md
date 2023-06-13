# mBox Software
This repository contains the software that is intended to run on the mBox Payload Application Computer for DTV guidance. In the frame of the FLPP-funded _On-board Real-Time Trajectory Generation Phase 2.2_ (OBRTTG) project, the mBox will be integrated on the Demonstrator for Technology Validation (DTV) vehicle to validate the OBRTTG guidance algorithms during real flights.

This software is released under [MIT license](./LICENSE).

#### Version
0.2.1

## Directory structure
- `cmake` CMake architecture and helper files.
- `codegen` source code automatically generated from Simulink.
- `communication` source code required to for the I/O mBox communication interface.
- `dependencies` external libraries required by the mBox software:
    - `gtest` for unit testing.
    - `message_thread` libembotech utilities for employed for inter-process communication.
    - `msgpack-c` serialization library for logging.
- `doc` documentation files.
- `logging` source code for logging.
- `main` source code for the main programs. 
- `msgpack_parser` files to build `mex` executable to parse logging msgpack files.
- `obrttg` source code integrating the components of the OBRTTG software.
- `utils` source and headers for miscellaneous utilities.

## Requisites
- Linux-based Operating System (e.g. Windows Subsystem for Linux);
- gcc/g++ 9.3.0 or higher;
- CMake 3.13 or higher;
- Scheduling priviledges. `OptimalTrajectoryPlanner` class uses `pthread_setschedparam` to configure the execution policy and priority of the OTP thread. Scheduling priviledges can be obtained in different ways:
    - by running `mbox-obrttg-software` executable as `sudo` (could be inconvenient for automated launching of the program)
        `sudo mbox-obrttg-software` 
    - by setting the niceness of the `mbox-obrttg-software` executable and running it normally (needs to be configured everytime the executable is re-built)
        `sudo setcap cap_sys_nice+ep ./mbox-obrttg-software`
    - by modifying the scheduling priority and real-time priority limits in `/etc/security/limits.conf`. The following lines added to this file give full scheduling priviledges to user `John`
        ```
        John        hard    rtprio          99
        John        soft    rtprio          99
        John        hard    nice            -20
        John        soft    nice            -20
        ```
    The OS needs to be rebooted for these changes to take effect. One can check that the limits are effectively modified by running `ulimit -e` and `ulimit -r` (should return 40 and 99 respectively)

#### Scheduling priviledges on WSL
Changes made in `/etc/security/limits.conf` will not directly have an effect when working on WSL. This is because `limits.conf` is a PAM construct and requires PAM to be called at log in.
It seems that there is not an actual _log in_ in WSL, so some workarounds are required to get the changes to take effect.

As detailed in this [post](https://askubuntu.com/questions/1326406/ulimit-n-command-shows-no-change-inspite-of-modifying-the-etc-security-limits) and this [github issue](https://github.com/Microsoft/WSL/issues/1688#issuecomment-518802498),
a workaround is to switch users using `su $USER`, which will ask the user to introduce `$USER` password. 

If manually introducing the password when running `su $USER` is a problem, this [post](https://unix.stackexchange.com/questions/113754/allow-user1-to-su-user2-without-password) yet another workaround.
Open `/etc/pam.d/su` and, underneath the `pam_rootok.so` line add the following:
```
auth  [success=ignore default=1] pam_succeed_if.so user = <user2>
auth  sufficient                 pam_succeed_if.so use_uid user = <user1>
```
replacing `<user1>` and `<user2>` with the correct values. In the general case, `<user1>` is the user we are logged in when running `su <user2>`. In this particular case, `<user1>` and `<user2>` are both equal to the output of `echo $USER`.

### Development requisites
Additionally, the following tools are required for development:
- `python 3.6+` can be installed in Linux with the command
```
sudo apt-get install python3
```
- `pip3` Python package manager can be installed in Linux with the command:
```
sudo apt-get install python3-pip
```
- `bump2version` for version increments
```
pip3 install --upgrade bump2version
```
- `dos2unix` for CRLF to LF line endings replacements in `update_codegen.py`
```
sudo apt-get install dos2unix
```
- [**Recommended**] **Visual Studio Code** editor can be installed from the binaries available in the [official website](https://code.visualstudio.com/)
- [**Cross-compilation**] **g++-aarch64-linux-gnu** (tested with version 9.4.0)
```
sudo apt-get install g++-aarch64-linux-gnu
```


## How To ...

### Build
- Populate `communication/incaslib` directory with a supported `incaslib` version.
- Create `build` folder in the root directory:
    `mkdir build`
- Go to build directory
    `cd build` 
- Configure CMake project
    `cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=../cmake/x86_64.cmake  -DCMAKE_BUILD_TYPE=<build_type> -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON ..`
    with appropriate values for:
        - `<build_type>` : `DEBUG` or `RELEASE`
- Build project
    `cmake --build . -j4`

### Cross-compile
Same procedure as for the host build, except from the configuration step:
```
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=../cmake/aarch64.cmake  -DCMAKE_BUILD_TYPE=<build_type> -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON ..`
```

### Run
After a successful build, the unit tests and the mBox software is run as follows:

#### Unit tests
- `cd build`
- `./obrttgUnitTests`

#### mBox software
- `cd build/main`
- `./mbox-obrttg-software`

The `mbox-obrttg-software` will initialize the different modules and will wait until it detects a successful connection with the OBC.

### Generate bin release (Development only)
To generate a bin release package, just run the `scripts/generate_release_bin.sh` script. This will create a folder in the repository root named `release_v<version>`.

### Generate source release (Development only)
To generate a release package, just run the `scripts/generate_release_source.sh` script. This will create a folder in the repository root named `release_v<version>`.

### Version increments (Development only)
The `bumpversion` configuration is stored in the file `.bumpversion.cfg`. This file lists all the files in which the version number is to be updated.

The following commands executed from the repository root (on a Linux OS) increment different parts of the version number:
```
bumpversion major       # Major version increment (e.g. 1.2.3 -> 2.0.0)
bumpversion minor       # Minor version increment (e.g. 1.2.3 -> 1.3.0)
bumpversion patch       # Patch version increment (e.g. 1.2.3 -> 1.2.4)
```

## Third-party dependencies
- [`gtest`](https://github.com/google/googletest)
- [`msgpack-c`](https://github.com/msgpack/msgpack-c/tree/6e7deb809120881634b3ca895e66b2a946084f34)
- [`incaslib`](./communication/incaslib)