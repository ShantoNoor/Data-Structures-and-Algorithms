def displayMatrix(mat):
	k = 1
	for i in range(1, mat[0][0]+1):
		for j in range(1, mat[1][0]+1):
			if(k < mat[2][0]+1 and i == mat[0][k] and j == mat[1][k]):
				print("%2d" %mat[2][k], end=' ')
				k += 1
			else:
				print("%2d" %0, end=' ')

		print()


matrixA = [
	[4, 1, 2, 2, 3, 4],
	[5, 3, 1, 4, 1, 5],
	[5, 7, 2, 5, 9, 4]
]

matrixB = [
	[4, 1, 2, 2, 3, 3, 4],
	[5, 3, 1, 5, 3, 5, 2],
	[6, 3, 4, 7, 5, 8, 6]
]

matrixC = [
	[4, 1, 2, 2, 3, 3, 4],
	[5, 5, 2, 5, 1, 3, 5],
	[6, 2, 5, 6, 4, 8, 9]
]


def addMatrix(matA, matB):
	if matA[0][0] == matB[0][0] and matA[1][0] == matB[1][0] :
		i, j, k = 1, 1, 0
		matC = []
		matC.append([matA[0][0]])
		matC.append([matA[1][0]])
		matC.append([0])
		while i <= matA[2][0] and j <= matB[2][0]:
			if matA[0][i] == matB[0][j]:
				if matA[1][i] == matB[1][j]:
					matC[0].append(matA[0][i])
					matC[1].append(matA[1][i])
					matC[2].append(matA[2][i]+matB[2][j])
					i += 1
					j += 1
					k += 1

				elif matA[1][i] < matB[1][j]:
					matC[0].append(matA[0][i])
					matC[1].append(matA[1][i])
					matC[2].append(matA[2][i])
					i += 1
					k += 1

				else:
					matC[0].append(matB[0][j])
					matC[1].append(matB[1][j])
					matC[2].append(matB[2][j])
					j += 1
					k += 1

			elif matA[0][i] < matB[0][j]:
				matC[0].append(matA[0][i])
				matC[1].append(matA[1][i])
				matC[2].append(matA[2][i])
				i += 1
				k += 1

			else:
				matC[0].append(matB[0][j])
				matC[1].append(matB[1][j])
				matC[2].append(matB[2][j])
				j += 1
				k += 1

		while i <= matA[2][0]:
			matC[0].append(matA[0][i])
			matC[1].append(matA[1][i])
			matC[2].append(matA[2][i])
			i += 1
			k += 1

		while j <= matB[2][0]:
			matC[0].append(matB[0][j])
			matC[1].append(matB[1][j])
			matC[2].append(matB[2][j])
			j += 1
			k += 1

		matC[2][0] = k

		return matC

	else:
		print("Matrix can't be added")


matrixD = addMatrix(matrixB, matrixC)

def displaySparseMatrix(mat):
	for i in mat:
		print(i)

displayMatrix(matrixB)
print('--------------')
displayMatrix(matrixC)
print('--------------')
displayMatrix(matrixD)

print('------------------------------------')
displaySparseMatrix(matrixD)

