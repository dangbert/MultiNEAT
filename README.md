# About MultiNEAT

MultiNEAT is a portable software library for performing neuroevolution, a form of machine learning that
trains neural networks with a genetic algorithm. It is based on NEAT, an advanced method for evolving
neural networks through complexification. The neural networks in NEAT begin evolution with very simple
genomes which grow over successive generations. The individuals in the evolving population are grouped
by similarity into species, and each of them can compete only with the individuals in the same species.

The combined effect of speciation, starting from the simplest initial structure and the correct
matching of the genomes through marking genes with historical markings yields an algorithm which
is proven to be very effective in many domains and benchmarks against other methods.

NEAT was developed around 2002 by Kenneth Stanley in the University of Texas at Austin.


### License

GNU Lesser General Public License v3.0 

### Documentation
* [latest docs webpage](https://dangbert.github.io/MultiNEAT/docs/html/files.html)
* [archived old docs](https://web.archive.org/web/20210514235617/http://multineat.com/docs.html)

Alternatively you can build the docs yourself:
````bash
# build docs:
sudo apt update && sudo apt install doxygen graphviz
doxygen ./Doxyfile

# view docs:
firefox docs/html/index.html
````


<!-- [http://multineat.com/docs.html](http://multineat.com/docs.html) -->

## Building and installation instructions

### Prerequisites

Install [Cereal](https://uscilab.github.io/cereal/)

For example on ubuntu:
````bash
sudo apt install libcereal-dev cmake
# optional: (for tests)
sudo apt install libboost-test-dev
````

If no package is available for your system, install from source.
The package is header only, so no building required.

### To install as a python library
  ```bash
  pip install .
  ```

### To install as a cpp library
  ```bash
  mkdir build && cd build
  cmake ..
  make -j4
  (sudo) make install
  ```
  
Installing options:
- if you want to install the release version without debugging symbols, add this option to the `cmake` command:
  ```
  cmake .. -DCMAKE_BUILD_TYPE=Release
  ```
  
- if you want to install the multineat in a different folder, add this option to the `cmake` command:
  ```
  cmake .. -CMAKE_INSTALL_PREFIX=/path/to/install/folder/
  ```
  
 These options may be combined togheter

### Run Tests:
````bash
mkdir build && cd build
cmake -DENABLE_TESTING=ON ..
make

# run unit tests:
make test

# view all options:
make help
````

### See also:
* [ci-group/MultiNEAT](https://github.com/ci-group/MultiNEAT)
* [peter-ch/MultiNEAT](https://github.com/peter-ch/MultiNEAT)
* [MultiNEAT/MultiNEAT](https://github.com/MultiNEAT/MultiNEAT)
