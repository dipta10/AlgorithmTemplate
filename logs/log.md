#### LOG:

**year-month-date**

- **TODO MUST**:
  - Interactive Problems!
  - Articulation Point doc.
  - Vertex covering doc.
  - https://toph.co/p/very-easy-geometry
  - https://www.codechef.com/problems/CHALENGE
  - Take [this one](https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/question-5-34/editorial/) maybe?
  - NumberTheoryAndStuff Remake
  - X-OR properties

* **2019-04-24:**<br>

  - I think I've got the error finally in my articulation point:

    ```cpp
    if (!vis[neighbor]) {
            if (dfsTime[node] <= lowTime[neighbor]) isArticulation = true;
            else lowTime[node] = min(lowTime[node], lowTime[neightbor]);
        } else {
            lowTime[node] = min(lowTime[node], **dfsTime[neighbor]**);
        }
    }
    ```

    - [x] Whatever, need to test it now against the one it failed. And also need to check the book as well.<br>

  - UVA11080 - What was that all about then?

* **2019-03-24:**<br>

  - [UVA11396](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=669) Claw, is/how is it a bipartite graph problem?

* **2019-03-24:**<br>

  - okay! Here I am after almost 3 weeks of immense pressure with all the endless quizzes, finals and projects.
    - [ ] [A perfect Murder](), how long will it take.
    - [ ] One from the group

* **2019-03-24:**<br>

  - Okay! The only reason my solution didn't work back there was because I used fing **`memset()`** ! Are you fing **`serious!! BE SURE WHEN TO AND NOT TO USE MEMSET()`**. I was also using **`C++ (g++ 4.3.2)`** and not **`C++14 (g++ 4.3.2)`** as well. It was another reason as well.

* **2019-03-22:**<br>

  - [ ] - Submit CF 2 problems, 1 from the Programming group solution $\rightarrow$ comment
  - [ ] [Settings Sync](https://github.com/shanalikhan/code-settings-sync)

* **2019-03-22:**<br>

  - I've decided to include others stuff those are not related to programming/algorithm here. Though programming and algorithmic stuff will will have a symbol ($\checkmark, \ltimes$)
  - TODO:<br>
    - [ ] $\xcancel{CF Contest Tonight div2}$
    - [x] MSD Quiz Sunday $\rightarrow$ pdfs
    - [x] MSD Mid Sunday $\rightarrow$ codes
    - [x] ISD Presentation Sunday
    - [ ] $\ltimes$ [Solve Previous VJudge Contest](https://vjudge.net/contest/289594) Solved : 3

* **2019-03-20:**<br>
  I though Mo's Algorithm was gonna be much easier for me :(<br>
  The Individual Algo contest wasn't a good experience. Need to work on<br>

  - Algorithm knowledge
  - Understanding the problem statement quickly.
  - Thinking about every possible implementation.
  - Last Moment GUp

  - [x] $\checkmark$ Euler's path and circuit Doc
  - [ ] $\checkmark$ Fleury's algorithm
  - [x] $\checkmark$ TIRE
  - [ ] $\checkmark$ TIRE Documentation

* **2019-03-19:**<br>
  - [x] $\ltimes$ [find number of ways to split array in 3 equal sum parts](https://codeforces.com/contest/466/problem/C) : why `i < n` and not `i <= n` (`line 13`) ??
  - [x] $\ltimes$[492b - vanya and lanterns](https://codeforces.com/contest/492/submission/51430624) No binary search?

- **2019-03-17:**<br>
  `n-queens`: I know how it works. Still something is not right about it. I still don't know if I'll be able to solve problems similar to this one or derive a solution from this one. Diagonal for `ar[i][j]` is `i+j`, remember there can be at most `row*col - 1` diagonals?<br>
  - [ ] $\ltimes$ [Binary Search Problems](https://www.stopstalk.com/problems/search?name=&orderby=solved-count-desc&page=1&generalized_tags=Binary+Search&generalized_tags=Binary+Search+Tree&generalized_tags=Binary+Tree&include_editorials=on)
  - [ ] $\ltimes$ [Transposing Matrices](https://codeforces.com/contest/1136/problem/C): we can get any permutation of numbers on any diagonal because we can swap neighboring elements on diagonal if we perform transpose operation infinite times. So, we just need to check if the multi-sets of numbers on corresponding diagonals are the same.<br>

* **2019-03-16:**<br>
  `Files: LCA, Diameter of Tree, Centroid Decomposition start`