/*
 * ���� �ִ� ��ǥ(x, y) �� 7���� �ֺ� ��ǥ�� �����ϰ� ����
 * ���� �ִ� ��ǥ�κ��� ������ ��ǥ�� �󸶳� �ָ� ������ �ִ��� �����ϱ�
 * 
 * 0. ��ǥ ǥ���� ������� �ұ�?
 * - ������ �迭 �� ����ü�� ǥ�� �ϴ� ��� 2������ ����(�켱 ����ü�� ǥ���غ���)
 * 
 * 1. ������ǥ ������ ��� �ұ�?
 * - srand(), rand(), time() �Լ� ���
 * 
 * 2. ��ǥ�� �Ÿ� ���ϴ� ����� �Լ��� ���ȭ
 * - squrt(), Pow() �Լ� ���� ��� (math ���̺귯�� �߰�) 
 * 
 * 3. ���� ����� �Ÿ��� �ִ� ���� ȹ���� ������� �ұ�?
 * - ������ �Ÿ� length�� �̹� ���߱� ������ length�� ���� ª�� ���� index�� ���ؼ�
 *   �ش� index�� �ش��ϴ� ��ǥ ����ϱ�
 * - Position_miminumIndex�� ���� ���ȭ �Ϸ��� Length ����� �ش� �Լ� �Ʒ��� ���� �����ϸ� �ɵ�
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define POS_CNT 7

typedef struct Pos
{
    int X;
    int Y;
} Pos;

void Position_Length(double * , const Pos * defaultPos, const Pos *pPos);
void Position_RandomMake(Pos *, int);
int Position_minimumIndex(const double *);

int main()
{
    Pos pos[POS_CNT];
    Pos myPos;  
    int i, index; 
    double length[POS_CNT];

    srand(time(NULL)); //Position_RandomeMake �Լ� ���� ���� ù ����� �Ʒ� �ι����� ������ ���� ����?
    Position_RandomMake((Pos*)&myPos, 1);
    Position_RandomMake((Pos*)pos, POS_CNT);

    Position_Length((double*)length, (Pos*)&myPos, (Pos*)pos);
    
    index = Position_minimumIndex(length);
    printf("(%d , %d)\r\n",pos[index].X, pos[index].Y);
    return 0;
}

void Position_RandomMake(Pos * pPos, const int count)
{
    int i;

    for(i = 0; i < count; i++)
    {
//      pPos[i].X = rand();
//      pPos[i].Y = rand();
        (pPos+i)->X = rand()%10;
        (pPos+i)->Y = rand()%10;
    }
}

void Position_Length(double *pLength, const Pos * defaultPos, const Pos * pPos)
{
    int i;

    for(i = 0; i < POS_CNT; i++)
    {
        pLength[i] = (double) sqrt(pow(pPos[i].X - defaultPos->X, 2) + pow(pPos[i].Y - defaultPos->Y, 2));
        printf("%5.2f\r\n", pLength[i]);
    }
}

int Position_minimumIndex(const double *pLength)
{
    int i;
    int index = 0;
    double min = pLength[index]; 

    for(i = 1; i < POS_CNT; i++)
    {
        if(pLength[i] < min)
        {
           min = pLength[i];
           index = i; 
        }
    }

    return index;
}
