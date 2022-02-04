# Purpose: The purpose of this function is to find numbers in a vector based on an expression with respect to a value.

# Example:
#  In matlab the expression is "newvec = find(vec > 3)"
# vec = [2,2,5,6,7,6,5,4,3,5,1]
# expression = '>'
# val = 3
# [newvec, ind_newvec] = findall(vec, expression, val)

# print newvec
# print ind_newvec

# RETURNS
# [5, 6, 7, 6, 5, 4, 5]
# [2, 3, 4, 5, 6, 7, 9]


def findall(vec, expression, val):
    newvec = []
    ind_newvec = []
    
    if expression == '==':
        for i in range(len(vec)):
            if vec[i] == val:
                newvec.append(vec[i])
                ind_newvec.append(i)
    elif expression == '!=':
        for i in range(len(vec)):
            if vec[i] != val:
                newvec.append(vec[i])
                ind_newvec.append(i)
    elif expression == '>=':
        for i in range(len(vec)):
            if vec[i] >= val:
                newvec.append(vec[i])
                ind_newvec.append(i)
    elif expression == '<=':
        for i in range(len(vec)):
            if vec[i] <= val:
                newvec.append(vec[i])
                ind_newvec.append(i)
    elif expression == '>':
        for i in range(len(vec)):
            if vec[i] > val:
                newvec.append(vec[i])
                ind_newvec.append(i)
    elif expression == '<':
        for i in range(len(vec)):
            if vec[i] < val:
                newvec.append(vec[i])
                ind_newvec.append(i)
    
    ind_newvec = [int(x) for x in ind_newvec]
    
    return newvec, ind_newvec
