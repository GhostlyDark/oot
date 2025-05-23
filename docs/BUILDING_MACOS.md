# Building on macOS

**N.B.** C++17 is required to build the asset processing program that we use (ZAPD), so check your OS version can support this before proceeding.


## 1. Dependencies

For macOS, use Homebrew to install the following dependencies:

* coreutils
* make
* python3
* libpng
* bash
* clang-format
* libxml2
* libiconv

You can install them with the following commands:

```bash
brew update
brew install coreutils make python3 libpng bash clang-format libxml2 libiconv
```

(The repository expects Homebrew-installed programs to be either linked correctly in `$PATH` etc. or in their default locations.)


## 2. Building mips-linux-binutils

The following instructions are written for MacOS users but should apply to any Unix-like system, with maybe some modifications at the end regarding the bash_profile.

Create destination dir for binutils
```bash
sudo mkdir -p /opt/cross
```

Create and enter local working dir
```bash
mkdir ~/binutils-tmp
cd ~/binutils-tmp
```

Get and extract binutils source
```bash
curl -O https://ftp.gnu.org/gnu/binutils/binutils-2.35.tar.bz2
tar xjf binutils-2.35.tar.bz2
```

Create and enter a build directory
```bash
mkdir build-binutils
cd build-binutils
```

Configure the build
```bash
../binutils-2.35/configure --target=mips-linux-gnu --prefix=/opt/cross --with-system-zlib --disable-gprof --disable-gdb --disable-werror
```

Make and install binutils
```bash
make -j$(nproc)
sudo make install
```

Edit your `~/.bash_profile`/`~/.zprofile` (or whichever shell you use) to add the new binutils binaries to the system PATH
```bash
echo 'export PATH="$PATH:/opt/cross/bin"' >> ~/.bash_profile
```

Reload `~/.bash_profile` (or just launch a new terminal tab)
```bash
source ~/.bash_profile
```

If this worked, you can now delete the temporary directory `~/binutils-tmp`.


## 3. Final note

Apple's version of `make` is very out-of-date, so you should use the brew-installed `gmake` in place of `make` in this repo from now on.

You should now be able to continue from [step 2](../README.md#2-clone-the-repository) of the Linux instructions.


## 4. Building GCC (optional)

If you'd like to compile with GCC instead of IDO (e.g. for modding), you can build it from source similarly to how we built binutils:

Install dependences
```bash
brew install gcc@14 gmp isl libmpc mpfr
```

Create and enter local working dir
```bash
mkdir ~/gcc-tmp
cd ~/gcc-tmp
```

Get and extract gcc source
```bash
curl -O https://ftp.gnu.org/gnu/gcc/gcc-14.2.0/gcc-14.2.0.tar.xz
tar xvf gcc-14.2.0.tar.xz
```

Create and enter a build directory
```bash
mkdir build-gcc
cd build-gcc
```

Configure the build
```bash
CC=gcc-14 CXX=g++-14 ../gcc-14.2.0/configure --target=mips-linux-gnu --prefix=/opt/cross --disable-nls --enable-languages=c --with-gmp=$(brew --prefix)/opt/gmp --with-mpfr=$(brew --prefix)/opt/mpfr --with-mpc=$(brew --prefix)/opt/libmpc --with-isl=$(brew --prefix)/opt/isl
```

Make and install gcc
```bash
CC=gcc-14 CXX=g++-14 make all-gcc -j$(nproc)
sudo make install-gcc
```

If this worked, you can now delete the temporary directory `~/gcc-tmp`.
