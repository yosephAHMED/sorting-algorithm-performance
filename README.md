# sorting-algorithm-performance
## Programming Assignment: You need to implement insertion sort and merge sort (increasing or decreasing order) algorithms and measure the performance of these two algorithms in terms of number of steps and CPU running time.

For each algorithm, and for each n = 100, 200, 300, 400, 500, 1000, 4000, 10000, measure its running time and number of steps when the input is (1) reversely sorted, i.e. n, n-1, …, 3, 2,1; (2) sorted 1, 2, 3, … n; (3) random permutation of 1, 2, …, n; (4) 50 instances of n random numbers generated in the range of [1..n].

## Note:

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

## Raw Results:
### https://raw.githubusercontent.com/yosephAHMED/sorting-algorithm-performance/master/sorting-algorithm-performance/results.txt

## Analysis:
<a href="https://gist.githubusercontent.com/yosephAHMED/57e21327b739594cc26b36dc77a39d89/raw/3853f43d1d0763bb953ee860c7ac1af750771015/Insertion_Sort_C_Approximation.svg">
  <img src="https://gist.githubusercontent.com/yosephAHMED/57e21327b739594cc26b36dc77a39d89/raw/3853f43d1d0763bb953ee860c7ac1af750771015/Insertion_Sort_C_Approximation.svg">
</a>

### Average C approximations for Insertion Sort
| Input Size | Reversely Sorted | Sorted | Random Permutation | 50 Instances of Random Input |
| --- | --- | --- | --- | --- |
| `100` | 3.5551 | 0.0298 | 1.8197 | 1.739 |
| `200` | 3.49745 | 0.01495 | 1.55285 | 1.75162 |
| `300` | 3.49831 | 0.00997778 | 1.57961 | 1.75683 |
| `400` | 3.49874 | 0.0074875 | 1.72936 | 1.74756 |
| `500` | 3.49899 | 0.005992 | 1.72598 | 1.75616 |
| `1000` | 3.4995 | 0.002998 | 1.72187 | 1.74925 |
| `4000` | 3.49987 | 0.000749875 | 1.7119 | 1.74857 |
| `10000` | 3.49995 | 0.00029998 | 1.74479 | 1.7511 |
| --- | --- | --- | --- | --- |
| **Average** | 3.50598875 | 0.009031891875 | 1.6982575 | 1.75001125 |

<a href="https://gist.githubusercontent.com/yosephAHMED/4241617bb803a9d3d39a6260b95b8558/raw/21a6b219a1b2ed4cca90af7816bb6cf3d3be6a6a/Merge_Sort_C_Approximation.svg">
  <img src="https://gist.githubusercontent.com/yosephAHMED/4241617bb803a9d3d39a6260b95b8558/raw/21a6b219a1b2ed4cca90af7816bb6cf3d3be6a6a/Merge_Sort_C_Approximation.svg">
</a>

### Average C approximations for Merge Sort
| Input Size | Reversely Sorted | Sorted | Random Permutation | 50 Instances of Random Input |
| --- | --- | --- | --- | --- |
| `100` | 9.10281 | 9.10281 | 11.6195 | 11.6717 |
| `200` | 8.682 | 8.682 | 11.3781 | 11.3772 |
| `300` | 8.46222 | 8.46222 | 11.2124 | 11.2493 |
| `400` | 8.35188 | 8.35188 | 11.1746 | 11.1467 |
| `500` | 8.31074 | 8.31074 | 11.0385 | 11.0437 |
| `1000` | 8.05819 | 8.05819 | 10.8798 | 10.8785 |
| `4000` | 7.67731 | 7.67731 | 10.6339 | 10.6295 |
| `10000` | 7.44433 | 7.44433 | 10.5372 | 10.5352 |
| --- | --- | --- | --- | --- |
| **Average** | 8.261185 | 8.261185 | 11.05925 | 11.066475 |

## Conclusion:
For sorted inputs, it appears that insertion sort is faster than merge sort across all input size (n). Furthermore, for smaller input size (n), it appears that insertion sort has a faster runtime performance, however when the input size (n) is large, merge sort is the superior sorting algorithm in runtime performance. This is clearly the case for input sizes of 1000 and onward.
