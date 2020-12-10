import random
cnt=1
def password_generator():
    global cnt
    password = 'h5M30Jx89fUkCGmI'
    ### START YOUR CODE HERE ###
    password=password[:cnt]+'A'+password[cnt+1:]
    cnt=(cnt+1)%16

    #### END YOUR CODE HERE ####
    return password
