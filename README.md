# sorting-algorithm-performance
Programming Assignment: You need to implement insertion sort and merge sort (increasing or decreasing order) algorithms and measure the performance of these two algorithms in terms of number of steps and CPU running time.
For each algorithm, and for each n = 100, 200, 300, 400, 500, 1000, 4000, 10000, measure its running time and number of steps when the input is (1) reversely sorted, i.e. n, n-1, …, 3, 2,1; (2) sorted 1, 2, 3, … n; (3) random permutation of 1, 2, …, n; (4) 50 instances of n random numbers generated in the range of [1..n].

Note:

(1) You may have to repeat the algorithm many times, each time you need to initialize the array.

(2) Your running time should exclude the time for initialization. 

(3) All measurement should be done in a single run, i.e. you do not need to run once for n=100, another time for n=200, etc

 

What to turn in:

(1) Well documented source code in C++

(2) Report the number of steps and the CPU running time in a table,

(3) Plot the running time of the algorithm results

(4) Approximation the constant c in the complexity of insertion sort (cn^2), and merge sort (cnlgn) by inspecting the results

<a href="https://gist.githubusercontent.com/yosephAHMED/1b64610bd5942dd886dced5bd19853a0/raw/8b7fa99ec8ff80e458ce7f77da55db0f12092a00/Insertion_Sort_Performance.svg">
  <img src="https://gist.githubusercontent.com/yosephAHMED/1b64610bd5942dd886dced5bd19853a0/raw/8b7fa99ec8ff80e458ce7f77da55db0f12092a00/Insertion_Sort_Performance.svg">
</a>

<a href="https://gist.githubusercontent.com/yosephAHMED/a027ccf406a2a72c2e07672fb7a28a75/raw/d8df8aeb8229a9fd98df50d0348b74fcfb2162a2/Merge_Sort_Performance.svg">
  <img src="https://gist.githubusercontent.com/yosephAHMED/a027ccf406a2a72c2e07672fb7a28a75/raw/d8df8aeb8229a9fd98df50d0348b74fcfb2162a2/Merge_Sort_Performance.svg">
</a>
