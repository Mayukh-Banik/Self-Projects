**Basic Tensor Functions**

The goal of this project is to effectively write the entirety
of all of Numpy's functions that they list on their website 
from scratch, and to ensure that it runs on a Linux system,
along with supporting CUDA at a later date.

Installation:

Since it is currently under development, just copy the entirety 
of the github page onto a file that is running a Debian based 
system with Gtest running globally and just run make clean debug.
The Makefile has numerous bugs resulting in make clean debug being 
the only way to ensure every piece of code is up to date. 

So far the project is being developed with tests, as of a later 
unknown date, the goal is to combine the entirety of the project
into a single header file to allow for easy combination with other 
projects to assure easy access to internal methods. 

Numpy Methods:
Empty - Complete
Eye - Complete
Identity - Complete
Ones - Complete
Zeros - Complete
Full - Complete
Array
FromFile
FromFunction
Fromiter
Fromstring
Loadtxt
Arrange
Linspace
Logspace
Geomspace
Meshgrid
Diag
Tri
Tril
Triu
Vander
Mat
Bmat
