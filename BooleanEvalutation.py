mod = 1000000007
def evaluateExp(exp):
    str1,str2 = "",""
    for i in exp:
        if i=='T' or i=='F':
            str1+=i
        else:
            str2+=i
    n = len(str1)
    dpt = [[0]*n for i in range(n)]
    dpf = [[0]*n for i in range(n)]
    
    for gap in range(n):
        for i in range(n-gap):
            j = i + gap
            if gap==0:
                if str1[i]=='T':
                    dpt[i][j] = 1
                else:
                    dpf[i][j] = 1
            else:
                for k in range(i,j):
                    lt = dpt[i][k]
                    lf = dpf[i][k]
                    rt = dpt[k+1][j]
                    rf = dpf[k+1][j]
                    
                    if str2[k]=='&':
                        dpt[i][j] += lt*rt
                        dpf[i][j] += lf*rt + lt*rf + lf*rf
                    elif str2[k]=='|':
                        dpt[i][j] += lt*rf + lf*rt + lt*rt
                        dpf[i][j] += lf*rf
                    else:
                        dpt[i][j] += lt*rf + lf*rt
                        dpf[i][j] += lf*rf + lt*rt
                    dpt[i][j] = dpt[i][j]%mod
                    dpf[i][j] = dpf[i][j]%mod
    return dpt[0][n-1]                   
