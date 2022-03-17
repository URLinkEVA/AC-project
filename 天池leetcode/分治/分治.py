# 伪代码
# MERGE_SORT(A,p,r)
# if p < r
#     q = [(p+r)/2]
#     MERGE_SORT(A,p,r)
#     MERGE_SORT(A,q+1,r)
#     MERGE(A,p,q,r)
