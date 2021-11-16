# Alignment

For instance, retrieving a missaligned Data Structure of 5 bytes is more time-expensive than retrieving an 8 bytes aligned one. This is because, if your 5 "... byte data does not start on one of those 4 byte boundaries, the computer must read the memory twice, and then assemble the 4 bytes to a single register internally" (1).

Working with unaligned data requires more mathematical operations and ends in more time (and power) consumption by the ECU.

- https://en.cppreference.com/w/c/language/_Alignof
- http://web.archive.org/web/20170708093042/http://www.cs.umd.edu:80/class/sum2003/cmsc311/Notes/Data/aligned.html
- http://grok2.com/structure_packing.html
- https://stackoverflow.com/questions/3318410/pragma-pack-effect
- https://stackoverflow.com/questions/18978006/how-to-use-alignas-to-replace-pragma-pack

