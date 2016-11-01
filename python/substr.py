"""
Simply check if a substring is found in the string
subst - substring
st    - string
"""
def substr(subst,st):
    #Get length of substring
    sbLength = len(subst)
    #Get length of string
    sLength = len(st)
    #Scroll through string
    for i in range(0, sLength-sbLength+1):
        #If current window matches with substring
        if st[i:i+sbLength] == subst:
            return true;
            
def main():
    st = "blahblblah"
    assert substr("blah",st)
    assert substr("ab",st)
    assert substr(" bl",st)

if __name__ == '__main__':
    main()
