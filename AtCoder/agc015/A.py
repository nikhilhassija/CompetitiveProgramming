N, A, B = map(int, input().split())

minsum = A + B + (N-2)*A
maxsum = A + B + (N-2)*B

print(max(0, maxsum - minsum + 1))