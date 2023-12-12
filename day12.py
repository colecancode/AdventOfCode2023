def solve(part):
	ans = 0;
	while line := input():
		info, lengths = line.split()
		arr = [int(l) for l in lengths.split(',')]

		if (part == 2):
			info_cpy = info
			for _ in range(4): info += "?" + info_cpy
			arr_cpy = arr.copy()
			for _ in range(4): arr += arr_cpy
		info += "."

		n, m = len(info), len(arr)
		info = " " + info	# one based
		arr = [0] + arr		# indexing
		dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
		dp[0][0] = 1;
		for i in range(1, n+1):
			for j in range(0, m+1):
				if info[i] != '#':
					dp[i][j] += dp[i-1][j];

				if j > 0 and info[i] != '.' and i+arr[j] <= n and "." not in info[i:i+arr[j]] and info[i+arr[j]] != "#":
					dp[i+arr[j]][j] += dp[i-1][j-1];
		ans += dp[n][m]
	print(ans)

solve(1)
solve(2)