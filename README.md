# extended_heptane_svn
The extended heptane to calculate the cache interference between two benchmarks
Contents:
------------

- src: source code of Heptane (extraction of control flow graphs +
  WCET estimation tool itself, management of control flow graphs)

- benchmarks: some pre-compiled benchmarks to run Heptane. 
  Subset of the Mälardalen WCET Benchmarks,
  http://www.mrtc.mdh.se/projects/wcet/benchmarks.html

- doc: basic documentation to install and use Heptane

- install.sh: installation script (the configuration and installation
  parameters have to be set up before running the script)

- tools: cross-compiler toolchain + salto tool (salto is an assembly
  manipulation library used to extract CFGs) + cache simulator

How to install all this?
------------------------

See html file index.html in directory doc on how to use the
install.sh script
