# [Gold I] Globulous Gumdrops - 7666 

[문제 링크](https://www.acmicpc.net/problem/7666) 

### 성능 요약

메모리: 10232 KB, 시간: 124 ms

### 분류

다이나믹 프로그래밍, 기하학, 비트마스킹, 비트필드를 이용한 다이나믹 프로그래밍, 외판원 순회 문제

### 제출 일자

2026년 1월 13일 03:41:58

### 문제 설명

<p>Gwen just bought a bag of gumdrops! However, she does not like carrying gumdrops in plastic bags; instead, she wants to pack her gumdrops in a cylindrical tube of diameter d. Given that each of her gumdrops are perfect spheres of radii r<sub>1</sub>,r<sub>2</sub>,... ,r<sub>n</sub>, find the shortest length tube Gwen can use to store her gumdrops.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/7666/1.png" style="height:250px; width:175px"></p>

<p style="text-align: center;">Figure 4: Gumdrops packed into a cylindrical tube.</p>

<p>You should assume that the gumdrop radii are sufficiently large that no three gumdrops can be simultaneously in contact with each other while fitting in the tube. Given this restriction, it may be helpful to realize that the gumdrops will always be packed in such a way that their centers lie on a single two-dimensional plane containing the axis of rotation of the tube.</p>

### 입력 

 <p>The input file will contain multiple test cases. Each test case will consist of two lines. The first line of each test case contains an integer n (1 ≤ n ≤ 15) indicating the number of gumdrops Gloria has, and a floating point value d (2.0 ≤ d ≤ 1000.0) indicating the diameter of the cylindrical tube, separated by a space. The second line of each test case contains a sequence of n space-separated floating point numbers, r<sub>1</sub> r<sub>2</sub> ... r<sub>n</sub> (1.0 ≤ r<sub>i</sub> ≤ d/2) are the radii of the gum drops in Gloria’s bag. A blank line separates input test cases. A single line with the numbers “0 0” marks the end of input; do not process this case.</p>

### 출력 

 <p>For each input test case, print the length of the shortest tube, rounded to the nearest integer.</p>

