def add_matrices(matrix1, matrix2):
    rows = len(matrix1)
    cols = len(matrix1[0])
    result = []

    for i in range(rows):
        temp = []
        for j in range(cols):
            temp.append(matrix1[i][j] + matrix2[i][j])
        result.append(temp)

    return result

def subtract_matrices(matrix1, matrix2):
    rows = len(matrix1)
    cols = len(matrix1[0])
    result = []

    for i in range(rows):
        temp = []
        for j in range(cols):
            temp.append(matrix1[i][j] - matrix2[i][j])
        result.append(temp)

    return result

def multiply_matrices(matrix1, matrix2):
    rows1 = len(matrix1)
    cols1 = len(matrix1[0])
    rows2 = len(matrix2)
    cols2 = len(matrix2[0])

    if cols1 != rows2:
        return "Matrices cannot be multiplied"

    result = [[0 for _ in range(cols2)] for _ in range(rows1)]

    for i in range(rows1):
        for j in range(cols2):
            for k in range(cols1):
                result[i][j] += matrix1[i][k] * matrix2[k][j]

    return result

def transpose_matrix(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    result = [[0 for _ in range(rows)] for _ in range(cols)]

    for i in range(rows):
        for j in range(cols):
            result[j][i] = matrix[i][j]

    return result

def display_matrix(matrix):
    for row in matrix:
        print(row)

def input_matrix():
    rows = int(input("Enter number of rows: "))
    cols = int(input("Enter number of columns: "))
    matrix = []

    print("Enter matrix elements:")
    for i in range(rows):
        row = []
        for j in range(cols):
            element = int(input(f"Enter element at position ({i+1},{j+1}): "))
            row.append(element)
        matrix.append(row)

    return matrix

while True:
    print("\nMatrix Operations Menu:")
    print("1. Addition of matrices")
    print("2. Subtraction of matrices")
    print("3. Multiplication of matrices")
    print("4. Transpose of a matrix")
    print("5. Exit")

    choice = int(input("Enter your choice (1-5): "))

    if choice == 1:
        print("\nEnter Matrix A:")
        matrix_A = input_matrix()
        print("\nEnter Matrix B:")
        matrix_B = input_matrix()

        result_addition = add_matrices(matrix_A, matrix_B)
        print("\nResultant Matrix (Addition):")
        display_matrix(result_addition)

    elif choice == 2:
        print("\nEnter Matrix A:")
        matrix_A = input_matrix()
        print("\nEnter Matrix B:")
        matrix_B = input_matrix()

        result_subtraction = subtract_matrices(matrix_A, matrix_B)
        print("\nResultant Matrix (Subtraction):")
        display_matrix(result_subtraction)

    elif choice == 3:
        print("\nEnter Matrix A:")
        matrix_A = input_matrix()
        print("\nEnter Matrix B:")
        matrix_B = input_matrix()

        result_multiplication = multiply_matrices(matrix_A, matrix_B)
        print("\nResultant Matrix (Multiplication):")
        display_matrix(result_multiplication)

    elif choice == 4:
        print("\nEnter Matrix A:")
        matrix_A = input_matrix()

        result_transpose_A = transpose_matrix(matrix_A)
        print("\nResultant Matrix (Transpose of Matrix A):")
        display_matrix(result_transpose_A)

    elif choice == 5:
        break

    else:
        print("Invalid choice! Please enter a valid option.")
