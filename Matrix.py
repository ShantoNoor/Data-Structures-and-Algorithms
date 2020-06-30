# diagonal matrix
# lis = [1, 2, 3, 4, 5]

# for i in range(len(lis)):
# 	for j in range(len(lis)):
# 		if i == j:
# 			print(lis[i], end=' ')
# 		else:
# 			print(0, end=' ')

# 	print()

# lower-triangular matrix
# n = int(input())
# lis = [0]*(n*(n+1)//2)

# def set(arr, nn):
# 	for i in range(nn):
# 		for j in range(nn):
# 			ij = int(input())
# 			if i >= j:
# 				# row major formula -->
# 				# lis[i*(i+1)//2+j] = ij
# 				# colom major formula -->
# 				lis[nn*j-((j*(j-1))//2)+(i-j)] = ij


# def show(arr, nn):
# 	for i in range(nn):
# 		for j in range(nn):
# 			if i >= j:
# 				# row major formula -->
# 				# print(lis[i*(i+1)//2+j], end=' ')
# 				# colom major formula -->
# 				print(lis[nn*j-((j-1)*j)//2+i-j], end=' ')
# 			else:
# 				print(0, end=' ')

# 		print()

# set(lis, n)
# show(lis, n)
# print(lis)

# upper-triangular matrix
# n = int(input())
# lis = [0]*(n*(n+1)//2)

# def set(arr, nn):
# 	for i in range(nn):
# 		for j in range(nn):
# 			ij = int(input())
# 			if i <= j:
# 				# row major formula -->
# 				# lis[nn*i-(i*(i-1))//2+j-i] = ij
# 				# colom major formula -->
# 				lis[i+(j*(j+1))//2] = ij


# def show(arr, nn):
# 	for i in range(nn):
# 		for j in range(nn):
# 			if i <= j:
# 				# row major formula -->
# 				# print(lis[nn*i-(i*(i-1))//2+j-i], end=' ')
# 				# colom major formula -->
# 				print(lis[i+(j*(j+1))//2], end=' ')
# 			else:
# 				print(0, end=' ')

# 		print()

# set(lis, n)
# show(lis, n)
# # print(lis)

### Symmetric Matrix
# n = int(input())
# lis = [0]*((n*(n+1))//2)
# def set(arr, nn):
# 	for i in range(nn):
# 		for j in range(nn):
# 			ij = int(input())
# 			if i >= j:
# 				arr[(i*(i+1))//2+j] = ij

# def show(arr, nn):
# 	for i in range(nn):
# 		for j in range(nn):
# 			if i >= j:
# 				print(arr[(i*(i+1))//2+j], end=' ')
# 			else:
# 				print(arr[(i*(i+1))//2+i], end=' ')
# 		print()

# set(lis, n)
# show(lis, n)
# # print(lis)

### Tri diagonal Matrix

# n = int(input())

# lis = [0]*(3*n-2)

# def set(arr, nn):
# 	for i in range(nn):
# 		for j in range(nn):
# 			ij = int(input())
# 			if j-i==1:
# 				arr[i] = ij
# 			elif i==j:
# 				arr[nn+i-1] = ij
# 			elif i-j==1:
# 				arr[2*nn+i-2] = ij

# def show(arr, nn):
# 	index = 0
# 	for i in range(nn):
# 		for j in range(nn):
# 			if j-i==1:
# 				print(arr[i], end=' ')
# 			elif i==j:
# 				print(arr[nn+i-1], end=' ')
# 			elif i-j==1:
# 				print(arr[2*nn+i-2], end=' ')
# 			else:
# 		 		print(0, end=' ')

# 		print()


# set(lis, n)
# show(lis, n)
# # print(lis)


### Toeplitz Matrix
#----->-----row-----<|>---col---<#
lis = [2, 3, 4, 5, 6, 7, 8, 9, 10]
n = 5

def show(arr, nn):
	for i in range(nn):
		for j in range(nn):
			if i <= j:
				print(arr[j-i], end=' ')
			elif i > j:
				print(arr[nn+i-j-1], end=' ')
		print()

show(lis, n)