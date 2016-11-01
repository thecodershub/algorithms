#Simply check if a substring is found in the string
def substr(subst,st):
    sbLength = len(subst)
    sLength = len(st)
    for i in range(0, sLength-sbLength+1):
        if st[i:i+sbLength] == subst:
            return true;
            
def main():
    st = "blahblblah"
    assert substr("blah",st)
    assert substr("ab",st)
    assert substr(" bl",st)

if __name__ == '__main__':
    main()
