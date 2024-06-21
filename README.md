# DNS-Lookup-using-Splay-Trees

Introduction
Splay trees can be utilized as an effective data structure for fast DNS lookup, particularly when access patterns are skewed, such as in scenarios where 20% of the data is accessed 80% of the time. The structure and properties of splay trees make them well-suited for this application.

Structure and Operation
A splay tree is structured as a self-adjusting binary search tree.
In DNS lookup applications, nodes typically represent domain names or IP addresses.
The key feature, the splay operation, is performed after every access, insertion, or deletion.
This operation moves the accessed node to the root of the tree.

Splay trees have six types of rotations used for splaying:
- Zig rotation (Right rotation)
- Zag rotation (Left rotation)
- Zig zag (Zig followed by zag)
- Zag zig (Zag followed by zig)
- Zig zig (two right rotations)
- Zag zag (two left rotations)

Adaptation to Access Patterns
The splay operation causes frequently accessed nodes (e.g., popular domain names) to be maintained near the root of the tree. This characteristic aligns well with the aforementioned 80-20 rule of access patterns.

Benefits for DNS Lookup
Lookups for popular domains are expedited, potentially approaching O(1) time for very frequent accesses.
The tree effectively functions as a self-organizing cache, automatically optimizing for frequently accessed items.

Time Complexity
Amortized Complexity
All standard operations (insert, delete, search): O(log n)

Worst-case Complexity
Single operation: O(n)

It should be noted that the amortized analysis is generally more relevant in practical applications, especially for DNS lookups with skewed access patterns. This is due to several factors:
- While a single operation may occasionally require O(n) time, this is compensated for by numerous faster operations.
- Items accessed frequently often achieve better-than-O(log n) performance, approaching O(1) for the most common lookups.
- The self-adjusting nature of splay trees allows them to adapt automatically to evolving access patterns without manual intervention.

Instructions to run:
Have gcc and make installed using WSL or Ubuntu
then run the following commands:
make clean
make
./st

Made as a part of my DSA 2 Project.