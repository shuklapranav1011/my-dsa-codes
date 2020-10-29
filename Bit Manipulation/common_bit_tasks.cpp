class bitfunctions
{
public:
    int isOdd(int n)
{
    return n&1;
}
int getBit(int n,int i)
{
    int mask=1<<i;
    return n&mask;
}
void setBit(int &n,int i)
{
    int mask=1<<i;
    n=n|mask;
}
void clearBit(int &n,int i)
{
    int mask=~(1<<i);
    n=n&mask;
}
void clearlast_i_bits(int &n,int i)
{
    int mask=(~0)<<i;
    n=n&mask;
}

void clearrangeitoj(int &n,int i,int j)
{
    //j is in left of i.
    //we are starting from the right.
    int mask1=(-1<<(j+1));
    int mask2=~(-1<<i);// or pow(2,i)-1;
    int mask=mask1|mask2;
    n=n&mask;
}
void updateBit(int &n,int i,int v)
{
    /*
    int mask;
    if(v==0)
    {
        mask=~(1<<i);
        n=n&mask;
    }
    if(v==1)
    {
        mask=(1<<i);
        n=n|mask;
    }
    */
    clearBit(n,i);
    n=n|(v<<i);
}
};
























