# [Bronze I] Another Brick in the Wall - 32916 

[문제 링크](https://www.acmicpc.net/problem/32916) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 사칙연산, 홀짝성

### 제출 일자

2026년 1월 3일 23:58:32

### 문제 설명

<p>Alice likes building toy walls. She has a lot of $1 \times 2$ bricks and a limited supply of $1 \times 3$ bricks. Both types of bricks have a height of 1 and can not be rotated.</p>

<p>Alice is going to build a one unit thick wall of length $l$ and height $h$ out of these bricks. A wall is <em>solid</em> if there are no seams directly above another seam.</p>

<table class="table table-bordered td-center td-middle">
	<tbody>
		<tr>
			<td><img alt="" src="https://upload.acmicpc.net/8806eeb4-b59f-4c3f-9eb6-e3c6a5370de0/-/preview/" style="width: 141px; height: 47px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/11a5e90c-735b-4ac1-b48b-36beff89c748/-/preview/" style="width: 140px; height: 66px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/dfe78474-d512-4eee-8fe4-d54bd1711567/-/preview/" style="width: 141px; height: 85px;"></td>
		</tr>
		<tr>
			<td>Good seam placement</td>
			<td>Bad seam placement</td>
			<td>Solid $7 \times 4$ wall</td>
		</tr>
	</tbody>
</table>

<p>Help Alice determine the minimum number of $1 \times 3$ bricks required to build a solid wall of length $l$ and height $h$.</p>

### 입력 

 <p>The only line contains two integers $l$ and $h$, denoting the length and the height of the wall ($5 \le l \le 1000$; $2 \le h \le 1000$).</p>

### 출력 

 <p>Print the minimum number of $1 \times 3$ bricks required to build a solid $l \times h$ wall.</p>

<p>It can be shown that it is always possible to build a solid wall of length $l$ and height $h$.</p>

