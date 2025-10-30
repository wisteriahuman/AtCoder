X, C = map(int, input().split())

# 引き出し額を(1000 * p)円とすると
# 1000 * p + C * p  <= X
# (1000 + C) * p <= X
# p <= X / (1000 + C)
# 整数pの最大ちはX / (1000 * C) の小数点以下を切り捨てた値である
p_max = X // (1000 + C)
ans = p_max * 1000
print(ans)

