class bit
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
void replacebits(int &n,int &m,int i,int j)
{
    clearrangeitoj(n,i,j);
    n=n|(m<<i);
}
int countsetbits(int n)
{   int ans=0;
    while(n>0)
    {
        if(n&1==1)
            ans++;
        n>>1;
    }
    return ans;
}
int countsetbitsfast(int n)
{
    int ans=0;
    while(n>0)
    {
        n=n&(n-1); //removes last set bit from the right.
        ans++;
    }
    return ans;
}
int countsetbitsfastest(int n)
{
    return __builtin_popcount(n);
}
};
























