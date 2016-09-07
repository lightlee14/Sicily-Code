#include<stdio.h>

void find(int countA,int countB,int maxA,int maxB)
{
    if (maxA==0 && countB>=maxB) printf("%d\n",maxB);
    else if (maxA==0 && countB<maxB) printf("%d\n",countB);
    else if (maxB==0 && countA>=maxA) printf("%d\n",maxA);
    else if (maxB==0 && countA<maxA) printf("%d\n",countA);
}

int main()
{
    int countA,countB,maxA,maxB,numA,numB;
    
    scanf("%d%d%d%d",&countA,&countB,&maxA,&maxB);
    
    if (maxA*maxB==0) find(countA,countB,maxA,maxB);
    else
    {
        if (countA%maxA!=0) numA=countA/maxA+1;
        else numA=countA/maxA;
        if (countB%maxB!=0) numB=countB/maxB+1;
        else numB=countB/maxB;
        if (numA==numB+1 || numB==numA+1) printf("%d\n",countA+countB);
        else if (numA-1 > countB) printf("%d\n",countB+maxA*(countB+1));
        else if (countA < numB-1) printf("%d\n",countA+maxB*(countA+1));
        else printf("%d\n",countA+countB);
    }

}
//like ABABA ->ABBABBA
