NAME - LAKSHYA CHOUDHARY

REG NO. - RA2511028010011

PROFILE HANDLE FOR CSES - laksh@1247

EXPLANATION FOR EACH SOLUTION -

QUESTION 1 -> FACTORY MACHINES

WHAT I THOUGHT ?

I needed a maximum possible timing through which i can allocate the products without wasting as i knew that the machine which takes minimum timing to make one product if i allocate all the products to that machine lets say products are t so time would be time = t * (time taken by that machine) so this would be my minimum time. Now time can range from [0 - time], i just need to find minimum possible timing through which i can make atleast t products.

1) just do linear search [0-time] and check how many products each machine would make. Checking one timing takes O(n), so checking every possible timing takes O(n * U), where U is the upper bound on time. Since U can be very large, this would give TLE.

2) OPTIMIZATION

instead of linear search apply binary search for the minimum possible time. Binary search takes O(log(U)) checks, and each check takes O(n), so the time complexity would be O(n * log(U)). This is appropriate for the input limit given.

SPACE COMPLEXITY (O(1))

QUESTION 2 -> MOVIE FESTIVAL

WHAT I THOUGHT ?

basic overlapping interval question if the boundaries of 2 movie collide we cannot watch them so choose accordingly.

1) using recursion either select to watch that movie or not watch that movie time complexity = O(2^(N)) where n is total movies for constraints 10^5 will give TLE.

2) OPTIMIZATION

-> initially thought select movie with least duration this wont work as duration does not correlate with maximum movie number as even if it is less it can collide with many other movies.

-> then i thought what if i choose the movie which is ending earliest as chances of it colliding with the other movies will be least so just sort the intervals on the basis of ending time and count non-overlapping movies. A movie can be selected if its starting time is greater than or equal to the ending time of the previously selected movie.

TIME COMPLEXITY (O(N log N))

SPACE COMPLEXITY (O(1) excluding sorting implementation details)

QUESTION 3 -> SUBARRAY SUMS II

WHAT I THOUGHT ?

very similar to 2 sum. If the target subarray sum is x and the current prefix sum is y, we need an earlier prefix sum equal to y-x.

1) BRUTE FORCE

try every possible subarray by choosing its starting and ending positions and calculate its sum. Maintain a running sum while extending the ending position and increment the answer whenever the sum equals x.

TIME COMPLEXITY (O(N^2))

SPACE COMPLEXITY (O(1) excluding the input array)

2) OPTIMIZATION

maintain a prefix sum and store the frequency of prefix sums seen before in an unordered_map. For each current prefix sum y, add the frequency of (y-x) to the answer. Then increase the frequency of y. Initially, set the frequency of prefix sum 0 to 1 to handle subarrays starting from index 0.

TIME COMPLEXITY (O(N) expected)

SPACE COMPLEXITY (O(N))

KEY DIFFERENCE BETWEEN BOTH APPROACHES

The brute-force approach checks every possible subarray, which takes O(N^2) time and becomes too slow for large inputs. The optimized approach uses prefix sums and a hash map to count valid subarrays without checking each one individually. This reduces the expected time complexity to O(N), using O(N) additional space.


QUESTION 4 -> COUNTING ROOMS

WHAT I THOUGHT ?

This is a standard number of components in a graph.

APPROACH -> use the grid and a visited matrix. Whenever a cell which is not a wall and is not visited comes this is a new component, so count it and completely traverse all connected cells using BFS/DFS. Mark all visited cells and keep on repeating this. We can directly check the four neighboring cells, so an adjacency matrix is not needed.

TIME COMPLEXITY -> O(N*M) where N is the number of rows and M is the number of columns.

SPACE COMPLEXITY -> O(N*M) for the visited matrix and BFS/DFS in the worst case.

QUESTION 5 -> SHORTEST ROUTES I

WHAT I THOUGHT ?

We need to find the shortest distance from city 1 to every other city in a directed weighted graph. Since the weights are non-negative, we can use Dijkstra's algorithm.

1) BRUTE FORCE

one approach is to try all possible paths from city 1 to every other city and choose the path with minimum total weight. There can be exponentially many paths, so this would give TLE for the given constraints.

2) OPTIMIZATION

use Dijkstra's algorithm with a min priority queue. Initially distance of city 1 is 0 and all other distances are infinity. Take the node with the minimum distance, and update the distances of its neighbours whenever a shorter path is found.

TIME COMPLEXITY -> O((V+E) log V)

SPACE COMPLEXITY -> O(V+E)

QUESTION 6 -> ROAD REPARATION

WHAT I THOUGHT ?

We need to connect all the cities with minimum total cost. This is a minimum spanning tree problem.

1) BRUTE FORCE

we could try different combinations of roads and check which combination connects all cities with minimum cost, but the number of combinations is very large and this would give TLE.

2) OPTIMIZATION

use Prim's algorithm with a min priority queue. Start from one city, repeatedly choose the minimum cost road that connects a visited city to an unvisited city, and add that cost to the answer. If all cities cannot be visited, the graph is disconnected and the answer is IMPOSSIBLE.

TIME COMPLEXITY -> O(E log E)

SPACE COMPLEXITY -> O(V+E)

QUESTION 7 -> EDIT DISTANCE

WHAT I THOUGHT ?

We need to convert one string into another using insertions, deletions and replacements, while minimizing the number of operations.

BRUTE FORCE -> recursively try all three operations (insert, delete and replace) and choose the minimum number of operations. If the current characters are equal, move to the next characters in both strings. Otherwise, try all three operations and take the minimum result. This creates many repeated subproblems and has exponential time complexity, so it would give TLE. The recursion can take O(N+M) stack space in the worst case.

OPTIMIZATION -> as currently completing dp i havent attempted the optimization for it

QUESTION 8 -> DYNAMIC RANGE SUM QUERIES

WHAT I THOUGHT ?

We need to answer sum queries on a range and also update the value at a particular index.

BRUTE FORCE -> for every sum query, traverse the whole range and calculate its sum. Each query can take O(N) time, and with many queries this would give TLE.

as i havent studied fenwick tree yet i havent attempted the optimization
